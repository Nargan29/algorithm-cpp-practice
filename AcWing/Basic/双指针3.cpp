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

    int j=0,i=0;
    while(i<n&&j<m)
    {
        if(a[i]==b[j]) i++;
        j++;
    }
    if(i==n) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    

}