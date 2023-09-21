/*
PROBLEM:
you are given a sorted array/list  containing of N elements.
You are also given an integar K
Now your task is to find the first and last occurance of K in array

Example: array=[2,4,4,6] K=4
output: 1,2 (first and last index of 4)

*/

#include <iostream>
#include <vector>

using namespace std;

int firstoccurance(vector<int> &arr, int n, int key)
{
    int start = 0;
    int end = n - 1;
    int first=-1;
    int mid = start + (end - start) / 2; //(Recommended)

    while (start <= end)
    {
        if (key == arr[mid])
        {
            first=mid;
            end = mid - 1;
            mid = (start + end) / 2;
        }
        if (key < arr[mid])
        {
            end = mid - 1;
            mid = (start + end) / 2;
        }
        if (key > arr[mid])
        {
            start = mid + 1;
            mid = (start + end) / 2;
        }
    }
    return first;

}

int lastoccurance(vector<int> &arr, int n, int key)
{
    int start = 0;
    int end = n - 1;
    int last=-1;
    int mid = start + (end - start) / 2; //(Recommended)

    while (start <= end)
    {
        if (key == arr[mid])
        {
            last=mid;
            start = mid + 1;
            mid = (start + end) / 2;
        }
        if (key < arr[mid])
        {
            end = mid - 1;
            mid = (start + end) / 2;
        }
        if (key > arr[mid])
        {
            start = mid + 1;
            mid = (start + end) / 2;
        }
    }
    return last;
}

pair<int, int> firstandlastoccurance(vector<int> &arr, int n, int key)
{
    pair<int, int> p;
    p.first = firstoccurance(arr, n, key);
    p.second = lastoccurance(arr, n, key);
    return p;
}

int main()
{
    vector<int> array = {2, 5, 8, 11, 11, 11};
    // int size = sizeof(array) / sizeof(array[0]);
    int size=array.size();

    pair<int,int> p=firstandlastoccurance(array,size,11);
    cout<<"The pair value is: "<<p.first<<" "<<p.second;
    return 0;

}