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
    void merge(int *arr, int s, int e)
    {
         // Your code here
         int mid=(s+e)/2;
         
         int len1=mid-s+1;
         int len2=e-mid;
         
         int *first= new int[len1];
         int *second=new int[len2];
         
         //copy value
         int mainArrayindex=s;
         for(int i=0;i<len1;i++)
         {
             first[i]=arr[mainArrayindex++];
             
         }
         mainArrayindex=mid+1;
         for(int i=0;i<len2;i++)
         {
             second[i]=arr[mainArrayindex++];
         }
         //merge 2 sorted array
         int index1=0;
         int index2=0;
         mainArrayindex=s;
         while(index1<len1 && index2<len2)
         {
             if(first[index1]<second[index2])
             {
                 arr[mainArrayindex++]=first[index1++];
             }
             else{
                 arr[mainArrayindex++]=second[index2++];
             }
         }
         
         while(index1<len1)
         {
             arr[mainArrayindex++]=first[index1++];
         }
         while(index2<len2)
         {
             arr[mainArrayindex++]=second[index2++];
         }
    }
    public:
    void mergeSort(int *arr, int s, int e)
    {
        //code here
        if(s>=e)
        {
            return ;
            
        }
        int mid=(s+e)/2;
        
        //left par sorting
        mergeSort(arr,s,mid);
        //right part sorting
        mergeSort(arr,mid+1,e);
        //merge
        merge(arr,s,e);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends
