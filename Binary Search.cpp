#include<bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int left, int right, int key)
{
    // Base Case
    if(left == right)
    {
        if(arr[left] == key)
        {
            return left;
        }
        return -1;
    }

    int mid = (left + right) / 2;

    if(arr[mid] == key)
    {
        return mid;
    }
    else if(arr[mid] > key)
    {
        return binarySearch(arr, left, mid-1, key);
    }
    else
    {
        return binarySearch(arr, mid+1, right, key);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    int n = sizeof(arr)/sizeof(arr[0]);

    int key = 3;

    int keyIndex = binarySearch(arr, 0, n-1, key);

    if(keyIndex == -1)
    {
        cout << "Element is not in the array." << "\n";
    }
    else
    {
        cout << key << " is at index " << keyIndex << "\n";
    }

    return 0;
}
