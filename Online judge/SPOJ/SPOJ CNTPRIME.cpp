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
	      freopen("output.txt", "w", stdout);
	         #endif
}


bool marked[cs*10];
void sieve(int n) {

  for (int i = 3; i * i <= n; i += 2) {

    if (marked[i] == false)// i is a prime
    {
      for (int j = i * i; j <= n; j += i + i)/// 2 ar multiple gula drkar nai tai j+=i+i hoise
      {                                      ///ar i*i hoise karon i+i ar jnno ja hoito agei muche gese
        marked[j] = true;
      }
    }
  }
}

bool isPrime(int n) {

  if (n < 2) return false;

  if (n == 2) return true;

  if (n % 2 == 0) return false;

  return marked[n] == false;
}


int arr[cs];
struct info
{
    ll prop,sum;
}tree[cs*2];

void init(int node,int b,int e)
{
    if(b==e)
    {  
		if(isPrime(arr[b]))
        tree[node].sum=1;
		else tree[node].sum=0;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
}

void refresh(int node,int b,int e)
{
  if(tree[node].prop)
  {
    if(isPrime(tree[node].prop))
    tree[node].sum=e-b+1;
    else
    tree[node].sum=0;

  if(b!=e)
  {
    tree[node*2].prop=tree[node].prop;
   tree[node*2+1].prop=tree[node].prop;
  }
   tree[node].prop=0;
  }

}

int query(int node,int b,int e,int i,int j)
{
    if(i>e||j<b)
        return 0;
    
    refresh(node,b,e);
    if(b>=i&&e<=j)
        return tree[node].sum;
    
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}



void update(int node,int b,int e,int i,int j,int x)
{
    if(i>e||j<b)
        {
         refresh(node,b,e);
          return;
        }
    if(b>=i&&e<=j)
    {   
        tree[node].prop=x;
        refresh(node,b,e);
        return;
    }
    refresh(node,b,e);
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum;
}

int main() 
{ IOS
   
  sieve(1000005);
   int t;
   cin>>t;
  For0(k,t)
   {
     cout<<"Case "<<k+1<<":"<<endl;
    memset(arr,0,sizeof arr);
    memset(tree,0, sizeof tree);
   int n,q;
   cin>>n>>q;
   
   For1(i,n)
   cin>>arr[i];
   

   init(1,1,n);
   

   int a,x,y,v;

   while(q--)
   {
	   cin>>a;
	   if(a==0)
	   {
		   cin>>x>>y>>v;
		   update(1,1,n,x,y,v);
	   }

	   else
	   {  
		   cin>>x>>y;
		   cout<<query(1,1,n,x,y)<<endl;
	   }
	
   }
   }
   
    
}
