///CUET_Knightwatch(17)

#include<bits/stdc++.h>
using namespace std;

typedef long long int li;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef map<ll,ll> mi;

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
#define cs 1000005
#define INF (int)INFINITY
//#ifndef ONLINE_JUDGE
//fi;
//fo;
//#endif

vector<ll> adj[cs];
bool visited[cs];
ll g=0;


void bfs(ll s,ll n,ll level)
{   ll l=0;
    queue <int> Q;
    Q.push(s);
    if(visited[s])
    g=1;
    visited[s]=1;

    while(!Q.empty())
    { if(l==level)
        return;  
        ll u=Q.front();
        //cout<<u<<endl;
        Q.pop();

        for(ll i=0;i<adj[u].size();i++)
            if(visited[adj[u][i]]==0)
        {
            ll v=adj[u][i];
            visited[v]=1;
            Q.push(v);
        }
        l++;
    }
}

int main ()
{
  IOS fi
  ll t;
 cin>>t;
  while(t--)
  {ll n,r,m,a,b,k;
  g=0;
  memset(visited,0,sizeof(visited));
  memset(adj,0,sizeof(adj));
  cin>>n>>r>>m;
  For0(i,r)
  {
   cin>>a>>b;
   adj[a].pb(b);
   adj[b].pb(a);
  }
  For0(i,m)
  {
    cin>>a>>b;
    bfs(a,n,b);
  }
  // For1(i,n)
  //dfs(i);

  if(g==0)
  cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  }
}
