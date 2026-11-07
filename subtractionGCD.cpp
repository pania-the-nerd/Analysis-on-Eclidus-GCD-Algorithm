#include <iostream>
using namespace std;
int main()
{
    //gcd subtraction
    int a,b;
    cin>>a>>b;
    while(a != b)
    {
        if(a>b)
        {
            a=b-a;
        }
        else
        {
            b=b-a;
        }
    }
    cout<<"the gcd is: "<<a<<endl;
    return 0;
}