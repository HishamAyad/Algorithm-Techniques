#include <bits/stdc++.h>

using namespace std;
const int N =20;
int arr[N];
vector <int> ans;
vector <string> ans2;
bool flag ;
set <string> s;
void path (int lo, int hi, int t)
{
    if(lo>hi)
    {
        if(t==0)
        {
            string st="";
            for(auto i=0;i<ans.size()-1;i++)
            {
                st+=to_string(ans[i])+"+";
            }
            st+=to_string(ans[ans.size()-1]);
            if(!s.count(st))
            {
                s.insert(st);
                ans2.push_back(st);
            }
        }
        return ;
    }
    ans.push_back(arr[lo]);
    path(lo+1,hi,t-arr[lo]);
    ans.pop_back();
    path(lo+1,hi,t);
}

int main()
{
    int t,n;
    while(cin>>t>>n)
    {
        if(!t&&!n)
        {
            return 0;
        }
        ans.clear();
        ans2.clear();
        s.clear();
        flag=false;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<"Sums of "<<t<<":"<<endl;
        path(0,n-1,t);
        if(ans2.empty())
        {
            puts("NONE");
        }
        else
        {
            for(auto i: ans2)
            {
                cout<<i<<endl;
            }
        }
    }
    return 0;
}