#include <bits/stdc++.h>
using namespace std;

void radixSort(vector<int> &a)
{
    int n = a.size();
    int mx = *max_element(a.begin(), a.end());

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

    vector<int> neg, pos;

    // Separate numbers
    for (int x : a)
    {
        if (x < 0)
            neg.push_back(-x); // store absolute value
        else
            pos.push_back(x);
    }

    if (!neg.empty())
        radixSort(neg);
    if (!pos.empty())
        radixSort(pos);

    reverse(neg.begin(), neg.end());

    vector<int> result;

    for (int x : neg)
        result.push_back(-x);

    for (int x : pos)
        result.push_back(x);

    cout << "Sorted array (Radix Sort): ";
    for (int x : result)
        cout << x << " ";
}