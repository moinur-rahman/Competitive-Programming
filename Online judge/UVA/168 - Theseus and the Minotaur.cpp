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

vector<int>v[300],ans;
int visited[300];
int n,l;


void dfs(int t,int m,int step)
{
   visited[t]=!((++step)%n);
      for(int i=0;i<v[t].size();++i)
   { 
    if(!visited[v[t][i]]&&v[t][i]!=m)
	{   //cout<<(char)t<<char(m)<<endl;
		if(visited[t])
     cout<<(char)t<<" ";
	  return dfs(v[t][i],t,step);
	}
   }
  
  cout<<"/"<<(char)t<<endl;
 
}


int main(void) {
	IOS 
	in();
	string s;
	getline(cin,s);
	while (s!="#")
	{
	memset(visited,0,sizeof visited);
	memset(v,0,sizeof v);

	int len=s.length();
        char p;
	int f=0,i;
	for(i=0;s[i]!='.';++i)
    {
	if(s[i]==':')
	{
	p=s[i-1];
	f++;
	continue;
	}
    if(s[i]==';')
		f=0;
	 if(f&&s[i]>='A'&&s[i]<='Z')
	 {
	 v[p].pb(s[i]);
	 }

	}
	
     char t=s[i+2],m=s[i+4];
     n=s[i+6]-'0';
	 i+=7;
	 while (i<len)
	 {
		n=n*10+s[i]-'0';
		i++;
	 }
	// cout<<t<<m<<n<<endl;
	dfs(t,m,0);
      getline(cin,s);
	}
	
    

	/*for(int i='A';i<='H';++i)
	 {  cout<<(char)i<<"---";
		 for(int j=0;j<v[i].size();++j)
		 cout<<(char)v[i][j]<<" ";

		 cout<<endl;
	 }*/


}
