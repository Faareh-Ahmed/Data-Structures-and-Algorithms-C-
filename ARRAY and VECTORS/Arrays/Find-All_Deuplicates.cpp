/*
PROBLEM:
you are given array of size N contaniing integars and each integar
appears at least once or twice. Return an array of all the integars that
appears twice
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> findDuplicate(int arr[])
{
    vector<int> newarr;
    for(int i=0;i<10;i++)
    {
        int key=arr[i];
        int count=0;
        for(int j=0;j<10;j++)
        {
            if(key==arr[j])
            {
                count++;
            }
        }
        if(count==2)
        {
            newarr.push_back(key);
        }
    }
    
    return newarr;
}

int main()
{
    int arr[10]={1,1,2,5,5,6,7,8,6,9};
    vector<int> result = findDuplicate(arr);
    
    cout << "The duplicates: ";
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    
    return 0;
}