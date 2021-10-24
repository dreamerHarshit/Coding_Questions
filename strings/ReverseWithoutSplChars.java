class ReverseWithoutSplChars
{
    public static void reverse(char str[])
    {
        int right = str.length - 1, left = 0;

        while (left < right)
        {
            if (!Character.isAlphabetic(str[left]))
                left++;
            else if(!Character.isAlphabetic(str[right]))
                right--;
            else
            {
                char tmp = str[left];
                str[left] = str[right];
                str[right] = tmp;
                left++;
                right--;
            }
        }
    }

    public static void main(String[] args)
    {
        String str = "h?ell!o w#orl&d";
        char[] charArray = str.toCharArray();

        System.out.println("Input string: " + str);
        reverse(charArray);
        String revStr = new String(charArray);

        System.out.println("Output string: " + revStr);
    }
}

