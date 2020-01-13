#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    int t = 1;
    int num;
  
    cin >> t >> num;
    string mystr[num];
    string myAns[num];
    cin.get();  
    for (int i = 0; i < num; i++)
    {
        getline(cin, mystr[i]);
    }
    for (int i = 0; i < num; i++)
    {
        unsigned int pos = 0;
        string ans;
        while (pos < mystr[i].size())
        {
            if (mystr[i].substr(pos, 5).compare("enten") == 0)
            {
                ans.append("ierende");
                pos = pos + 5;
            }
            else if (mystr[i].substr(pos, 5).compare("entin") == 0)
            {
                ans.append("ierende");
                pos = pos + 5;
            }
            else if (mystr[i].substr(pos, 3).compare("ent") == 0)
            {
                ans.append("ierender");
                pos = pos + 3;
            }
            else
            {
                ans.append(mystr[i].substr(pos, 1));
                pos++;
            }
        }
        myAns[i] = ans;
    }
    cout << "Case #" << t << ":" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << myAns[i] << endl;
    }
    return 0;
}
