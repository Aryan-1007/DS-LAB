#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    int arr[N];
    cout << "Enter " << N << " integers:\n";
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int max_val = arr[0], min_val = arr[0], sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
        if (arr[i] > max_val)
            max_val = arr[i];
        if (arr[i] < min_val)
            min_val = arr[i];
    }

    float avg = (float)sum / N;

    cout << "Maximum value: " << max_val << endl;
    cout << "Minimum value: " << min_val << endl;
    cout << "Average value: " << avg << endl;

    int key;
    cout << "Enter a value to search: ";
    cin >> key;

    bool found = false;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element " << key << " found at index " << i << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Element " << key << " not found in the array.\n";

    return 0;
}
