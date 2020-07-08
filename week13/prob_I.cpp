#include <iostream>
#include <cstdlib>
using namespace std;

int cir(int n, int m)
{
    int p = 0;
    for (int i = 2; i <= n; i++)
    {
        p = (p + m) % i;
    }
    return p + 1;
}
int main()
{
    int t;
    cin >> t;
    for (int testCase = 1; testCase <= t; testCase++)
    {
        int n, m;
        cin >> n >> m;
        cout << "Case #" << testCase << ": " << cir(n,m) << endl;
    }
}