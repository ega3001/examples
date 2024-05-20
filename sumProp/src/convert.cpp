#include <convert.hpp>
#include <rules.hpp>
#include <parts.hpp>


std::wstring sumProp(uint64_t nSum, std::wstring sGender, std::wstring sCase){
    Rules r{};
    const wchar_t c = sCase.c_str()[0];
    const wchar_t g = sGender.c_str()[0];

    if (nSum == 0)
        return r.convert_zero(c, g);
    
    Parted result{};
    short rank = 0;
    
    do{
        Parted sPart{};
        short rank_part = nSum % 1000;
        short last_part = 0; 
        
        short cur_part = (rank_part / 100) * 100;
        if (r.check_num(cur_part)){
            sPart += r.convert_num(cur_part, c, g);
            last_part = cur_part;
        }
        
        cur_part = rank_part % 100;
        if (r.check_num(cur_part)){
            sPart += r.convert_num(cur_part, c, g);
            last_part = cur_part;
        }else{
            cur_part = (rank_part % 100 / 10) * 10;
            if (r.check_num(cur_part)){
                sPart += r.convert_num(cur_part, c, g);
                last_part = cur_part;
            }
            cur_part = rank_part % 10;
            if (r.check_num(cur_part)){
                sPart += r.convert_num(cur_part, c, g);
                last_part = cur_part;
            }
        }
        
        if (!sPart.is_empty())
            switch(rank){
                case 1: sPart += r.convert_rank(last_part, 't', c); break;
                case 2: sPart += r.convert_rank(last_part, 'm', c); break;
                case 3: sPart += r.convert_rank(last_part, 'b', c); break;
            }
        
        result = sPart + result;
        
        ++rank;
        nSum /= 1000;
        
        if (nSum == 0)
            break;
    }while(true);

    return result.to_str();
}