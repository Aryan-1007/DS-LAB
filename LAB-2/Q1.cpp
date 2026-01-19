#include <bits/stdc++.h>
using namespace std;
void insert(int *array, int postion, int element)
{
    realloc(array, 11 * sizeof(int));
    for (int i = postion; i < 11; i++)
        array[i] = array[i - 1];
    array[postion - 1] = element;
}
void Delete(int *array, int position)
{
    for (int i = position - 1; i < 10; i++)
        array[i] = array[i + 1];
    realloc(array, 9 * sizeof(int));
}
void Reverse(int *array)
{
    // int *arr;
    // arr = (int *)malloc(10 * sizeof(int));
    // for (int i = 0; i < 10; i++)
    //     arr[i] = array[10 - i - 1];
    // for (int i = 0; i < 10; i++)
    //     array[i] = arr[i];
    for (int i = 0; i < 5; i++)
        swap(array[i], array[9 - i]);
}
void copy(int *array1, int *array2, int start, int end)
{
    int temp = end - start + 1;
    realloc(array2, (10 + temp) * sizeof(int));
    for (int i = 0; i < temp; i++)
    {
        array2[10 + i] = array1[start + i - 1];
    }
}
void merge(int *array1, int *array2, int *array3)
{
    int pos = 0, i = 9, j = 9;
    sort(array1,array1+10);
    sort(array2,array2+10);
    while (pos < 20)
    {
        if (array1[i] > array2[j])
        {
            array3[pos] = array1[i];
            i--;
            pos++;
        }
        else
        {
            array3[pos] = array2[j];
            j--;
            pos++;
        }
    }
}
int sum(int *array)
{
    int temp{};
    for (int i = 0; i < (sizeof(array) / sizeof(int)); i++)
        temp += array[i];
    return temp;
}
int Search(int *array, int target)
{
    for (int i = 0; i < (sizeof(array) / sizeof(int)); i++)
    {
        if (array[i] == target)
            return i + 1;
        return -1;
    }
}
void Separate(int *array, int *array1, int *array2)
{

}

int main(int argc, char const *argv[])
{
    int *SubArray1, *SubArray2, *MainArray;
    SubArray1 = (int *)malloc(10 * sizeof(int));
    SubArray2 = (int *)malloc(10 * sizeof(int));
    MainArray = (int *)malloc(20 * sizeof(int));
    
    return 0;
}
