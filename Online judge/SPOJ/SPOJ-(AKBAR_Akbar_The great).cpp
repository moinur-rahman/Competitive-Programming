#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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
#define cs 1000005
#define pi acos(-1)
#define INF (int)INFINITY
void in()
{
     #ifndef ONLINE_JUDGE
         freopen("input.txt", "r", stdin);
          freopen("output.txt", "w", stdout);
     #endif
}

int main() 
{  in();
   
   int q;
   cin>>q;

   while (q--)
   {   
    vector<int> adj[cs];
    vector<int>done(cs,0);
    vector<int>level(cs,0);
    vector<int>visited(cs,0);
      int n,r,m;
      cin>>n>>r>>m;
      
      while (r--)
      {
       int a,b;
       cin>>a>>b;
       adj[a].pb(b);
       adj[b].pb(a);
      }
      
      int f=0;
      
      while (m--)
      {
       int a,b;
       cin>>a>>b;
       queue <int> Q;
    Q.push(a);
     
    visited[a]=1;
    level[a]=0;

    while(!Q.empty())
    {
        int u=Q.front();
      //  cout<<u<<endl;
        Q.pop();
        
        if(level[u]>b)
        break;
        
        if(done[u]==1)
        {
            f=1;
            break;
        }
        
        for(int v:adj[u])
            if(visited[v]==0)
        {
            level[v]=level[u]+1;
              if(level[v]<=b)
               visited[v]=1;           
            Q.push(v);
        }
        done[u]=1;
    }

      }
      
      for(int i=1;i<=n;++i)
      {
        // cout<<done[i]<<" ";
        if(done[i]==0)
      f=1;
      }
     // cout<<endl;
        if(f)
        cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
   }
   
} 