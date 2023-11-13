// 33. Search in Rotated Sorted Array

#include <iostream>
using namespace std;

int searchIndex(int array[], int s, int key, int e)
{
    int start = s;
    int end = e - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (array[mid] == key)
        {
            return mid;
        }
        if (array[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}
int findPivateElemets(int array[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (array[mid] >= array[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}
int findInPivateElemets(int array[], int size, int key)
{
    int index = -1;
    int pivaotElemts = findPivateElemets(array, size);
    if (array[pivaotElemts] == key)
    {
        return pivaotElemts;
    }
    if (array[0] == key)
    {
        return 0;
    }
    if (array[size - 1] == key)
    {
        return size - 1;
    }
    if (key > array[pivaotElemts] && key < array[size - 1])
    {
        index = searchIndex(array, pivaotElemts, key, size);
    }
    else
    {
        index = searchIndex(array, 0, key, pivaotElemts);
    }
    return index;
}
int main()
{
    int array[5] = {7, 9, 1, 2, 3};
    int pivatElements = findInPivateElemets(array, 5, 43);
    cout << "Your Elemts are at " << pivatElements;
}