#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int lcmall(int a[], int k)
{
    int res = a[0];
    for (int i = 0; i < k; i++)
    {
        res = lcm(res, a[i]);
    }
    return res;
}

int main()
{

    int t;
    scanf("%d",&t);
    for (int testCase = 1; testCase <= t; testCase++)
    {
        int k;
        scanf("%d",&k);
        int a[k];
        for (int i = 0; i < k; i++)
        {
            scanf("%d",&a[i]);
        }
        int res = lcmall(a, k);
        int min = a[0];
        int i = 1;
        while (i != k)
        {
            if (gcd(min + i, res) != a[i])
            {
                min += lcmall(a, i);
                i = 1;
            }
            else
            {
                i++;
            }
        }
        printf("Case #%d: %d %d\n",testCase,min,res);
    }
    return 0;
}
