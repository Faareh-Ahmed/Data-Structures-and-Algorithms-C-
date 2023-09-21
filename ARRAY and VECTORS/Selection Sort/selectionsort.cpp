/*
Selection sort works in Rounds
It picks the number and swaps it with the least or highest number
TOTAL ROUNDS= n-1
where n is the length of array 

SPACE COMPLEXITY: Big O(1) constant
TIME COMPLEXITY:  Big O(n^2)
Best Case = Worst Case = Big O(n^2)


It works better in smaller arrays 
*/

#include <iostream>
#include <vector>
using namespace std;

void selectionsort(vector<int> &arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minIndex=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}

void swap(int &x,int &y)
{
    int z=x;
    x=y;
    y=z;
}

int main()
{
    vector<int>arr={23,43,12,4,8,11};
    int size=arr.size();
    selectionsort(arr,size);
    cout << "Sorted array after selection sort: ";
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}