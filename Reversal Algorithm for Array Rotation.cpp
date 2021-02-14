#include<bits/stdc++.h>

using namespace std;

void reverseArray(int arr[], int startIndex, int endIndex)
{
    int temp;

    for(int i=startIndex, j=endIndex; i<j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    return;
}

void rotateArray(int arr[], int n, int k)
{
    reverseArray(arr, 0, k-1);

    reverseArray(arr, k, n-1);

    reverseArray(arr, 0, n-1);

    return;
}

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n";

    return;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    int n = sizeof(arr)/sizeof(arr[0]);

    int k = 3;

    cout << "Initial array " << "\n";
    printArray(arr, n);

    rotateArray(arr, n, k);

    cout << "Array after rotation " << "\n";
    printArray(arr, n);

    return 0;
}
