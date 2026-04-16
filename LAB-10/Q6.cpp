#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> heap(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> heap[i];
        int j = i;
        while (j > 0)
        {
            int p = (j - 1) / 2;
            if (heap[p] < heap[j])
            {
                int t = heap[p];
                heap[p] = heap[j];
                heap[j] = t;
                j = p;
            }
            else
                break;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int t = heap[0];
        heap[0] = heap[i];
        heap[i] = t;

        int j = 0;
        while (true)
        {
            int l = 2 * j + 1, r = 2 * j + 2, largest = j;
            if (l < i && heap[l] > heap[largest])
                largest = l;
            if (r < i && heap[r] > heap[largest])
                largest = r;
            if (largest != j)
            {
                int t2 = heap[j];
                heap[j] = heap[largest];
                heap[largest] = t2;
                j = largest;
            }
            else
                break;
        }
    }

    cout << "Sorted array (Heap Sort): ";
    for (int x : heap)
        cout << x << " ";
}