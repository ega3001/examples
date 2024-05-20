#include <numbers.hpp>

 
case_map ZeroConstructor::init(){
    case_map cases_map = {
        {L'И', L"ноль"},
        {L'Р', L"ноля"},
        {L'Д', L"нолю"},
        {L'В', L"ноль"},
        {L'Т', L"нолём"},
        {L'П', L"ноле"},
    };
    return cases_map;
}


case_gender_map OneConstructor::init(){
    case_gender_map cases_map = {
        {L'М', {
                {L'И', L"один"},
                {L'Р', L"одного"},
                {L'Д', L"одному"},
                {L'В', L"один"},
                {L'Т', L"одним"},
                {L'П', L"одном"},
            }
        },
        {L'Ж', {
                {L'И', L"одна"},
                {L'Р', L"одной"},
                {L'Д', L"одной"},
                {L'В', L"одну"},
                {L'Т', L"одной"},
                {L'П', L"одной"},
            }
        },
        {L'С', {
                {L'И', L"одно"},
                {L'Р', L"одного"},
                {L'Д', L"одному"},
                {L'В', L"одно"},
                {L'Т', L"одним"},
                {L'П', L"одном"},
            }
        },
    };
    return cases_map;
}


case_gender_map TwoConstructor::init(){
    case_gender_map cases_map = {
        {L'М', {
                {L'И', L"два"},
                {L'Р', L"двух"},
                {L'Д', L"двум"},
                {L'В', L"два"},
                {L'Т', L"двумя"},
                {L'П', L"двух"},
            }
        },
        {L'Ж', {
                {L'И', L"две"},
                {L'Р', L"двух"},
                {L'Д', L"двум"},
                {L'В', L"две"},
                {L'Т', L"двумя"},
                {L'П', L"двух"},
            }
        },
        {L'С', {
                {L'И', L"два"},
                {L'Р', L"двух"},
                {L'Д', L"двум"},
                {L'В', L"два"},
                {L'Т', L"двумя"},
                {L'П', L"двух"},
            }
        },
    };
    return cases_map;
}


case_map ThreeConstructor::init(){
    case_map cases_map = {
        {L'И', L"три"},
        {L'Р', L"трёх"},
        {L'Д', L"трём"},
        {L'В', L"три"},
        {L'Т', L"тремя"},
        {L'П', L"трёх"},
    };
    return cases_map;
}


case_map FourConstructor::init(){
    case_map cases_map = {
        {L'И', L"четыре"},
        {L'Р', L"четырёх"},
        {L'Д', L"четырём"},
        {L'В', L"четыре"},
        {L'Т', L"четырьмя"},
        {L'П', L"четырёх"},
    };
    return cases_map;
}


case_map EightConstructor::init(){
    case_map cases_map = {
        {L'И', L"восем"},
        {L'Р', L"восьм"},
        {L'Д', L"восьм"},
        {L'В', L"восем"},
        {L'Т', L"восьм"},
        {L'П', L"восьм"},
    };
    return cases_map;
}


case_map FiveToTwentyAndThirtyEndConstructor::init(){
    case_map cases_map = {
        {L'И', L"ь"},
        {L'Р', L"и"},
        {L'Д', L"и"},
        {L'В', L"ь"},
        {L'Т', L"ью"},
        {L'П', L"и"},
    };
    return cases_map;
}


case_map FourtyConstructor::init(){
    case_map cases_map = {
        {L'И', L"сорок"},
        {L'Р', L"сорока"},
        {L'Д', L"сорока"},
        {L'В', L"сорок"},
        {L'Т', L"сорока"},
        {L'П', L"сорока"},
    };
    return cases_map;
}


case_map HundredConstructor::init(){
    case_map cases_map = {
        {L'И', L"сто"},
        {L'Р', L"ста"},
        {L'Д', L"ста"},
        {L'В', L"сто"},
        {L'Т', L"ста"},
        {L'П', L"ста"},
    };
    return cases_map;
}


