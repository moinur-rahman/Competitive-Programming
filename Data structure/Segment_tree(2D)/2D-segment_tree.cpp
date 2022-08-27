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
#define cs 1005
#define pi acos(-1)
#define INF (int)INFINITY
void in()
{
     #ifndef ONLINE_JUDGE
         freopen("input.txt", "r", stdin);
          freopen("output.txt", "w", stdout);
     #endif
}
int arr[cs][cs];
int tree[3*cs][3*cs];

int finaltree[3*cs][3*cs];
int sz,r,c;
void init(int row,int col,int b,int e)
{
    if(b==e)
    {
        tree[row][col]=arr[row][b];
        return;
    }
    int left=col*2;
    int right=col*2+1;
    int mid=(b+e)/2;
    init(row,left,b,mid);
    init(row,right,mid+1,e);
    tree[row][col]=tree[row][left]+tree[row][right];
}

void final_init(int row,int b,int e)
{
    if(b==e)
    {
        for(int i=1;i<=sz;++i)
        finaltree[row][i]=tree[b][i];
        return;
    }
  
        int left=row*2;
        int right=row*2+1;
        int mid=(b+e)/2;
        final_init(left,b,mid);
        final_init(right,mid+1,e);
        
        for(int i=1;i<=sz;++i)
        finaltree[row][i] = finaltree[left][i] + finaltree[right][i]; 
}

void build(int row,int b,int e)
{   
    for(int i=1;i<=row;i++)
    init(i,1,b,e);

    final_init(1,b,e);
}

int final_query(int row,int col,int b,int e,int y1,int y2)
{
    if(y1>e||y2<b)
    return 0;

    if(b>=y1&&e<=y2)
    {
        return finaltree[row][col];
    }
    int mid=(b+e)/2;

    int left = col *2;
    int right = col*2+1;

    int p1=final_query(row,left,b,mid,y1,y2);  
    int p2=final_query(row,right,mid+1,e,y1,y2);

    return p1+p2;
}
int query(int node,int b,int e,int x1,int y1,int x2,int y2)
{
    if(x1>e||x2<b)
        return 0;
    if(b>=x1&&e<=x2)
        return (final_query(node,1,1,c,y1,y2));
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    int p1=query(left,b,mid,x1,y1,x2,y2);

    int p2=query(right,mid+1,e,x1,y1,x2,y2);
    return p1+p2;
}

void final_update(int row,int col,int b,int e,int y,int newvalue)
{
    if(y>e||y<b)
        return;
    if(b>=y&&e<=y)
    {
        finaltree[row][col]=newvalue;
        return;
    }
    int mid=(b+e)/2;
    int left=col*2;
    int right=col*2+1;

    final_update(row,left,b,mid,y,newvalue);
    final_update(row,right,mid+1,e,y,newvalue);

    finaltree[row][col]=finaltree[row][left]+finaltree[row][right];
}

void update(int node,int b,int e,int x,int y,int newvalue)
{
    if(x>e||x<b)
        return;
    if(b>=x&&e<=x)
    {
       final_update(node,1,1,c,y,newvalue);
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,x,y,newvalue);
    update(right,mid+1,e,x,y,newvalue);

    for(int i=1;i<=sz;++i)
    finaltree[node][i]=finaltree[left][i]+finaltree[right][i];
}
int main()
{ 
    in();

  cin>>r>>c;
  sz=r*2;  //size
  
   For1(i,r)
   For1(j,c)
   {
       cin>>arr[i][j];
   }
  for(int i=1;i<=r;++i)
  init(i,1,1,c);
  
  final_init(1,1,r);
  
  for(int i=1;i<=9;i++)
  {for(int j=1;j<=10;++j)
  {
      cout<<finaltree[i][j]<<" ";
  }
  cout<<endl;
  }
  update(1,1,r,2,2,4);  //1 theke start b<=row<=e
  cout<<query(1,1,r,2,2,4,3);
}