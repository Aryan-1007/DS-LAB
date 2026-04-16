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

    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && a[j] < a[j - 1])
        {
            int t = a[j];
            a[j] = a[j - 1];
            a[j - 1] = t;
            j--;
        }
    }

    cout << "Sorted array (Insertion Sort): ";
    for (int x : a)
        cout << x << " ";
}