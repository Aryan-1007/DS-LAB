#include <bits/stdc++.h>
using namespace std;

vector<int> mergeSort(vector<int> a)
{
    if (a.size() <= 1)
        return a;

    int mid = a.size() / 2;
    vector<int> left(a.begin(), a.begin() + mid);
    vector<int> right(a.begin() + mid, a.end());

    left = mergeSort(left);
    right = mergeSort(right);

    vector<int> res;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
            res.push_back(left[i++]);
        else
            res.push_back(right[j++]);
    }

    while (i < left.size())
        res.push_back(left[i++]);
    while (j < right.size())
        res.push_back(right[j++]);

    return res;
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

    a = mergeSort(a);

    cout << "Sorted array (Merge Sort): ";
    for (int x : a)
        cout << x << " ";
}