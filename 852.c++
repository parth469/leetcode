// 852. Peak Index in a Mountain Array

#include <iostream>
using namespace std;
int findPickElemets(int array[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (array[mid - 1] < array[mid] && array[mid] > array[mid + 1])
        {
            cout << array[mid];
            return 0;
        }
        else if (array[mid - 1] < array[mid])
        {
            start = mid + 1;
        }
        else if (array[mid] > array[mid + 1])
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
}
int main()
{
    int array[4] = {3, 4, 5, 2};
    findPickElemets(array, 4);
}
