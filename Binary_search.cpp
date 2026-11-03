#include <iostream>
using namespace std;
void sort(int arr[] , int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int min = i;
        for(int j = 0; j < size; j++)
        {
            if(arr[j] < min)
            {
                min = j;
            }
        }
        if(min != i)
        {
            int temp = arr[i];
            arr[i] = min;
            min = temp;
        }
    }
    cout<<"Sorted Array : [ ";
    for(int x = 0; x < size; x++)
    {
        cout<<x<<" ";
    }
    cout<<" ]";
}
int main()
{
    int arr[] = {23, 35, 46, 57, 68, 79, 89, 92}; // array must be sorted
    int size_of_array = sizeof(arr) / sizeof(arr[0]);
    int find = 79;
    int low = 0;
    int high = size_of_array - 1;
    int mid;
    bool isFound = false; // To check if the value is found or not
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == find)
        {
            isFound = true;
            break;
        }
        else if (find < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (isFound)
    {
        cout << arr[mid] << " Find at index " << mid << endl;
    }
    else
    {
        cout << "Value NOt Found!";
    }
}