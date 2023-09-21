

#include <iostream>
using namespace std;

bool binarysearch(int array[],int start,int end,int size,int key)
{
    int mid=start+(end-start)/2; //(Recommended)
    if(start>end)
    {
        return false;
    }
    if(array[mid]==key)
    {
        return true;
    }
    if(array[mid]>key)
    {
        binarysearch(array,start,mid-1,size/2,key);
    }
    else{
        binarysearch(array,mid+1,end,size/2,key);
    }

    
}


int main()
{
     int array[7]={2,5,8,11,15,18,21};
    int size = sizeof(array)/sizeof(array[0]);
    bool value = binarysearch(array,0,size-1,size,18);
    cout<<"the Key value is Present: "<<value;

    return 0;
}