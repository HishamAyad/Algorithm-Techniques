#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
#define ll long long
int coins[5]={1,5,10,25,50};

ll mem[5][7500];
ll solve (int i,ll rem)
{
    if(rem==0)
    {
        return 1;
    }
    if(i==5)
    {
        return 0;
    }
    if(mem[i][rem]!=-1)
    {
        return mem[i][rem];
    }
    ll op1 =solve(i+1,rem);
    ll op2 =0;
    if(coins[i]<=rem)
    {
        op2=solve(i,rem-coins[i]);
    }
    return mem[i][rem]=op1+op2;
}

int main()
{

    ll n;
    memset(mem,-1,sizeof mem);
    while(~scanf("%lld",&n))
    {
        printf("%lld\n",solve(0,n));
    }
    return 0;
}