case_map FiftyToEightyEndConstructor::init(){
    case_map cases_map = {
        {L'И', L""},
        {L'Р', L"и"},
        {L'Д', L"и"},
        {L'В', L""},
        {L'Т', L"ью"},
        {L'П', L"и"},
    };
    return cases_map;
}


case_gender_map HundredsEndConstructor::init(){
    case_gender_map cases_map = {
        {L'2', {
                {L'И', L"сти"},
                {L'Р', L"сот"},
                {L'Д', L"стам"},
                {L'В', L"сти"},
                {L'Т', L"стами"},
                {L'П', L"стах"},
            }
        },
        {L'3', {
                {L'И', L"ста"},
                {L'Р', L"сот"},
                {L'Д', L"стам"},
                {L'В', L"ста"},
                {L'Т', L"стами"},
                {L'П', L"стах"},
            }
        },
        {L'5', {
                {L'И', L"сот"},
                {L'Р', L"сот"},
                {L'Д', L"стам"},
                {L'В', L"сот"},
                {L'Т', L"стами"},
                {L'П', L"стах"},
            }
        },
    };
    return cases_map;
}


case_gender_map ThousandConstructor::init(){
    case_gender_map cases_map = {
        {L'1', {
                {L'И', L"тысяча"},
                {L'Р', L"тысячи"},
                {L'Д', L"тысяче"},
                {L'В', L"тысячу"},
                {L'Т', L"тысячей"},
                {L'П', L"тысяче"},
            }
        },
        {L'2', {
                {L'И', L"тысячи"},
                {L'Р', L"тысяч"},
                {L'Д', L"тысячам"},
                {L'В', L"тысячи"},
                {L'Т', L"тысячами"},
                {L'П', L"тысячах"},
            }
        },
        {L'5', {
                {L'И', L"тысяч"},
                {L'Р', L"тысяч"},
                {L'Д', L"тысячам"},
                {L'В', L"тысяч"},
                {L'Т', L"тысячами"},
                {L'П', L"тысячах"},
            }
        }
    };
    return cases_map;
}


case_gender_map MillionConstructor::init(){
    case_gender_map cases_map = {
        {L'1', {
                {L'И', L"миллион"},
                {L'Р', L"миллиона"},
                {L'Д', L"миллиону"},
                {L'В', L"миллион"},
                {L'Т', L"миллионом"},
                {L'П', L"миллионе"},
            }
        },
        {L'2', {
                {L'И', L"миллиона"},
                {L'Р', L"миллионов"},
                {L'Д', L"миллионам"},
                {L'В', L"миллиона"},
                {L'Т', L"миллионами"},
                {L'П', L"миллионах"},
            }
        },
        {L'5', {
                {L'И', L"миллионов"},
                {L'Р', L"миллионов"},
                {L'Д', L"миллионам"},
                {L'В', L"миллионов"},
                {L'Т', L"миллионами"},
                {L'П', L"миллионах"},
            }
        }
    };
    return cases_map;
}


case_gender_map BillionConstructor::init(){
    case_gender_map cases_map = {
        {L'1', {
                {L'И', L"миллиард"},
                {L'Р', L"миллиарда"},
                {L'Д', L"миллиарду"},
                {L'В', L"миллиард"},
                {L'Т', L"миллиардом"},
                {L'П', L"миллиарде"},
            }
        },
        {L'2', {
                {L'И', L"миллиарда"},
                {L'Р', L"миллиардов"},
                {L'Д', L"миллиардам"},
                {L'В', L"миллиарда"},
                {L'Т', L"миллиардами"},
                {L'П', L"миллиардах"},
            }
        },
        {L'5', {
                {L'И', L"миллиардов"},
                {L'Р', L"миллиардов"},
                {L'Д', L"миллиардам"},
                {L'В', L"миллиардов"},
                {L'Т', L"миллиардами"},
                {L'П', L"миллиардах"},
            }
        }
    };
    return cases_map;
}
