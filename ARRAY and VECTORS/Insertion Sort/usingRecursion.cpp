
#include <iostream>
#include <vector>
using namespace std;

void insertionsort(vector<int> &arr, int n)
{
    if (n <= 1)
        return;

    insertionsort(arr, n - 1);

    int temp = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > temp)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = temp;
    cout << "\nThe sorted array after Insertion Sort is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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