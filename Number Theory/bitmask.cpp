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
#define cs 500005
#define pi acos(-1)
#define INF (int)INFINITY
void in()
    {
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
    }

void set_(ull &x,ull n)
{
    x=x|(1LL<<(n-1));
}

bool check(ull x,ull n)
{
    return x&(1LL<<(n-1));
}

void unset(ull x,ull n)
{
    if(check(x,n))
    x=x^(1LL<<(n-1));
}



int main()
{  IOS
    //in();

    ull x=6;
    
    set_(x,0);
    
    cout<<x<<endl;
}