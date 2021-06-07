#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N=1005;
string a,b;
int mem[N][N];
int solve(int i,int j)
{
    if(i==a.size()||j==b.size())
    {
        return 0;
    }
    if(mem[i][j]!=-1)
    {
        return mem[i][j];
    }
    if(a[i]==b[j])
    {
        return mem[i][j]=solve(i+1,j+1)+1;
    }
    int op1=solve(i+1,j);
    int op2=solve(i,j+1);
    return mem[i][j]=max(op1,op2);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(mem,-1,sizeof mem);
        cin>>a>>b;
        cout<<solve(0,0)<<endl;
    }
    return 0;
}
