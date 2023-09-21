// PROBLEM:
// Given array of integars of array, return true if the
// number of occurances of each value in the array is
// unique , or false otherwise

#include <iostream>
#include <vector>
using namespace std;

bool findUNiqueNumberOccurance(int arr[], int size)
{
    int newarr[10];
    int keyarr[10];

    for (int i = 0; i < size; i++)
    {
        int count = 0;
        int key = arr[i];
        cout<<"The key is: "<<key<<endl;
        keyarr[i] = key;
        int newkey = keyarr[i];
        

        // loop to check if the given number has already been searched for or not
        
            int newcount = 0;

            cout<<"The new key is: "<<newkey<<endl;
            for (int j = 0; j < size; j++)
            {
                if (newkey == keyarr[j])
                {
                    newcount++;
                }
            }
            if (newcount > 1)
            {
                continue;
            }
        

// loop to count the occurances of element
        for (int j = 0; j < size; j++)
        {
            if (key == arr[j])
            {
                count++;
            }
        }
        newarr[i] = count;
    }

    // checking the uniqueness of their occurances
    int key;
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        key = newarr[i];
        for (int j = 0; j < size; j++)
        {
            if (key == newarr[j])
            {
                count++;
            }
        }
        if (count == 1)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{

    int arr[10] = {-3,0,1,-3,1,1,1,-3,10,0};
    bool unique = findUNiqueNumberOccurance(arr, 10);
    cout << ("The unique element in this array is: ", unique);
    return 0;
}