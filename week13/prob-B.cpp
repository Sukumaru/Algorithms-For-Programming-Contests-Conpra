#include <iostream>
#include <set>
#include <vector>
using namespace std;

/*
Given a number of friends who have to give or take some amount of money from one another.
 Design an algorithm by which the total cash flow among all the friends is minimized.
Link : http://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/
*/
vector<pair<long long, long long>> graph[100000];
set<pair<long long, long long>> amount_set;
set<pair<long long, long long>> amount_set1;

long long amount_array[100000];

void minCashFlow(long long v)
{
    long long min_amount;
    while (amount_set.rbegin()->first > 0) // while there are some cash flows left to handle
    {
        pair<long long, long long> pmin, pmax;
        pmin = *amount_set.begin();
        pmax = *amount_set.rbegin();
        min_amount = min(-pmin.first, pmax.first);
        cout << pmin.second + 1 << " " << pmax.second + 1 << " " << min_amount << "\n";
        amount_set.erase(pmin);
        amount_set.erase(pmax);
        pmin.first = pmin.first + min_amount;
        pmax.first = pmax.first - min_amount;
        amount_set.insert(pmin);
        amount_set.insert(pmax);
    }
}

long long minCashFlow1(long long v)
{
    long long ans = 0;
    long long min_amount;
    while (amount_set1.rbegin()->first > 0) // while there are some cash flows left to handle
    {
        pair<long long, long long> pmin, pmax;
        pmin = *amount_set1.begin();
        pmax = *amount_set1.rbegin();
        min_amount = min(-pmin.first, pmax.first);
        ans += min_amount;
        amount_set1.erase(pmin);
        amount_set1.erase(pmax);
        pmin.first = pmin.first + min_amount;
        pmax.first = pmax.first - min_amount;
        amount_set1.insert(pmin);
        amount_set1.insert(pmax);
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    for (int testCase = 1; testCase <= t; testCase++)
    {
        long long v, e;
        long long a, b, w;
        cin >> v >> e;
        long long i;
        for (int i = 0; i < v; i++)
        {
            amount_array[i] = 0;
        }
        for (i = 0; i < e; i++)
        {
            cin >> a >> b >> w;
            graph[a - 1].push_back(make_pair(b - 1, w));
            amount_array[a - 1] -= w;
            amount_array[b - 1] += w;
        }

        for (i = 0; i < v; i++)
        { // 0 based indexing
            amount_set.insert(make_pair(amount_array[i], i));
            amount_set1.insert(make_pair(amount_array[i], i));
        }
        cout << "Case #" << testCase << ": " << minCashFlow1(v) << endl;
        minCashFlow(v);
    }
    return 0;
}
