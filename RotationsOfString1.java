public class RotationsOfString
{
    public static void main(String[] args)
    {
        String s1 = "Rotate_String";
        int count = 0;
        for (int i = 0; i < s1.length(); i++)
        {
            StringBuffer sb = new StringBuffer();
            for (int j = i + 1; j < s1.length(); j++)
            {
                sb.append(s1.charAt(j));
            }
            count++;
            for (int k = 0; k < count; k++)
            {
                sb.append(s1.charAt(k));
            }
            System.out.print(sb);
            System.out.println();
        }
    }
}

