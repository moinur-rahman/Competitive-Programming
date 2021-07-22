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

int digit[10];

int main ()
{ 
  int T,k=0;
  cin>>T;
  For0(k,T)
  {
  memset(digit,0,sizeof digit);
  string s;
  cin>>s;
  int len=s.length(),total=0;
  //cout<<len<<endl;
  For0(i,len)
  digit[s[i]-'0']++,total+=s[i]-'0';
  //cout<<total<<endl;
  cout<<"Case "<<k+1<<": ";
  int cnt=0;
  for(int i=total%3;i<=9;i+=3)
  { if(digit[i]!=0)
    digit[i]--,total-=i,cnt++,i=total%3;
   // cout<<total<<" "<<i<<" "<<cnt<<endl;
  }
  
  if(cnt%2)
  cout<<"S"<<endl;
  else
  cout<<"T"<<endl;
  }
}
