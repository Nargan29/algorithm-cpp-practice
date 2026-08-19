#include <iostream>
using namespace std;
const int N=100010;
int n,m,x;
int A[N],B[N];
int main()
{
    cin>>n>>m>>x;
    for(int i=0;i<n;i++) cin>>A[i];
    for(int j=0;j<m;j++) cin>>B[j];
    int j=m-1;   //j在外面不然超时
    for(int i=0;i<n;i++)
    {
        while(j>=0&&A[i]+B[j]>x) j--;    //j>0,不然一直走，
        if(A[i]+B[j]==x) cout<<i<<" "<<j<<endl;
    }
    return 0;
}