#include <iostream>
using namespace std;


void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
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
void mergeSort(int arr[], int l, int r, int K)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, K);
        mergeSort(arr, m + 1, r, K);

        merge(arr, l, m, r);
    }
}
int kthLargest(int arr[], int N, int K)
{
    mergeSort(arr, 0, N - 1, K);
    return arr[N - K];
}


int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    int arr[n];

    int K = 4;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "kth largest element is " << kthLargest(arr, n, K);

    return 0;
}