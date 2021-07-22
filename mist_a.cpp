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

struct suffix 
{ 
    int index; 
    char *suff; 
}; 
  
struct suffix suffixes[100000]; 

int cmp(struct suffix a, struct suffix b) 
{ 
    return strcmp(a.suff, b.suff) < 0? 1 : 0; 
} 

int *buildSuffixArray(char *txt, int n) 
{ 

    for (int i = 0; i < n; i++) 
    { 
        suffixes[i].index = i; 
        suffixes[i].suff = (txt+i); 
    } 
  
    
    sort(suffixes, suffixes+n, cmp); 
    
  //  For0(i,n)
  //  cout<<suffixes[i].index<<" "<<suffixes[i].suff<<endl;
  
    int *suffixArr = new int[n]; 
    for (int i = 0; i < n; i++) 
        suffixArr[i] = suffixes[i].index; 
  
  
    return  suffixArr; 
} 
  
int main() 
{ IOS 
  int t;
  cin>>t;
  while (t--)
  {
   char s[100000];

   cin>>s;
    int len=strlen(s);
  int *arr=buildSuffixArray(s,len);
  int tc;
  cin>>tc;
  while (tc--)
  {
  int a,b,c,d,i=0;
  cin>>a>>b>>c>>d;
  
  char x[100000],y[100000];
   
   for(i=c-1;i<=d-1;i++)
       y[i-c+1]=s[i];
       
       y[d-c+1]='\0';

   //cout<<y<<endl;
   int pos=find(arr,arr+len,c-1)-arr;
   int p=0,q=0,cnt=0;
   //cout<<"pos"<<pos<<endl;
   for(p=pos;p>=0&&strncmp(y,suffixes[p].suff,strlen(y))==0;--p)
   {
       if(suffixes[p].index+1>=a&&suffixes[p].index+1<=b-(d-c))
       cnt++;
     //  cout<<suffixes[p].index+1<<" "<<suffixes[p].suff<<endl;
   }
   //cout<<p+1<<endl;
   for(q=pos+1;q<len&&strncmp(y,suffixes[q].suff,strlen(y))==0;q++)
   {
       if(suffixes[q].index+1>=a&&suffixes[q].index+1<=b-(d-c))
       cnt++;
  //cout<<suffixes[q].index+1<<" "<<suffixes[q].suff<<endl;
   }
 
   cout<<cnt<<endl;
  }

  }
 
 
}
