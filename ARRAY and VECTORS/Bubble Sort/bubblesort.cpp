/*
 Completed in Round
 In each Round the Largest element of the round is placed at the end
 Total Rounds = n-1
 where n is the length of the array

TIME COMPLEXITY:  Big O(n^2)
SPACE COMPLEXITY: Big O(1)

Best Case (already sorted) = Big O(n)
Worst Case (reverese sorted)= Big O(n^2)

*/

#include <iostream>
#include <vector>
using namespace std;

void bubblesort(vector<int>&arr, int n)
{
    for(int i=1;i<=n-1;i++)
    {
        // for round 1 to n-1 
        bool swapped=false;
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false)
        {
            break;
        }
    }
}

void swap(int &x, int &y)
{
    int z=x;
    x=y;
    y=z;
}

int main()
{
    vector<int>arr={12,34,2,6,11,5};
    int size=arr.size();
    bubblesort(arr,size);
    cout<<"The sorted array after Bubble Sort is: "<<endl;
    for(int num : arr)
{
    cout << num << " ";
}

    return 0;
}