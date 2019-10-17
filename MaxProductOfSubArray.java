public class MaxProductOfSubArray
{
    public static int max(int a, int b, int c)
    {
        if (a >= b && a >= c)
        {
            return a;
        }
        else if (b >= a && b >= c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }

    public static int min(int a, int b, int c)
    {
        if (a <= b && a <= c)
        {
            return a;
        }
        else if (b <= a && b <= c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }

    public static void main(String[] args)
    {
        int[] arr =
        { -2, -1, 1, 2, 0, 3, 5, 2 };
        int c_max = arr[0];
        int c_min = arr[0];
        int p_max = arr[0];
        int p_min = arr[0];
        int ans = arr[0];
        for (int i = 1; i < arr.length; i++)
        {
            c_max = max(p_max * arr[i], p_min * arr[i], arr[i]);
            c_min = min(p_max * arr[i], p_min * arr[i], arr[i]);
            ans = Math.max(ans, c_max);
            p_max = c_max;
            p_min = c_min;
        }
        System.out.println(ans);
    }
}

