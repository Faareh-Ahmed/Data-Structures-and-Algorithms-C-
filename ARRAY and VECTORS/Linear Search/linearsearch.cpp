// This is the Linear Search program Algorithm 
// its Space Complexity= Big O(n) 


#include <iostream>
using namespace std;

bool  linearsearch(int array[],int size,int key)
{
    for (int i=0;i<size;i++)
    {
        if(key==array[i])
        {
            return true;
        }
    }
    return false ;
}
int main()
{
    int array[5]={2,5,8,12,3};
    cout<<"Size of array"<<sizeof(array)<<endl;
    cout<<"Size of array index"<<sizeof(array[0])<<endl;
    int size =sizeof(array)/sizeof(array[0]);
    bool value=linearsearch(array,size,12);
    cout<<"The value is Present: "<<value;
    return 0;
}