/*
SPACE COMPLEXITY: Big O(n)
TIME COMPLEXITY: Big O(nlogn)
Worst Case: Big O(n^2)

*/

#include <iostream>
using namespace std;


void swap(int &x,int &y)
{
    int z=x;
    x=y;
    y=z;
}
int partition(int *arr, int start, int end)
{
    int pivot=arr[start];

    int count=0;
    for(int i=start+1;i<=end;i++)
    {
        if(arr[i]<=pivot)
        {
            count++;
        }
    }

    int pivotIndex=start+count;
    swap(arr[pivotIndex],arr[start]);

    int i=start;
    int j=end;

    while(i<pivotIndex && j>pivotIndex)
    {
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
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;

}

void quicksort(int *arr, int start, int end)
{
    if(start>=end)
    {
        return;
    }

    int p=partition(arr,start,end);
    quicksort(arr,start,p-1);

    quicksort(arr,p+1,end);
}

int main()
{
    int arr[6]={32,23,11,5,2,25};
    int size=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,size-1);
    cout<<"The sorted QuickSort Array is: "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}