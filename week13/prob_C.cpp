#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
using namespace std;

struct circle
{
    long double x;
    long double y;
    long double r;
};

circle get_enclosing_circle(circle A, circle B)
{
    circle ans;

    long double D = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
    if (D + A.r <= B.r)
    {
        return B;
    }
    else if (D + B.r <= A.r)
    {
        return A;
    }
    else
    {
        ans.r = (D + A.r + B.r) / 2;
        long double theta = atan((A.y - B.y) / (A.x - B.x));
        if (A.x == B.x)
        {
            ans.x = A.x;
            if(A.y >= B.y){
                ans.y = (A.y+A.r+B.y-B.r)/2;
            }
            else{
                ans.y = (A.y-A.r+B.y+B.r)/2;
            }
        }
        else if (A.y == B.y)
        {
            ans.y = A.y;
            if(A.x >= B.x){
                ans.x = (A.x+A.r+B.x-B.r)/2;
            }
            else{
                ans.x = (A.x-A.r+B.x+B.r)/2;
            }
        }
        else if (A.x < B.x && A.y < B.y)
        {
            ans.x = ((A.x - A.r * cos(theta)) + (B.x + B.r * cos(theta))) / 2;
            ans.y = ((A.y - A.r * sin(theta)) + (B.y + B.r * sin(theta))) / 2;
        }
        else if (A.x > B.x && A.y > B.y)
        {
            ans.x = ((A.x + A.r * cos(theta)) + (B.x - B.r * cos(theta))) / 2;
            ans.y = ((A.y + A.r * sin(theta)) + (B.y - B.r * sin(theta))) / 2;
        }
        else if (A.x < B.x && A.y > B.y)
        {
            ans.x = ((A.x - A.r * cos(theta)) + (B.x + B.r * cos(theta))) / 2;
            ans.y = ((A.y - A.r * sin(theta)) + (B.y + B.r * sin(theta))) / 2;
        }
        else if (A.x > B.x && A.y < B.y)
        {
            ans.x = ((A.x + A.r * cos(theta)) + (B.x - B.r * cos(theta))) / 2;
            ans.y = ((A.y + A.r * sin(theta)) + (B.y - B.r * sin(theta))) / 2;
        }
        return ans;
    }
}

int main()
{
    int t;
    cin >> t;
    for (int testCase = 1; testCase <= t; testCase++)
    {
        int n;
        cin >> n;
        vector<circle> mycircles;
        for (int i = 0; i < n; i++)
        {
            long double x, y, r;
            cin >> x >> y >> r;
            circle current = {x, y, r};
            mycircles.push_back(current);
        }
        int index = 1;
        circle big = mycircles[0];
        while (index != n)
        {
            big = get_enclosing_circle(big, mycircles[index]);
            index++;
        }
        cout << "Case #" << testCase << ": " << big.r << endl;
    }
}