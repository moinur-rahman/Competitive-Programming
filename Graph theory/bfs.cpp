#include<bits/stdc++.h>
using namespace std;

typedef long long int li;
typedef pair<int,int> PII;

#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)

#define mx 10000005

vector<int> adj[100];
int visited[100];

void bfs(int s,int n)
{
    queue <int> Q;
    Q.push(s);

    visited[s]=1;

    while(!Q.empty())
    {
        int u=Q.front();
        cout<<u<<endl;
        Q.pop();

        for(int i=0;i<adj[u].size();i++)
            if(visited[adj[u][i]]==0)
        {
            int v=adj[u][i];
            visited[v]=1;
            Q.push(v);
        }
    }
}

int main()
{
   int n,x,y;
   cin>>n;
   For0(i,n)
   {  cin>>x>>y;
       adj[x].push_back(y);
   //    adj[y].push_back(x);
   }
   bfs(1,10);
}



