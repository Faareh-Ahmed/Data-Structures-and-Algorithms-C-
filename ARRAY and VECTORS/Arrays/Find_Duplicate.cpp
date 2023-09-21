/*
PROBLEM:
you are given array of size N contaniing each number between 1 to N-1
at least once. there is a single integar value in the array that is
present twice . find that duplicate integar value in the array
*/

#include <iostream>
using namespace std;

int findDuplicate(int arr[])
{
    for(int i=0;i<10;i++)
    {
        int count=0;
        int key=arr[i];
        for(int j=0;j<10;j++)
        {
            if(key==arr[j])
            {
                count++;
            }
        }
        if(count==2)
        {
            return key;
        }
    }
    return -1;
}

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,6,9};
    int key=findDuplicate(arr);
    cout<<"The key is: "<<key;
    return 0;
}