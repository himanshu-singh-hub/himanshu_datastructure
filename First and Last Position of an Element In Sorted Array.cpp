int firstOcc(vector<int>& arr, int n, int key)

{

   int s = 0, e = n - 1;

   int mid = s + (e - s) / 2;

   int ans = -1;

 

   while (s <= e)

   {

       if (arr[mid] == key)

       {

           ans = mid;

           e = mid - 1; // this is done to find the leftmost occurence!!

       }

       else if (arr[mid] < key)

       {

           s = mid + 1;

       }

       else if (arr[mid] > key)

       {

           e = mid - 1;

       }

       mid = s + (e - s) / 2;

   }

   return ans;

}

 

int lastOcc(vector<int>& arr, int n, int key)

{

   int s = 0, e = n - 1;

   int mid = s + (e - s) / 2;

   int ans = -1;

 

   while (s <= e)

   {

       if (arr[mid] == key)

       {

           ans = mid;

           s = mid + 1;

       }

       else if (arr[mid] < key)

       {

           s = mid + 1;

       }

       else if (arr[mid] > key)

       {

           e = mid - 1;

       }

       mid = s + (e - s) / 2;

   }

   return ans;

}

 

 

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)

{

   pair<int, int> p;

   p.first= firstOcc(arr, n,k);

   p.second= lastOcc(arr,n,k);

   

   return p;

}
//alternative of this code is

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


vector<int> find(int arr[], int n , int x )
{
     int first_occ=-1;
   int last_occ=-1;
   vector <int> v;
   for(int i=0;i<n;i++)
   { if(arr[i]==x)
       {     if(first_occ==-1)
              {
               first_occ=i;
               last_occ=i;

               }
           else
               last_occ=i;
       }
}
 v.push_back(first_occ);
   v.push_back(last_occ);
   
   return v;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
