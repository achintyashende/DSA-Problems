#include<iostream>
using namespace std;

int partition(int arr[],int s,int e)
{
    //choose pivot index and pivot element
    int pivotIndex = s;
    int pivotElement = arr[s];

    //find the correct position of pivot element and place it there 
    int count =0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivotElement)
        {
            count++;
        }
    }
    int correctIndex = s+count;
    swap(arr[correctIndex],arr[pivotIndex]);
    pivotIndex = correctIndex;

    //left me chote element and right me bade element
    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex)
    {
        while(arr[i]<pivotElement)
        {
            i++;
        }
        while(arr[j]>pivotElement)
        {
            j--;
        }
        if(i<pivotIndex && j>pivotIndex)
        {
            swap(arr[i],arr[j]);
        }
        return pivotIndex;
    }
}

void QuickSort(int arr[],int s,int e)
{
    //base case
    if(s>=e)
    {
        return;
    }
    int pivot = partition(arr,s,e);
    //for left side

    QuickSort(arr,s,pivot-1);

    //for right side
    QuickSort(arr,pivot +1,e);
}

int main()
{
    int arr[] = {2,5,6,3,1,8,12,9};
    int n =8;
    int s =0;
    int e =n-1;
    cout<<"Before QuickSort:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    } 
    cout<<endl;
    QuickSort(arr,s,e);
    cout<<endl;
    cout<<"After QuickSort:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    } 
return 0;
}