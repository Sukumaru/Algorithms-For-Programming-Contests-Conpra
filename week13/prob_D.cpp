#include <iostream>

using namespace std;
int MAX = 10000000;
struct Line
{
    double k;
    double d;
    double value = 0; //parallel to y-axis
};

struct Point
{
    double x;
    double y;
};

Line getLine(Point A, Point B)
{
    Line myline;
    if (A.x != B.x)
    {
        myline.k = (A.y - B.y) / (A.x - B.x);
        myline.d = (A.x * B.y - A.y * B.x) / (A.x - B.x);
    }
    else
    {
        myline.k = MAX;
        myline.value = A.x;
    }
    return myline;
}

bool getcrossPoint(Line L1, Line L2, Point &ans)
{
    if (L1.k == L2.k)
    {
        return false;
    }
    else if (L1.value != 0)
    {
        ans.x = L1.value;
        ans.y = L1.value * L2.k + L2.d;
    }
    else if (L2.value != 0)
    {
        ans.x = L2.value;
        ans.y = L2.value * L1.k + L1.d;
    }
    else
    {
        ans.x = (L2.d - L1.d) / (L1.k - L2.k);
        ans.y = (L1.d * L2.k - L2.d * L1.k) / (L2.k - L1.k);
    }
    return true;
}

Line getPerpendicularLine(Line L1, Point P1)
{

    Line ans;
    if (L1.k == 0)
    {
        ans.k = MAX;
        ans.value = P1.x;
    }
    else if (L1.k == MAX)
    {
        ans.k = 0;
        ans.d = P1.y;
    }
    else
    {
        ans.k = -1 / (L1.k);
        ans.d = ans.k * P1.x + P1.y;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    for (int testCase = 1; testCase <= t; testCase++)
    {
        Point Lea;
        cin >> Lea.x >> Lea.y;
        Point Snowball;
        cin >> Snowball.x >> Snowball.y;
        Line Line1 = getLine(Lea, Snowball);
        Point MirrorA, MirrorB;
        cin >> MirrorA.x >> MirrorA.y >> MirrorB.x >> MirrorB.y;
        Line Mirror = getLine(MirrorA, MirrorB);
        Point Enemy;
        cin >> Enemy.x >> Enemy.y;
        Line Line2 = getPerpendicularLine(Mirror, Enemy);
        Point ans;
        getcrossPoint(Line1, Line2, ans);
        cout <<"Case #"<<testCase<<": "<< ans.x << " " << ans.y << endl;
        
    }
    return 0;
}