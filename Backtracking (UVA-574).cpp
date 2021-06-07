#include <bits/stdc++.h>

using namespace std;

const int N=15,oo=0x3f3f3f3f;
int n,arr[N],mem[N][N];

int solve (int i,int prev)
{
    if(i==n)
    {
        return 0;
    }
    if(mem[i][prev]!=-1)
    {
        return mem[i][prev];
    }
    int op1=solve(i+1,prev);
    int op2=-1;
    if(arr[i]>prev)
    {
        op2=solve(i+1,arr[i])+1;
    }
    return mem[i][prev]=max(op1,op2);
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    memset(mem,-1,sizeof mem);
    printf("%d\n",solve(0,0));
    return 0;
}