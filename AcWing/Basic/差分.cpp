#include <iostream>
using namespace std;

const int N = 100010; //数组最大长度，1e5+10
int n, m;
int a[N], b[N];  // a原数组，b差分数组

//差分核心函数：区间[l,r]全部加上c
void insert(int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    cin>>n>>m; //读入n数组长度，m操作次数
    
    //读原始数组a[1~n]，这里习惯下标从1开始，差分更方便不用处理0边界
    for (int i = 1; i <= n; i ++ ) cin>>a[i];
    
    //初始化差分数组：a[i]相当于对区间[i,i]加上a[i]
    for (int i = 1; i <= n; i ++ ) insert(i, i, a[i]);
    
    //m次区间加操作
    while (m -- )
    {
        int l, r, c;
       cin>>l>>r>>c;
        insert(l, r, c);
    }
    
    //对差分数组求前缀和，还原出修改后的结果数组
    for (int i = 1; i <= n; i ++ ) b[i] += b[i - 1];
    
    //输出最终数组
    for (int i = 1; i <= n; i ++ ) cout<<b[i];
    
    return 0;
}
