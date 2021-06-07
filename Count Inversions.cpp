#include <iostream>

using namespace std;
/*
    Count Inversions :
    we want to write a program to count the in inversions
    Inversion : if Arr[i]>Arr[j] where i<j

    An application for this problem (collaborative filtering)
*/

int brute_force(int arr[],int N) //O(N^2)
{
    int ans=0;
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(arr[i]>arr[j])
            {
                ans++;
            }
        }
    }
    return ans;
}
int Merge_and_count (int a[],int sizea,int b[],int sizeb) //O(n)
{
    int idxa=0,idxb=0,idxc=0,ans=0;
    int c[sizea+sizeb];
    while(idxa<sizea&&idxb<sizeb)
    {
        if(a[idxa]<b[idxb])
        {
            c[idxc++]=a[idxa++];
        }
        else
        {
            c[idxc++]=b[idxb++];
            ans+=sizea-idxa;
        }
    }
    while(idxa<sizea)
    {
        c[idxc++]=a[idxa++];
    }
    while(idxb<sizeb)
    {
        c[idxc++]=b[idxb++];
    }
    copy(c,c+sizea+sizeb,a);
    return ans;
}
int sort_and_count(int* begin,int * end)
{
    int sz = end - begin,ans=0;
      if (sz <= 1) {
        return 0;
      }
      int mid = sz/2;
      ans +=sort_and_count(begin, begin+mid);
      ans +=sort_and_count(begin+mid, end);
      ans +=Merge_and_count(begin, mid, begin+mid, sz-mid);
      return ans;
}
int main()
{
    int arr[6]={6,5,4,3,2,1};
    cout<<sort_and_count(arr,arr+6);
    //cout<<brute_force(arr,6);
    return 0;
}

