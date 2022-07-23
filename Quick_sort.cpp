//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends

class Solution
{
    public:
    void swap(int *xp, int *yp)
    {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    }
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int s, int e)
    {
        // code here
        if(s>e)
       {
           return;
       }
       int p=partition(arr,s,e);
       //left part
       quickSort(arr,s,p-1);
       //right side
       quickSort(arr,p+1,e);
    }
    
    public:
    int partition (int arr[], int s, int e)
    {
       // Your code here
       int pivot= arr[s];
       int cnt=0;
       for(int i=s+1;i<=e;i++)
       {
           if(arr[i]<=pivot)
           {
               cnt++;
           }
       }
           //place pivot at right position
           int pivotIndex=s+cnt;
           swap(&arr[pivotIndex],&arr[s]);
           
           
           //left and right handle
           int i=s,j=e;
           while(i<pivotIndex && j>pivotIndex){
               while(arr[i]<pivot)
               {
                   i++;
               }
               while(arr[j]>pivot)
               {
                   j--;
               }
               if(i<pivotIndex && j>pivotIndex)
               {
                   swap(&arr[i++],&arr[j--]);
                   
                   
               }
           }
           return pivotIndex;  
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends


Alternative solution of Quick sort
/*
//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends

class Solution
{
    public:
    void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
public:
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
public:
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends
*/
