#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        string name;
        cin >> name;
        cout << " Case #" << i + 1 << ": Hello " << name << "!" << endl;
    }
    return 0;
}