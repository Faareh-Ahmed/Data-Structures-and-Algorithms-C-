/*
Insertion Sort doesnot Swaps element
it only shifts the elements

It is very Adaptable and stable algo
after each round our array is being sorted 

TIME COMPLEXITY: Big O(n^2)
SPACE COMPLEXITY: Big O(1)

Best Case= Big O(n)
Worst Case= Big O(n^2)

*/

#include <iostream>
#include <vector>
using namespace std;

void insertionsort(vector<int> &arr, int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        // rounds from 1 to n-1
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    vector<int> arr = {64, 32, 11, 15, 7, 3};
    int size = arr.size();
    insertionsort(arr, size);
    cout << "The sorted array after Insertion Sort is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}