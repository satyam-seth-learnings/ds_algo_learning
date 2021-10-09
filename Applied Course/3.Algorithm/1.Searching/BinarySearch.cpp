//Iterative solution to search element using binary search
#include <stdio.h> 
#include<stdlib.h>
int binarySearch(int arr[], int l, int r, int x) 
{ 
    while (l <= r)
    { 
        int m = l + (r - l) / 2; 
  
        // Check if x is present at mid 
        if (arr[m] == x) 
            return m; 
  
        // If x greater, ignore left half 
        if (arr[m] < x) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
  
    return -1; //means element is not found 
} 
  
int main(void) 
{ 
    int i, ele, n, *arr;
	printf("Enter number of elements in array\n");
	scanf("%d", &n);
	//allocate dynamic memory 
	arr = (int*)malloc(n*sizeof(int));
	printf("Enter elements into an array\n");
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
 
    printf("Enter element to search in an array\n");
    scanf("%d", &ele);
    int result = binarySearch(arr, 0, n - 1, ele); 
    (result == -1) ? printf("Element is not present"
                            " in array") 
                   : printf("Element is present at "
                            "index %d", 
                            result); 
    return 0; 
} 
