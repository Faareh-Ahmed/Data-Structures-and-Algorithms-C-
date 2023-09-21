
#include <iostream>
#include <vector>
using namespace std;

void bubblesort(vector<int> &arr, int start, int n)
{
    bool swapped = false;
    if (n == 0)
    {
        return;
    }

    for (int i = start; i < n; i++)
    {
        for (int j = 0; j < n - start; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            return;
        }
        
        bubblesort(arr, start + 1, n - 1);
    }
}

void swap(int &x, int &y)
{
    int z = x;
    x = y;
    y = z;
}

int main()
{
    vector<int> arr = {12, 34, 2, 1, 5, 5,8,11,15};
    int size = arr.size();
    bubblesort(arr, 0, size);
    cout << "The sorted array after Bubble Sort is: " << endl;
    for (int num : arr)
    {
        cout << num << " ";
    }

    return 0;
}