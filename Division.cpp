#include <iostream>
using namespace std;
int main()
{
    //gcd division
    int a,b,r;
    cout<<"Enter Your Numbers: "<<endl;
    cin>>a>>b;
    while(b != 0)
    {
        r= a%b;
        a=b;
        b=r;
    }
    cout<<"the gcd is: "<<a<<endl;
    return 0;
}