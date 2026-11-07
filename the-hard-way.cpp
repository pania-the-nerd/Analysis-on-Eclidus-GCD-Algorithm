#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a, b;
    vector<int> r;
    vector<int> m;
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        if (a % i == 0)
        {
            r.push_back(i);
        }
    }
    for (int i = 1; i <= b; i++)
    {
        if (b % i == 0)
        {
            m.push_back(i);
        }
    }
    // for finding the max ---->
    int gcd = 1;
    for (int i = 0; i < r.size(); i++)
    {
        for (int j = 0; j < m.size(); j++)
        {
            if (r[i] == m[j])
            {
                if (r[i] > gcd)
                {
                    gcd = r[i];
                }
            }
        }
    }
    cout << "the gcd is: " << gcd;
    return 0;
}