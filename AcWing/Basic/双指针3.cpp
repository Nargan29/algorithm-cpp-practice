#include <iostream>
using namespace std;
const int N=100010;
int n,m;
int a[N],b[N];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<m;j++) cin>>b[j];

    int j=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[j]) i++;j++;
        while(j<m&&b[j]!=a[i]) j++;
        
    }
    if(a[n-1]==b[j]) cout<<"Y";
    else cout<<"N";
        return 0;

}