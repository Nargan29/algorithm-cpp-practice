#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII; //PII 是 pair<int,int>的简写，存一个区间 {左端点, 右端点}

const int N=100010;
int n,m;
vector<PII> segs;
void merge(vector<PII> &segs)
{
    vector<PII> res;    // 用来存放合并完成后的新区间
    sort(segs.begin(),segs.end());   // ① 排序：按照区间左端点从小到大排序
    int st=-2e9,ed=-2e9;
    for(auto seg:segs)    // ② 依次遍历每一个原始区间 seg
    {
        if(ed<seg.first)
        {
            if(st!=-2e9)
            res.push_back({st,ed});
            st=seg.first,ed=seg.second;   // 开启一段全新区间，更新 st ed 为当前 seg 的左右端点
        }
        else{    // 区间重叠/相接，合并！更新右端点为两者更大的值
            ed=max(ed,seg.second);
        }
    }
    // 循环结束后，最后一组 [st,ed] 还没放进 res，补上
    if(st!=-2e9)
        res.push_back({st,ed});

    segs=res;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        segs.push_back({l,r});   // 存入所有区间
    }
    merge(segs);
    cout<<segs.size()<<endl;
}