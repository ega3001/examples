import java.util.*;

//Класс - решатель, использует алгоритм А* для более быстрого поиска
public class MyPuzzleResolver implements PuzzleResolver {
    public int[] resolve(int[] arr){
        Puzzle pz = new Puzzle(arr);
        PriorityQueue<MyTree> open = new PriorityQueue<MyTree>(new Comparator<MyTree>() {
            @Override
            public int compare(MyTree o1, MyTree o2) {
                return o1.getF() - o2.getF();
            }
        });
        HashMap<String, MyTree> close = new HashMap<>();
        open.add(new MyTree(pz, null));
        MyTree mt  = open.poll();
        close.put(mt.getInnerPuzzle().getUniqName(), mt);
        while(!mt.getInnerPuzzle().isGoal()){
            for(Puzzle item : mt.getInnerPuzzle().getChilds()){
                if(!close.containsKey(item.getUniqName()))
                    open.add(new MyTree(item, mt));
            }
            mt = open.poll();
            close.put(mt.getInnerPuzzle().getUniqName(), mt);
        }
        List<Integer> trace = mt.getTrace();
        int[] arrTrace = new int[trace.size()];
        for(int i = 0; i<arrTrace.length; i++)
            arrTrace[i] = trace.get(trace.size() - i - 1);
        return arrTrace;
    }
}
