#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath> //pow함수 선언
#include <limits.h>

#define MAX 20001
using namespace std;
#define INF 10000000

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            cout << L[i] << " ";
            cout << endl;
            i++;
        }
        else
        {
            cout << R[j] << " ";
            cout << endl;
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// int main() {
//     int arr[] = {13, 7, 9, 1, 15, 6};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     mergeSort(arr, 0, n - 1);

//     for (int i = 0; i < n; i++)
//         cout << arr[i] << " ";
//     return 0;
// }

int main()
{
    int testcase;
    cin >> testcase;
    int temp;
    int arr[testcase];
    for (int i = 0; i < testcase; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < testcase - 1; i++)
    {
        for (int j = i + 1; j < testcase; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[j];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < testcase; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}