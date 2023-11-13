// 69. Sqrt(x)
#include <iostream>
using namespace std;
int sqroot(int num)
{
    int start = 1;
    int ans = 0;
    int end = num;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (mid * mid <= num)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int num = 6;
    cout << sqroot(1000000000);
}