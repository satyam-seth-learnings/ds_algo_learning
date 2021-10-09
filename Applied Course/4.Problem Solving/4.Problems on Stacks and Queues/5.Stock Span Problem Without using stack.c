#include <stdio.h>

void calculateSpan(int *arr, int n, int *stock) 
{ 
    // Span value of first element is always 1 
    stock[0] = 1; 
  
    //find stock values for rest 
    for (int i = 1; i < n; i++) { 
        int c = 1; 
        while ((i - c) >= 0 && arr[i] > arr[i - c]) { 
            c += stock[i - c]; 
        } 
        stock[i] = c; 
    } 
} 
  
//print elements of array 
void printSpan(int *arr, int n) 
{ 
    for (int i = 0; i < n; i++) 
        printf("%d\t", arr[i]); 
} 
  

int main() 
{ 
    int price[] = { 10, 4, 5, 90, 120, 80 }; 
    int n = sizeof(price) / sizeof(price[0]); 
    int stock[n]; 
    calculateSpan(price, n, stock); 
    printSpan(stock, n); 
  
    return 0; 
} 

