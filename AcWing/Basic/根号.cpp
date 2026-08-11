#include <iostream>
using namespace std;
int main()
{
    double x;
    cin>>x;
    double l=0.0,r=100;  //r不能等于x，当x<1时就会报错
    while(r-l>1e-8)
    {
        double mid=(l+r)/2;
        if(mid*mid>=x) r=mid;
        else l=mid;
    }
    cout<<l<<endl;
}