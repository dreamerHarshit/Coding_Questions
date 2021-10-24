import java.util.*;


class CountOccuranceUsingRec {


    public static int count7(int n) {
        int counter = 0;
        System.out.println("n:" + n );

        if( n % 10 == 7) counter++;

        if( n / 10  == 0)  return counter;

        System.out.println("counter:" + counter );
        return counter + count7(n/10);
    }


    public static void main(String[] args) {
        int n = 71777;
        System.out.println("7 is " + count7(n) + " times in " + n);
    }
}
