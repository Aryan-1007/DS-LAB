#include <bits/stdc++.h>
using namespace std;

/* Insert element */
int *insert(int *arr, int &size, int pos, int ele)
{
    size++;
    arr = (int *)realloc(arr, size * sizeof(int));

    for (int i = size - 1; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = ele;
    return arr;
}

/* Delete element */
int *Delete(int *arr, int &size, int pos)
{
    for (int i = pos - 1; i < size - 1; i++)
        arr[i] = arr[i + 1];

    size--;
    arr = (int *)realloc(arr, size * sizeof(int));
    return arr;
}

/* Reverse (in-place) */
void Reverse(int *arr, int size)
{
    for (int i = 0; i < size / 2; i++)
        swap(arr[i], arr[size - i - 1]);
}

/* Reverse using temporary array */
void ReverseTemp(int *arr, int size)
{
    int *temp = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        temp[i] = arr[size - i - 1];

    for (int i = 0; i < size; i++)
        arr[i] = temp[i];

    free(temp);
}

/* Sum without recursion */
int sum(int *arr, int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
        s += arr[i];
    return s;
}

/* Sum using recursion */
int sumRec(int *arr, int size)
{
    if (size == 0)
        return 0;
    return arr[size - 1] + sumRec(arr, size - 1);
}

/* Linear search */
int Search(int *arr, int size, int key)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            return i + 1;
    return -1;
}

/* Copy elements to MainArray */
int copyToMain(int *sub, int *mainArr, int mainSize, int start, int end)
{
    for (int i = start - 1; i < end; i++)
        mainArr[mainSize++] = sub[i];
    return mainSize;
}

/* Merge two arrays in descending order */
void mergeDesc(int *a, int *b, int *c)
{
    sort(a, a + 10);
    sort(b, b + 10);

    int i = 9, j = 9, k = 0;
    while (i >= 0 && j >= 0)
        c[k++] = (a[i] > b[j]) ? a[i--] : b[j--];
}

/* Separate odd-even and positive-negative */
void Separate(int *arr, int size)
{
    cout << "Even: ";
    for (int i = 0; i < size; i++)
        if (arr[i] % 2 == 0)
            cout << arr[i] << " ";

    cout << "\nOdd: ";
    for (int i = 0; i < size; i++)
        if (arr[i] % 2 != 0)
            cout << arr[i] << " ";

    cout << "\nPositive: ";
    for (int i = 0; i < size; i++)
        if (arr[i] >= 0)
            cout << arr[i] << " ";

    cout << "\nNegative: ";
    for (int i = 0; i < size; i++)
        if (arr[i] < 0)
            cout << arr[i] << " ";
    cout << endl;
}

/* Display */
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int size1 = 10, size2 = 10, mainSize = 0;

    int *SubArray1 = (int *)malloc(size1 * sizeof(int));
    int *SubArray2 = (int *)malloc(size2 * sizeof(int));
    int *MainArray = (int *)malloc(20 * sizeof(int));

    cout << "Enter 10 elements for SubArray1:\n";
    for (int i = 0; i < 10; i++)
        cin >> SubArray1[i];

    cout << "Enter 10 elements for SubArray2:\n";
    for (int i = 0; i < 10; i++)
        cin >> SubArray2[i];

    int choice;
    do
    {
        cout << "\n1.Insert\n2.Delete\n3.Reverse(temp)\n4.Reverse(in-place)"
             << "\n5.Copy to MainArray\n6.Merge Descending\n7.Sum\n8.Sum Rec"
             << "\n9.Search\n10.Separate\n11.Display\n0.Exit\nChoice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            SubArray1 = insert(SubArray1, size1, 1, 100);
            break;

        case 2:
            SubArray1 = Delete(SubArray1, size1, 1);
            break;

        case 3:
            ReverseTemp(SubArray1, size1);
            break;

        case 4:
            Reverse(SubArray1, size1);
            break;

        case 5:
            mainSize = copyToMain(SubArray1, MainArray, mainSize, 1, 5);
            break;

        case 6:
            mergeDesc(SubArray1, SubArray2, MainArray);
            break;

        case 7:
            cout << "Sum = " << sum(SubArray1, size1) << endl;
            break;

        case 8:
            cout << "Sum (Rec) = " << sumRec(SubArray1, size1) << endl;
            break;

        case 9:
            cout << "Position: " << Search(SubArray1, size1, 5) << endl;
            break;

        case 10:
            Separate(MainArray, mainSize);
            break;

        case 11:
            display(SubArray1, size1);
            break;
        }
    } while (choice != 0);

    free(SubArray1);
    free(SubArray2);
    free(MainArray);
    return 0;
}
