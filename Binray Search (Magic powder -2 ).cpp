#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N=100005;
ll n,k,need[N],have[N];
bool check (ll x)
{
    ll powder=k;
    for(int i=0;i<n;i++)
    {
        ll grams = x*need[i];
        if(have[i]<grams)
        {
            if(have[i]+powder<grams)
            {
                return false;
            }
            powder-=(grams-have[i]);
        }
    }
    return true;
}

ll binarysearch ()
{
    ll low=0,high=2000000000,mid;
    while(high-low>0)
    {
        mid=(low+high+1)/2;
        if(check(mid))
        {
            low=mid;
        }
        else
        {
            high=low-1;
        }
    }
    return low;
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>need[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>have[i];
    }
    cout<<binarysearch()<<endl;
    return 0;
}
