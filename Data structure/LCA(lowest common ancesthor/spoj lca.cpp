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
#define cs 100005
#define INF (int)INFINITY
//#ifndef ONLINE_JUDGE
//fi;
//fo;
//#endif

int L[cs];
int P[cs][22];
int T[cs];
vector<int> g[cs];

void dfs(int from,int u,int dep)
{
  T[u]=from;
  L[u]=dep;
  
  for(int i=0;i<g[u].size();++i)
  {
    int v=g[u][i];
    if(v==from)
    continue;
    dfs(u,v,dep+1);
  }
}

int lca_query(int N,int p,int q)
{
  int tmp,log,i;
  if (L[p]<L[q])
  swap(p,q);

  log = 1;

  while(1)
  {
    int next=log+1;
    if((1<<next)>L[p])
    break;
    log++;
  }

  for(i=log;i>=0;--i)
  {
    if(L[p]-(1<<i)>=L[q])
    p=P[p][i];
  }

  if(p==q)
  return p;

  for(i=log;i>=0;--i)
  if(P[p][i]!=-1&&P[p][i]!=P[q][i])
  p=P[p][i],q=P[q][i];

  return T[p];
}

void lca_init(int N)
{
  memset(P,-1,sizeof P);
  
  int i,j;
  for(int i=0;i<N;++i)
  P[i][0]=T[i];

  for(j=1;1<<j<N;++j)
    for(i=0;i<N;++i)
     if(P[i][j-1]!=-1)
     P[i][j]=P[P[i][j-1]][j-1];
}

int main(void) {
  int d;
  cin>>d;
  For0(k,d)
  {int n,m,a,b,c,q;
  cin>>n;
  
  
  For0(i,n)
  {
   cin>>m;
   For0(j,m)
   cin>>a,
   g[i+1].pb(a);
  }
  dfs(-1,1,0);
  lca_init(n+1);
  cin>>q;
  cout<<"Case "<<k+1<<": "<<endl;
  For0(i,q)
  {
  cin>>b>>c;
  cout<<lca_query(n+1,b,c)<<endl;
  }
  memset(L,0,sizeof L);
  memset(T,0,sizeof T);
  memset(g,0,sizeof g);
  }
}
