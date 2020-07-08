#include <bits/stdc++.h>
#include <vector>
#include <cassert>
#include <queue>

namespace
{

using namespace std;

using Graph = vector<vector<long long int>>;

void minimizeCashFlow(Graph &flow, long long int n)
{

    long long int balance[n];
    memset(balance, 0, sizeof(balance));

    for (long long int u = 0; u < n; ++u)
    {
        for (long long int v = 0; v < n; ++v)
        {
            balance[u] -= flow[u][v];
            balance[v] += flow[u][v];
        }
    }

    priority_queue<long long int> fromQueue;
    priority_queue<long long int, vector<long long int>, greater<long long int>> toQueue;

    for (long long int v = 0; v < n; ++v)
    {
        if (balance[v] > 0)
            toQueue.push(v);
        else if (balance[v] < 0)
            fromQueue.push(v);
    }

    for (long long int u = 0; u < n; ++u)
    {
        for (long long int v = 0; v < n; ++v)
        {
            flow[u][v] = 0;
        }
    }

    while (!fromQueue.empty())
    {
        long long int u = fromQueue.top();
        long long int v = toQueue.top();

        if (-balance[u] <= balance[v])
        {
            long long int money = -balance[u];
            flow[u][v] = money;
            balance[u] = 0;
            balance[v] -= money;
        }
        else
        {
            long long int money = balance[v];
            flow[u][v] = money;
            balance[u] += money;
            balance[v] = 0;
        }

        if (balance[u] == 0)
            fromQueue.pop();

        if (balance[v] == 0)
            toQueue.pop();
    }
}

} // namespace

int main()
{
    long long int t;
    cin >> t;
    for (long long int testCase = 1; testCase <= t; testCase++)
    {
        unsigned long long int n, m;
        cin >> n >> m;
        Graph flow{n, vector<long long int>(n)};
        for (unsigned long long int i = 0; i < m; i++)
        {
            long long int x, y, c;
            cin >> x >> y >> c;
            flow[x - 1][y - 1] = c;
        }
        minimizeCashFlow(flow, n);

        long long int ans = 0;
        for (unsigned long long int u = 0; u < n; ++u)
        {
            for (unsigned long long int v = 0; v < n; ++v)
            {
                if (flow[u][v] != 0)
                {
                    ans += flow[u][v];
                }
            }
        }
        cout << "Case #"<<testCase<<": "<< ans << endl;
        for (unsigned long long int u = 0; u < n; ++u)
        {
            for (unsigned long long int v = 0; v < n; ++v)
            {
                if (flow[u][v] != 0)
                {
                    printf("%lld %lld %lld\n", u+1, v+1, flow[u][v]);
                }
            }
        }
        flow.clear();
    }
}