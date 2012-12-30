import java.util.*;

class SumToZero {

    class Node {
        Node next;
        int data;
    }

    public static void printSumToZero(int []d) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i = 0; i < d.length; i++) {
            if(map.get(d[i]) != null) {
                int value = map.get(d[i]) + 1;
                map.put(d[i], value);
            } else
                map.put(d[i], 1);
        }
        for(int i = 0; i < d.length; i++) {
            for(int j = i + 1; j < d.length; j++) {
                int v = 0 - d[i] - d[j];
                int num = 0;
                num += (d[i] == v ? 1 : 0);
                num += (d[j] == v ? 1 : 0);
                if(map.get(v) != null && map.get(v) > num)
                    System.out.println(d[i] + ":" + d[j] + ":" + v);
            }
        }
    }

    public static void main(String[] args) {
        int[] d = {1, 1, 2, 4, 5, 6, -6, -7, 0};
        printSumToZero(d);
    }
    
}
