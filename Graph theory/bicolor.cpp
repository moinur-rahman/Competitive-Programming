#include<bits/stdc++.h>
using namespace std;

typedef long long int li;

#define For(i,a,n) for(int i=a;i<n;++i)
#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)
#define fi freopen("input.txt","r",stdin);
#define fo freopen("output.txt","w",stdout);
#define pb push_back
#define mp make_pair
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define mx 100005


#define white 1
#define red 2
#define blue 3
vector <int> adj[1005];
int visited[mx];
int color[mx];

bool bicolor(int s,int n)
{
    queue<int>Q;
    Q.push(s);
    for(int i=0;i<=n;i++)
        color[i]=white;
    color[s]=red;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        for(int i=0;i<adj[u].size();i++)
        {  int v=adj[u][i];
            if(color[v]==white)
        {

            if(color[u]==red)
            color[v]=blue;
            else
            color[v]=red;
            Q.push(v);

        }
        //cout<<v<<endl;
        if(color[u]==color[v])
            return false;
        }
    }
    return true;
}

int main()
{
//#ifndef ONLINE_JUDGE
fi;
//fo;
//#endif

IOS;

 int n,x,y;
   cin>>n;
   For0(i,n)
   {  cin>>x>>y;
       adj[x].push_back(y);
       adj[y].push_back(x);
   }
   if(bicolor(1,5))
    cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
}

/*
7
1 2
1 3
3 4
3 5
2 5
2 4
4 5
*/
