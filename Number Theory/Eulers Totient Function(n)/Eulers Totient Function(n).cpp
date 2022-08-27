#include<bits/stdc++.h>
using namespace std;

typedef long long int li;

#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)


int phi(int n)
{
    int ret=n;

    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {   
                n/=i;
            }
          
            ret -= ret/i;
        }
    }

    if(n>1)
    {   
        ret -= ret/n;
    }

    return ret;
}

int main()
{   int a;
    cin>>a;
    cout<<phi(a)<<endl;
}
