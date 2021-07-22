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

int id[cs],edge,node;
pair<int,pair<int,int> >p[cs];

void initialize()
{
    for(int i=0;i<cs;++i)
    id[i]=i;
}

int root(int x)
{
    while(id[x]!=x)
    {
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}

void union1(int x,int y)
{
    int p=root(x);
    int q=root(y);

    id[p]=id[q];
}

ll kruskal(pair<int,pair<int,int> > p[])
{
    int x,y;

    ll cost,mincost=0;

    for(int i=0;i<edge;++i)
    {
        x=p[i].second.first;

        y=p[i].second.second;

        cost=p[i].first;

        if(root(x)!=root(y))
        {
            mincost+=cost;
            union1(x,y);
        }
    } 
    return mincost;
}

int main()
{
int x,y;
ll weight,cost,mincost;
initialize();
cin>>node>>edge;
for(int i=0;i<edge;++i)
{
    cin>>x>>y>>weight;
    p[i]=mp(weight,mp(x,y));
}
sort(p,p+edge);

mincost=kruskal(p);

cout<<mincost<<endl;

return 0;
}