#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        int idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[idx])
                idx = j;
        }
        int t = a[i];
        a[i] = a[idx];
        a[idx] = t;
    }

    cout << "Sorted array (Selection Sort): ";
    for (int x : a)
        cout << x << " ";
}