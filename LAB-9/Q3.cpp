#include <bits/stdc++.h>
using namespace std;

void intersection(int a[], int m, int b[], int n)
{
    unordered_set<int> setA;
    unordered_set<int> result;

    for (int i = 0; i < m; i++)
        setA.insert(a[i]);

    for (int i = 0; i < n; i++)
    {
        if (setA.find(b[i]) != setA.end())
            result.insert(b[i]);
    }

    cout << "Intersection: ";
    for (auto x : result)
        cout << x << " ";
}

int main()
{
    int m, n;

    cout << "Enter size of array a: ";
    cin >> m;
    int a[m];

    cout << "Enter elements of array a: ";
    for (int i = 0; i < m; i++)
        cin >> a[i];

    cout << "Enter size of array b: ";
    cin >> n;
    int b[n];

    cout << "Enter elements of array b: ";
    for (int i = 0; i < n; i++)
        cin >> b[i];

    intersection(a, m, b, n);

    return 0;
}