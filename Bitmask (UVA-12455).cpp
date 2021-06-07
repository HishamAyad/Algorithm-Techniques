#include <iostream>

using namespace std;

int arr[20];
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>k>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        bool flag =false;
        for(int i=0;i<(1<<n);i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                if((i>>j)&1)
                {
                    sum+=arr[j];
                }
            }
            if(sum==k)
            {
                flag=true;
                break;
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
