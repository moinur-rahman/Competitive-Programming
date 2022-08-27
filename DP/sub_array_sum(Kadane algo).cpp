#include<bits/stdc++.h>
using namespace std;
         
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> Pi;
typedef map<ll,ll> mi;
         
template<class T> T nrem(T x,T y){return ((x%y)+y)%y;}
         
#define For(i,a,n) for(int i=a;i<n;++i)
#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)
#define Forl0(i,n) for(ll i=0;i<n;++i)
#define Forl1(i,n) for(ll i=1;i<=n;++i)
#define fi freopen("input.txt","r",stdin);
#define fo freopen("output.txt","w",stdout);
#define pb push_back
#define mp make_pair
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define cs 2000005
#define pi acos(-1)
#define INF (int)INFINITY
void in()
    {
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
    }

int kadane(int a[],int n)
{
    int meh=0,msf=INT_MIN;

   for(int i=0;i<n;++i)
    {meh = meh + a[i];
    if(meh<a[i])
    meh=a[i];
    if(msf<meh)
    msf=meh;
    }

    return msf;
}

int main()
{  IOS
    in();
    

}