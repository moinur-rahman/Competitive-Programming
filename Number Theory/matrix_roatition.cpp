#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> Pi;
typedef map<ll,ll> mi;
 
template<class T> T nrem(T x,T y){return ((x%y)+y)%y;}
const ll M=1e9+7;
ll mod(ll x){return ((x%M+M)%M);}
 
#define loop(i,a,b) for(int i=a;i<=b;++i)
#define rloop(i,a,b) for(int i=a;i>=b;--i)
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
#define cs 100005
#define pi acos(-1)
#define INF (int)INFINITY
 
void in()
    {
      #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
      #endif
    }

void rotate90Clockwise(int a[N][N])
{
 
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
 
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}

void solve()
{

}
int main()
{   in();
    IOS
    int t=1;
     cin>>t;
   while (t--)
    {
          solve();
    }
    
}