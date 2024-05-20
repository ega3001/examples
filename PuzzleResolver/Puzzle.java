import java.util.*;

//Класс - пазл
public class Puzzle {
    private int[] arr;                                              //Массив с пазлом
    static private int[][] graph = new int[][]{{0,1,1,0,0,0,0,0},   //Граф смежности
            {1,0,1,1,0,0,0,0},
            {1,1,0,0,0,1,0,0},
            {0,1,0,0,1,0,1,0},
            {0,0,0,1,0,1,0,0},
            {0,0,1,0,1,0,0,1},
            {0,0,0,1,0,0,0,1},
            {0,0,0,0,0,1,1,0}};
    private int prevPress;                                          //Последняя "нажатая" ячейка
    private int diff;                                               //Эвристическая оценка, для А*
    Puzzle(int[] arr){
        this.arr = arr;
        this.prevPress = -1;
        this.diff = calcDiff();
    }
    //Конструктор копирования
     private Puzzle(Puzzle pz){
        this.arr = pz.arr.clone();
        this.diff = calcDiff();
        this.prevPress = pz.prevPress;
    }
    //Подсчет эвристичской оценки
    private int calcDiff(){
        int sum = 0;
        for(int i = 0; i<arr.length; i++){
            sum += calcDistFromTo(truePositionIndex(arr[i]), i);
        }
        return sum;
    }
    //Поиск расстояния от одной точки до другой, использует поиск в ширину
    private int calcDistFromTo(int from, int to){
        List<Integer> outerList = new ArrayList<>();
        boolean[] isVisited = new boolean[arr.length];
        isVisited[from] = true;
        outerList.add(from);
        int iter = 0;
        while(outerList.size() > 0){
            List<Integer> list = new ArrayList<>();
            for(int cur: outerList) {
                if (cur == to) return iter;
                for (int i = 0; i < graph[cur].length; i++) {
                    if (graph[cur][i] == 1 && !isVisited[i]) {
                        isVisited[i] = true;
                        list.add(i);
                    }
                }
            }
            outerList = list;
            iter++;
        }
        return Integer.MAX_VALUE;
    }
    //Получить терминальный индекс для значения ячейки
    private int truePositionIndex(int num){
        switch (num){
            case 0: return 4;
            case 1: return 0;
            case 2: return 1;
            case 3: return 2;
            case 4: return 3;
            case 5: return 5;
            case 6: return 6;
            case 7: return 7;
        }
        return Integer.MAX_VALUE;
    }
    //"Нажатие" по ячейке
    private void boob(int index){
        if(arr[index] != 0){
            for(int i = 0; i<graph[index].length; i++){
                if(graph[index][i] == 1 && arr[i] == 0){
                    this.prevPress = arr[index];
                    int buf = arr[i];
                    arr[i] = arr[index];
                    arr[index] = buf;
                    this.diff = calcDiff();
                    break;
                }
            }
        }
    }
    //Получить все возможные будущие состояния текущей головоломки
    public List<Puzzle> getChilds(){
        List<Puzzle> childs = new ArrayList<>();
        for(int i = 0; i<arr.length; i++){
            if(arr[i] == 0){
                for(int j = 0; j<graph[i].length; j++){
                    if(graph[i][j] == 1){
                        Puzzle pz = new Puzzle(this);
                        pz.boob(j);
                        childs.add(pz);
                    }
                }
                break;
            }
        }
        return childs;
    }
    //Получить уникальное имя для текущего состояния пазла, для HashMap
    public String getUniqName(){
        return Arrays.toString(this.arr);
    }
    public int getDiff(){
        return this.diff;
    }
    public int getPrevPress(){
        return this.prevPress;
    }
    //Если true - головоломка решена
    public boolean isGoal(){
        return this.diff == 0;
    }
}
