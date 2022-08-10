#include<stdio.h>
#include<conio.h>
void quick(int arr[],int n);
void quicksort(int arr[],int beg,int end,int *loc);

int main()
{
    int arr[]={40,1,8,9,3,0,5,6,2,7};
    int i,j,n;
    n=sizeof(arr)/sizeof(int);
    printf("\nList before sorting: ");
    for(i=0;i<n;i++)
    {
        printf("%d, ",arr[i]);
    }
    quick(arr,n);
    printf("\nList after Sorting: ");
    for ( i = 0; i < n; i++)
    {
        printf("%d, ",arr[i]);
    }
    return 0;
}
void quick(int arr[],int n)
{
    int loc,beg,end;
    int lower[n],upper[n],top=0;
    lower[0]=0;
    upper[0]=n-1;
    while(top>-1)
    {
        beg=lower[top];
        end=upper[top];
        top--;
        quicksort(arr,beg,end,&loc);
        if(beg<loc-1)
        {
            top++;
            lower[top]=beg;
            upper[top]=loc-1;

        }
        if(end>loc+1)
        {
            top++;
            lower[top]=loc+1;
            upper[top]=end;

        }
    }
}

void quicksort(int arr[],int beg,int end,int *loc)
{
    int left=beg,temp,right=end;
    while(right>left)
    {
        *loc=left;
        while(arr[*loc]<arr[right] && *loc<right) right--;
        if(*loc==right)
        {
            return ;

        }
        if(arr[*loc]>arr[right])
        {
            temp=arr[*loc];
            arr[*loc]=arr[right];
            arr[right]=temp;
        }
        *loc=right;
        while(arr[left]<arr[*loc] && *loc>left) left++;
        if(*loc==left)
        {
            return ;

        }
        if(arr[left]>arr[*loc])
        {
            temp=arr[*loc];
            arr[*loc]=arr[left];
            arr[left]=temp;
        }
    }
    return ;
}