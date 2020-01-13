#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

struct Line
{
    vector<int> num;
    vector<string> op;
};
int getNum(string mystring, unsigned int pos, unsigned int length)
{
    return (atoi(mystring.substr(pos - length, pos).c_str()));
}
void read(string mystring, Line &myline)
{
    unsigned int pos = 0;

    while (pos < mystring.length())
    {
        unsigned int length = 0;
        while (isdigit(mystring[pos]))
        {
            length++;
            pos++;
        }
        myline.num.push_back(getNum(mystring, pos, length));
        if (mystring.substr(pos, 4).compare("plus") == 0)
        {
            myline.op.push_back("plus");
            pos += 4;
        }
        else if (mystring.substr(pos, 5).compare("minus") == 0)
        {
            myline.op.push_back("minus");
            pos += 5;
        }
        else if (mystring.substr(pos, 5).compare("times") == 0)
        {
            myline.op.push_back("times");
            pos += 5;
        }
        else if (mystring.substr(pos, 12).compare("tothepowerof") == 0)
        {
            myline.op.push_back("tothepowerof");
            pos += 12;
        }
    }
}
int step_calc(string op, int a, int b)
{
    if (op.compare("plus") == 0)
    {
        return a + b;
    }
    else if (op.compare("minus") == 0)
    {
        return a - b;
    }
    else if (op.compare("times") == 0)
    {
        return a * b;
    }
    else if (op.compare("tothepowerof") == 0)
    {
        return pow(a,b);
    }
    else
    {
        return 0;
    }
}
int calc(Line myline)
{
    int ans = *myline.num.begin();
    vector<int>::iterator it = myline.num.begin() + 1;
    vector<string>::iterator it2 = myline.op.begin();
    while (it != myline.num.end())
    {
        ans = step_calc(*it2, ans, *it);
        it++;
        it2++;
    }
    myline.num.clear();
	myline.op.clear();
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int NoC;
    cin >> NoC;
    for (int i = 0; i < NoC; ++i)
    {
        Line myline;
        string mystring;
        cin >> mystring;
        read(mystring, myline);
        cout << "Case #" << i + 1 << ": " << calc(myline) << endl;
    }
    return 0;
}