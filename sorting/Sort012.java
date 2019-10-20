import java.util.Arrays;

public class Sort012
{
    public static void main(String[] args)
    {
        int[] arr =
        { 2, 1, 0, 1, 1, 2, 2, 2, 1, 0, 0, 0, 0, 1 };
        int lo = 0, mid = 0, hi = arr.length - 1, temp = 0;
        while (mid <= hi)
        {
            if (arr[mid] == 0)
            {
                temp = arr[mid];
                arr[mid] = arr[lo];
                arr[lo] = temp;
                lo++;
                mid++;
                System.out.println(Arrays.toString(arr));
            }
            else if (arr[mid] == 1)
            {
                mid++;
                System.out.println(Arrays.toString(arr));
            }
            else
            {
                temp = arr[mid];
                arr[mid] = arr[hi];
                arr[hi] = temp;
                hi--;
                System.out.println(Arrays.toString(arr));
            }
        }
        System.out.println(Arrays.toString(arr));
    }
}

