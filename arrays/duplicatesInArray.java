import java.util.*;


class duplicatesInArray {
    public static void main(String[] args) {
        int[] input = {1,3,2,1,6,7,1,2};
        Map<Integer, Integer> map = new HashMap<>();

        for(int i: input) {
            if(map.containsKey(i)) {
                map.put(i,map.get(i) +1);
            }
            else {
                map.put(i, 1);
            }
        }
        System.out.print("Duplicates: ");
        for(Map.Entry<Integer, Integer> iterate:map.entrySet()) {
            if(iterate.getValue() > 1) {
                System.out.print(iterate.getKey() + " ");
            }
        }
    }
}
