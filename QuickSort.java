public class Main
{
	public static void main(String[] args) {
	//	System.out.println("Hello World");
		int arr[] = {3,1,6,2,8,4,99,76,59,93, -2};
		int l=0;
		int h = arr.length-1;
		quicksort(arr,l,h);
		for(int i=l;i<=h;i++)
		{
		    System.out.print(arr[i] + " ");
		}
		
	}
	static void quicksort(int arr[],int l,int h)
	{
	    
	    if(l < h)
	    {
	      int pivot = partition(arr,l,h);
	       quicksort(arr,l,pivot-1);
	       quicksort(arr,pivot+1,h);
	    }
	    
	}
	static int partition(int arr[],int l,int h)
	{
	    int pi = arr[h];
	    int i=l-1;
	    //int j =l-1;
	    for(int j=l;j<=h-1;j++)
	    {
	        if(arr[j] <pi)
	        {
	            i++;
	            int temp=arr[j];
	            arr[j] = arr[i];
	            arr[i] = temp;
	        }
	    }
	    int temp=arr[i+1];
	    arr[i+1] = arr[h];
	    arr[h]=temp;
	    return i+1;
	    
	}
}
