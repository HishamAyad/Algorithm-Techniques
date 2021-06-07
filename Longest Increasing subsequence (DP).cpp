#include <bits/stdc++.h>

using namespace std;
#define ll long long

typedef vector<vector<int>> vvi;

void BabageDiffrenceEngine(vvi &a,int m)
{
    while(a.back().size()>1)
    {
        vector<int> b,&p=a.back();
        for(int i=0;i<p.size()-1;++i)
        {
            b.push_back(p[i+1]-p[i]);
        }
        a.push_back(b);
    }
    a.back().resize(m+1,a.back().back());
    for(int i=a.size()-1,j=1;i>0;--i,++j)
    {
        vector<int>&curr=a[i],&prev=a[i-1];
        for(int k=0;k<m;++k)
        {
            prev.emplace_back(curr[k+j]+prev[k+j]);
        }
    }
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        vvi ans;
        vector<int> arr(n);
        for(int i=0;i<n;++i)
        {
            scanf("%d",&arr[i]);
        }
        ans.push_back(arr);
        BabageDiffrenceEngine(ans,m);
        for(int i=n;i<ans[0].size();++i)
        {
            printf("%d ",ans[0][i]);
        }
        printf("\n");
    }

    return 0;
}