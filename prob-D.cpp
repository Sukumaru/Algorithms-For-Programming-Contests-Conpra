#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class IntSet
{
public:
    int val[5];
    int size = 5;
    void Greater(IntSet &myIntSet)
    {
        sort(myIntSet.val, myIntSet.val + 5, greater<int>());
    }
};

bool test(const IntSet &i, const IntSet &j)
{
    if (i.val[0] != j.val[0])
    {
        return (i.val[0] > j.val[0]);
    }
    if (i.val[1] != j.val[1])
    {
        return (i.val[1] > j.val[1]);
    }
    if (i.val[2] != j.val[2])
    {
        return (i.val[2] > j.val[2]);
    }
    if (i.val[3] != j.val[3])
    {
        return (i.val[3] > j.val[3]);
    }
    if (i.val[4] != j.val[4])
    {
        return (i.val[4] > j.val[4]);
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int NoC;
    cin >> NoC;

    for (int i = 0; i < NoC; ++i)
    {
        std::cout << "Case #" << i + 1 << ":\n";
        int NoT;
        cin >> NoT;
        vector<IntSet> teams;
        teams.resize(NoT);
        vector<IntSet>::iterator it = teams.begin();
        while (it != teams.end())
        {
            for (unsigned int j = 0; j < 5; j++)
            {
                cin >> it->val[j];
            }
            it->Greater(*it);
            it++;
        }
        sort(teams.begin(), teams.end(), test);
        vector<IntSet>::iterator newit = teams.begin();
        while (newit != teams.end())
        {
            for (unsigned int j = 0; j < 5; j++)
            {
                cout << newit->val[j] << " ";
            }
            cout << endl;
            newit++;
        }
        teams.clear();
    }
    return 0;
}
