#include<iostream>
using namespace std;

void merge(int * arr, int s,int e)
{
    int mid = s+(e-s)/2;

    int len1 = mid +1 -s;
    int len2 = e -mid;

    int* left = new int[len1];
    int* right = new int[len2];

    //copy values of left part
    int k = s;
    for(int i=0;i<len1;i++)
    {
        left[i] = arr[k];
        k++;
    }
    //copy values of right part
    k = mid+1;
    for(int i=0;i<len2;i++)
    {
        right[i] = arr[k];
        k++;
    }

    //now merge them
    int leftIndex =0;
    int rightIndex =0;
    int mainIndex = s;

    while(leftIndex < len1 && rightIndex < len2)
    {
        if(left[leftIndex] < right[rightIndex])
        {
            arr[mainIndex] = left[leftIndex];
            mainIndex++;
            leftIndex++;
        }
        else
        {
            arr[mainIndex] = right[rightIndex];
            mainIndex++;
            rightIndex++;    
        }
    }
    
    while(leftIndex < len1)
    {
            arr[mainIndex] = left[leftIndex];
            mainIndex++;
            leftIndex++;
    }
    while(rightIndex < len2)
    {
            arr[mainIndex++] = right[rightIndex++];  
    }
}

void mergeSort(int * arr, int s,int e)
{
    //base case
    if(s>=e)
    {
        return;
    }
    int mid = s+(e-s)/2;
    //left part 
    mergeSort(arr,s,mid);

    //gor right part
    mergeSort(arr,mid+1,e);

    //merging them
    merge(arr,s,e);
}

int main()
{
    int arr[] = {2,5,6,3,1,8,12,9};
    int n =8;
    int s =0;
    int e =n-1;
    mergeSort(arr,s,e);

    cout<<"After mergeSort:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    } 
return 0;
}