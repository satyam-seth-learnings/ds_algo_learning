#include <stdio.h> 
#include<stdlib.h>
int search(int arr[], int n, int x) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
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
    int result = search(arr, n, ele); 
    (result == -1) ? printf("Element is not present in array") 
                   : printf("Element is present at index %d", 
                            result); 
    return 0; 
} 
