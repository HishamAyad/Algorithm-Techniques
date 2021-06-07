#include <iostream>
#include <cstring>

using namespace std;

const int N=2005;
int bag,value[N],siz[N],n,mem[N][N];

int solve (int i,int s)
{
    if(i==n || s==0 )
    {
        return 0;
    }
    if(mem[i][s]!=-1)
    {
        return mem[i][s];
    }
    int op1=solve(i+1,s);
    int op2=-1;
    if(s-siz[i]>=0)
    {
        op2=solve(i+1,s-siz[i]) +value[i];
    }
    return mem[i][s]=max(op1,op2);
}

int main()
{
    cin>>bag>>n;
    for(int i=0;i<n;i++)
    {
        cin>>siz[i]>>value[i];
    }
    memset(mem,-1,sizeof mem);
    cout<<solve(0,bag)<<endl;
    return 0;
}
