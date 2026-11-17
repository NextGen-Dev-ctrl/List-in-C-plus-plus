#include<iostream>
using namespace std;
int binary_search(int arr[],int size,int target)
{
    int low = 0;
    int high = size - 1;
    int mid;
    while(low <= high)
    {
        mid = low + (high - low) / 2;
        if(target == arr[mid])
        {
            return mid;
        }
        else if(target < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int roll_no[] = {101,105,110,120,135,150,170};
    // problem can say chech for 135 and 112
    int key[] = {135,112};
    for(int i = 0; i < 2; i++)
    {
        int ret = binary_search(roll_no,7,key[i]);
        if(ret == -1)
        {
            cout<<"Value Not Found!"<<endl;
        }
        else
        {
            cout<<"Roll No "<<key[i]<<" Found at index "<<ret<<endl;
        }
    }
}