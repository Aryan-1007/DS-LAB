#include <bits/stdc++.h>
using namespace std;

void quick(vector<int> &a, int l, int r)
{
    if (l >= r)
        return;

    int i = l, j = r;
    int pivot = a[(l + r) / 2];

    while (i <= j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }

    quick(a, l, j);
    quick(a, i, r);
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quick(a, 0, n - 1);

    cout << "Sorted array (Quick Sort): ";
    for (int x : a)
        cout << x << " ";
}