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
    string suff; 
}; 
  

int cmp(struct suffix a, struct suffix b) 
{ 
    return a.suff.compare(b.suff) < 0? 1 : 0; 
} 

int *buildSuffixArray(string txt, int n) 
{ 

    struct suffix suffixes[n]; 
  
 
    for (int i = 0; i < n; i++) 
    { 
        suffixes[i].index = i; 
        suffixes[i].suff = txt.substr(i); 
    } 
  
    sort(suffixes, suffixes+n, cmp); 
  
   
   For0(i,n)
   cout<<suffixes[i].suff<<endl;
    int *suffixArr = new int[n]; 
    for (int i = 0; i < n; i++) 
        suffixArr[i] = suffixes[i].index; 
  
    return  suffixArr; 
} 
  

void printArr(int arr[], int n) 
{ 
    for(int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

int search(string pat, string txt, int *suffArr, int n) 
{ 
    int m = pat.length(); 
  
    int l = 0, r = n-1,x=0,y=0;  
    while (l <= r) 
    { 
        int mid = l + (r - l)/2; 
        int res =txt.compare(suffArr[mid],m,pat); 

    
  
        if (res < 0) l = mid + 1; 
  
        else r = mid - 1; 
    } 
    x=r+1;
   l=0,r=n-1;
    while (l <= r) 
    { 
        int mid = l + (r - l)/2; 
		
        int res = txt.compare(suffArr[mid],m,pat);
  
        if (res <= 0) l = mid + 1; 
  
        else r = mid - 1; 
    } 
	y=l-1;
  // cout<<x<<" "<<y<<endl;
	return y-x+1;
} 

int main() 
{ IOS fi
  int t;
  cin>>t;
  while (t--)
  {
   string s;

  cin>>s;

  
  int q;
  cin>>q;
  while (q--)
  {
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  
   string x=s.substr(a-1,b-a+1),y=s.substr(c-1,d-c+1);
  // cout<<x<<" "<<y<<endl;
  int *arr=buildSuffixArray(x,x.length());
  
     cout<<search(y,x,arr,x.length())<<endl;
  }
  
  
  
  
  }

}
