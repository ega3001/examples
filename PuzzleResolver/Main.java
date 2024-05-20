import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        long time = System.currentTimeMillis();
        MyPuzzleResolver mpr = new MyPuzzleResolver();
        System.out.println(Arrays.toString(mpr.resolve(new int[]{3,1,4,5,2,6,7,0})));
        System.out.println(Arrays.toString(mpr.resolve(new int[]{1,2,3,4,0,5,6,7})));
        System.out.println(Arrays.toString(mpr.resolve(new int[]{2,1,3,4,0,5,6,7})));
        System.out.println(Arrays.toString(mpr.resolve(new int[]{7,6,5,4,3,2,1,0})));
        System.out.println(System.currentTimeMillis() - time);
    }
}
