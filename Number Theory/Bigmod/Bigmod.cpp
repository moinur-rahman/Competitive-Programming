#include<bits/stdc++.h>
using namespace std;

typedef long long int li;
typedef long long ll;

#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)

ll bigMod(ll a,ll b,ll M)
{
    if(b==0) return 1%M;

    ll x = bigMod(a,b/2,M);

    x = ( x * x ) % M;

    if(b % 2 == 1) x = (x * a) % M;

    return x;
}

int main()
{
    int a,b,M;

    cin>>a>>b>>M;

    cout<<bigMod(a,b,M)<<endl;

}
