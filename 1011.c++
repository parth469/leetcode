// 1011. Capacity To Ship Packages Within D Days
// Book Allocation
#include <iostream>
using namespace std;

bool isPossbile(int array[], int size, int days, int mid, int maxValue)
{
    int sumDay = 0;
    int day = 1;
    for (int i = 0; i < size; i++)
    {
        if (sumDay + array[i] <= mid)
        {
            sumDay += array[i];
        }
        else
        {

            day++;
            if (day > days || array[i] > mid)
            {
                return false;
            }
            sumDay = array[i];
        }
    }
    return true;
}

int main()
{
    int weights[6] = {3, 2, 2, 4, 1, 4};
    int size = 6;
    int days = 3;
    int start = 0;
    int arraySum = 0;
    if (size < days)
    {
        return -1;
    }
    for (int i = 0; i < size; i++)
    {
        arraySum += weights[i];
    }
    int end = arraySum;
    int ans = 0;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (isPossbile(weights, size, days, mid, arraySum))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    cout << ans;
}