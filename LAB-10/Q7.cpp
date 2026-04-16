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

    int mx = 0;
    for (int x : a)
        if (x > mx)
            mx = x;

    for (int exp = 1; mx / exp > 0; exp *= 10)
    {
        vector<int> out(n);
        int cnt[10] = {0};

        for (int i = 0; i < n; i++)
            cnt[(a[i] / exp) % 10]++;
        for (int i = 1; i < 10; i++)
            cnt[i] += cnt[i - 1];

        for (int i = n - 1; i >= 0; i--)
        {
            int d = (a[i] / exp) % 10;
            out[cnt[d] - 1] = a[i];
            cnt[d]--;
        }

        a = out;
    }

    cout << "Sorted array (Radix Sort): ";
    for (int x : a)
        cout << x << " ";
}