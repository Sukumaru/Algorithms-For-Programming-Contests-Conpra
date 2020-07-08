#include <bits/stdc++.h>

#include <vector>

using namespace std;
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

struct Items
{
    vector<int> val;
    vector<int> wt;
    vector<int> index;
};

// Prints the items which are put in a knapsack of capacity W
void printknapSack(int W, Items myitem, int number)
{
    int i, w;
    int K[number + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= number; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (myitem.wt[i - 1] <= w)
                K[i][w] = max(myitem.val[i - 1] +
                                  K[i - 1][w - myitem.wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // stores the result of Knapsack
    int res = K[number][W];
    //printf("%d\n", res);

    w = W;
    vector<int> ans;
    for (i = number; i > 0 && res > 0; i--)
    {

        // either the result comes from the top
        // (K[i-1][w]) or from (val[i-1] + K[i-1]
        // [w-wt[i-1]]) as in Knapsack table. If
        // it comes from the latter one/ it means
        // the item is included.
        if (res == K[i - 1][w])
            continue;
        else
        {

            // This item is included.

            ans.push_back(myitem.index[i - 1]);

            // Since this weight is included its
            // value is deducted
            res = res - myitem.val[i - 1];
            w = w - myitem.wt[i - 1];
        }
    }
    for (int j = ans.size()-1; j >=0; j--)
    {
        printf("%d ", ans[j]);
    }
}

// Driver code
int main()
{
    int t;
    cin >> t;
    for (int testCase = 1; testCase <= t; testCase++)
    {
        Items current;
        int m, n;
        int number = 0;
        cin >> m >> n;
        for (int i = 0; i < n; i++)
        {
            int p, l, s;
            cin >> p >> l >> s;
            for (int j = 0; j < p; j++)
            {
                current.val.push_back(s);
                current.wt.push_back(l);
                current.index.push_back(i + 1);
            }
            number += p;
        }
        cout << "Case #" << testCase << ": ";
        printknapSack(m, current, number);
        cout << endl;
    }
    return 0;
}