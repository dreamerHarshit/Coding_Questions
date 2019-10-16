public class Main
{
	public static void main(String[] args) {
	//	Array on which quick sort will be performed
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
		// Applying Divide and Conquer Strategy
	    
	    if(l < h)
	    {
		    // pivot is selected by the partition function
	      int pivot = partition(arr,l,h);
		     // Recursively sort elements for elements before partition and elements after partition 
	       quicksort(arr,l,pivot-1);
	       quicksort(arr,pivot+1,h);
	    }
	    
	}
	static int partition(int arr[],int l,int h)
	{
		 /* This function takes last element as pivot, placesthe pivot element at its correct position in sorted
		    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
	    int pi = arr[h];
	    int i=l-1;
	    //int j =l-1;
	    for(int j=l;j<=h-1;j++)
	    {
		  //If current element is smaller than the pivot
	        if(arr[j] <pi)
	        {
	            i++;
			// swap arr[i] and arr[j] 
	            int temp=arr[j];
	            arr[j] = arr[i];
	            arr[i] = temp;
	        }
	    }
		 // swap arr[i+1] with pivot 
	    int temp=arr[i+1];
	    arr[i+1] = arr[h];
	    arr[h]=temp;
		//returning pivot position
	    return i+1;
	    
	}
}
