/*
Divide and Conquer Technique
SPACE COMPLEXITY: Big O(n)
TIME COMPLEXITY: Big O(nlogn)

Conquer Step: Big O(n)
Divide Step: Big O(logn)


*/

#include <iostream>
using namespace std;

void merge(int *arr, int start, int end)
{
    cout<<"In merge: Start="<<start<<" and End="<<end<<endl;
    int mid = start + (end - start) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    // create 2 smaller arrays

    int *first = new int[len1];
    int *second = new int[len2];

    // copy the values from main array to smaller arrays

    int k = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    // merge 2 sorted arrays

    int index1 = 0;
    int index2 = 0;
    int mainarrayindex = start;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainarrayindex++] = first[index1++];
        }
        else
        {
            arr[mainarrayindex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainarrayindex++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[mainarrayindex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void mergesort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;
//Divide
    mergesort(arr, start, mid);

    mergesort(arr, mid + 1, end);
//conquer
    merge(arr, start, end);
    for (int i = 0; i < end+1; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[6] = {6, 9, 3, 1, 12, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr, 0, size - 1);
    cout << "The sorted array after MergeSort is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}