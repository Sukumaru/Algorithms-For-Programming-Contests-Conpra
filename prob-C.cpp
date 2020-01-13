#include <iostream>
#include <cstdlib>

using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    int num;
    cin >> num;
    unsigned long long int c(299792458);

    for (int i = 0; i < num; i++)
    {
        unsigned int m;
        std::cin >> m;
        std::cout << "Case #" << i + 1 << ": " << m * c * c << "\n";
    }

    return 0;
}