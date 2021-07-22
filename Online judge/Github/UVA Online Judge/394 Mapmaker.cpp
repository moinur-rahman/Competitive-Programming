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

/*
e.g.
TWO 2000 4 3 1 4 0 5 5 10
TWO base = 2000 size = 4 D = 3
D0=(1, 4), D1=(0, 5), D2=(5, 10)
Di = (Di_L, Di_U)
    
C[2] = size = 4
C[1] = C[2] * (10-5+1) = 24
C[0] = C[1] * (5-0+1) = 144

TWO[3, 3, 9] = base + (3-D0_L)*C[0] + (3-D1_L)*C[1] + (9-D2_L)*C[2]
= 2000 + (3-1)*144 + (3-0)*24 + (9-5)*4 = 2376
*/
struct  arr
{   
	int size;
	int base;
	int dimension;
	pair<int,int>d[11];
	int c[11];
};


int main(void) {
	fi fo
    int n,r;
	cin>>n>>r;
	 
	arr tmp;
	string s;
	map<string,arr>m;

	for(int i=0;i<n;++i)
	{   
		cin>>s>>tmp.base>>tmp.size>>tmp.dimension;
		for(int j=0;j<tmp.dimension;++j)
		cin>>tmp.d[j].first>>tmp.d[j].second;
        
        tmp.c[tmp.dimension-1]=tmp.size;
		for(int j=tmp.dimension-2;j>=0;--j)
		tmp.c[j]=tmp.c[j+1]*(tmp.d[j+1].second-tmp.d[j+1].first+1);
	    
		m[s]=tmp;
	}

	for(int i=0;i<r;++i)
	{   
		cin>>s;
		int sum=m[s].base,w,j;
		cout<<s<<"[";
		for(j=0;j<m[s].dimension-1;++j)
        {   
			cin>>w;
			cout<<w<<", ";
			sum+=m[s].c[j]*(w-m[s].d[j].first);
		     
		}
		cin>>w;
		sum+=m[s].c[j]*(w-m[s].d[j].first);
		cout<<w<<"] = "<<sum<<endl;
		
	}
}