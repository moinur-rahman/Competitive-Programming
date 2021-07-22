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
#define pi acos(-1)
#define INF (int)INFINITY
void in()
{
        	#ifndef ONLINE_JUDGE
    		freopen("input.txt", "r", stdin);
	    	//freopen("output.txt", "w", stdout);
	         #endif
}
vector<int>v[105];
int indeg[105],outdeg[105];
int n,m;
void topological_sort()
{   int i,j,deg;
    for(i=0;i<n;++i)
    {
     for(j=1;j<=n;++j)
     if(indeg[j]==0)
     break;
     
      deg=j;
      cout<<deg<<" ";
      indeg[deg]=-1;
      
      for(j=0;j<v[deg].size();++j)
      indeg[v[deg][j]]--;
    }
}

int main()
{   IOS
    int x,y;
    while(1)
    {
        cin>>n>>m;
        if(m==0&&n==0)
        return 0;

        memset(v,0,sizeof v);
        memset(indeg,0,sizeof indeg);
        for(int i=0;i<m;++i)
        {
            cin>>x>>y;
            v[x].push_back(y);
            //outdeg[x]++;
            indeg[y]++;
        }
        topological_sort();
		cout<<endl;
    }
}