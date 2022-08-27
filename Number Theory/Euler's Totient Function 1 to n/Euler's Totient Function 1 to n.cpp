#include<bits/stdc++.h>
using namespace std;

typedef long long int li;

#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)

int phi[100006],mark[100006];

void sievephi(int n)
{
    int i,j;
    /// initialization
    for(int i=1;i<=n;++i)
        phi[i]=i;

    phi[1]=1;
    mark[1]=1;

    for(int i=2;i<=n;i++)
    {
        if(!mark[i])
            for(j=i;j<=n;j+=i)
        {
            mark[j]=1;
            phi[j]=phi[j]/i*(i-1);
        }
    }
}

int main()
{
    int a;///finding the number from 1 to n
    cin>>a;
    sievephi(a);
    For1(i,a)
    cout<<phi[i]<<endl;
}
