import java.util.ArrayList;
import java.util.List;

public class MyTree {
    private MyTree prev;        //Предыдущее состояние
    private Puzzle innerPuzzle; //Текущее состояние
    private int f;              //Сумма diff и длинны цепочки
    MyTree(Puzzle pz, MyTree prev){
        this.innerPuzzle = pz;
        this.prev = prev;
        this.f = this.innerPuzzle.getDiff();
        if(prev != null)
            this.f += prev.f - prev.innerPuzzle.getDiff() + 1;
    }
    int getF(){ return this.f; }
    public Puzzle getInnerPuzzle(){
        return this.innerPuzzle;
    }
    //Получить путь "нажатия" ячеек
    public List<Integer> getTrace(){
        MyTree mt = this;
        List<Integer> trace = new ArrayList<>();
        while(mt.getInnerPuzzle().getPrevPress() != -1){
            trace.add(mt.innerPuzzle.getPrevPress());
            mt = mt.prev;
        }
        return trace;
    }
}
