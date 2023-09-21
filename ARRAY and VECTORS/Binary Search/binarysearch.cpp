// Linear Search vs Binary Search :
// Total length of array= 1000:
// Linear Search: worst case 1000 times search (Big O(n))
// Binary Search: worst case 10 times search (Big O(logn))


#include <iostream>
using namespace std;

bool binarysearch(int array[],int size,int key)
{
    int start=0;
    int end=size-1;

    // int mid=(start+end)/2;   (Not recommended)
    
    // in this statement to find the mid there can be a problem 
    // suppose the start=end=(2 raise to power 31 - 1)
    // so in that case when we add them we will get value that is out of the range
    // hence we will get error 

    int mid=start+(end-start)/2; //(Recommended)

    while(start<=end)
    {
        if(key==array[mid])
        {
            return true;
        }
        if(key<array[mid])
        {
            end=mid-1;
            mid=(start+end)/2;
        }
        if(key>array[mid])
        {
            start=mid+1;
            mid=(start+end)/2;
        }
    }
    return false;
}


int main()
{
     int array[6]={2,5,8,11,15,18};
    int size = sizeof(array)/sizeof(array[0]);
    bool value = binarysearch(array,size,11);
    cout<<"the Key value is Present: "<<value;

    return 0;
}