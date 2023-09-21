// PROBLEM:
// You have been given an integar array of size N. Where N=2M+1
// Now in the given array M number are present twice and one number 
// is present only once_flagYpu need to find and return that number 
// which is unique in the array

// Unique element is always present according which is unique in the array

#include <iostream>
using namespace std;

int findUNique(int*arr, int size)
{
    int key;
    for(int i=0;i<size;i++){
        int count=0;
        key=arr[i];
        for(int j=0;j<size;j++){
            if(key==arr[j]){
                count++;
            }
        } 
        if(count==1){
            break;
        }
        
    }
    return key;
}
int main()
{

    int arr[10]={1,1,2,2,3,3,9,9,7,9};
    int unique=findUNique(arr,10);
    cout<<("The unique element in this array is: ",unique);
    return 0;


}