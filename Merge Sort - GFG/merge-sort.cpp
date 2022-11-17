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
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int n1=m-l+1,n2=r-m;
        //  int first_arr[n1],second_arr[n2];
        vector<int> first_arr(n1),second_arr(n2);
         int first_arr_idx=0,second_arr_idx=0,idx=l;
         for(int i=0;i<n1;i++){
             first_arr[i]=arr[l+i];
         }
         for(int i=0;i<n2;i++){
             second_arr[i]=arr[m+i+1];
         }
         while(first_arr_idx<n1 && second_arr_idx<n2){
             if(first_arr[first_arr_idx]<=second_arr[second_arr_idx]){
                 arr[idx]=first_arr[first_arr_idx];
                 first_arr_idx++;
             }
             else{
                 arr[idx]=second_arr[second_arr_idx];
                 second_arr_idx++;
             }
             idx++;
         }
         while(first_arr_idx<n1){
            arr[idx]=first_arr[first_arr_idx];
            first_arr_idx++;
            idx++;
         }
         while(second_arr_idx<n2){
            arr[idx]=second_arr[second_arr_idx];
            second_arr_idx++;
            idx++;
         }
        //  delete[] first_arr;
        //  delete[] second_arr;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r){
            return;
        }
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        
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