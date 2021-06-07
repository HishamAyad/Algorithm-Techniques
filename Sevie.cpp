#include <iostream>
#include<vector>
using namespace std;
vector<int>v;
const int N=3005;
int n;
bool prime[N];
void seive(int n)
{
    fill(prime,prime+N,true);
    prime[0]=prime[1]=false;
    for(int p=2;p<=n;p++)
    {
        if(prime[p])
        {
            for(int m=p*2;m<=n;m+=p)
            {
                prime[m]=false;
            }
            v.push_back(p);
        }
    }
}
int main()
{
    cin>>n;
    seive(n);
    for(auto it : v)
    {
       cout<<it<<" ";
    }
    puts("");
    return 0;
}
