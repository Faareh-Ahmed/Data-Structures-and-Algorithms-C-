/*
PROBLEM: find the Peak Index of Mountain Array

example: array=[2,4,5,8,6,5,3,1]  Peak index=3
explaintaion: 8 is the element whose on left side array is in ascendingly 
              sorted and on right array is descendingly sorted

*/


#include <iostream>
using namespace std;

int binarysearch(int array[],int size)
{
    int start=0;
    int end=size-1;

    int mid=start+(end-start)/2; //(Recommended)

    while(start<=end)
    {
        if(array[mid]>array[mid-1] && array[mid]>array[mid+1])
        {
            return mid;
        }
        else if(array[mid]>array[mid-1] && array[mid]<array[mid+1])
        {
            start=mid+1;
            mid=start+(end-start)/2; //(Recommended)
        }
        else if(array[mid]<array[mid-1] && array[mid]>array[mid+1])
        {
            end=mid-1;
            mid=start+(end-start)/2; //(Recommended)
        }
        cout<<"No";
    }
    cout<<"YES";
    return -1;
}


int main()
{
    int array[6]={2,5,7,8,11,10};
    int size = sizeof(array)/sizeof(array[0]);
    int value = binarysearch(array,size);
    cout<<"the Key value is Present: "<<value;

    return 0;
}