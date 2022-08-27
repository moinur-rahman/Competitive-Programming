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

int getMaxArea(int hist[],int n)
{
    stack<int>s;

    int max_area = 0;
    int tp;
    int area_with_top;

    int i=0;

    while (i<n)
    {
     if(s.empty()||hist[s.top()]<=hist[i])
     s.push(i++);

     else
     {
         tp = s.top();
         s.pop();

         area_with_top = hist[tp] *(s.empty()?i:i-s.top()-1);

         max_area=max(max_area,area_with_top);
     }
     
    }

    while (!s.empty())
    {
        tp = s.top();
         s.pop();

         area_with_top = hist[tp] *(s.empty()?i:i-s.top()-1);

         max_area=max(max_area,area_with_top);
    }
    
    return max_area;
}

int main() 
{ 
    int hist[] = {6, 2, 5, 4, 5, 1, 6}; 
    int n = sizeof(hist)/sizeof(hist[0]); 
    cout << "Maximum area is " << getMaxArea(hist, n); 
    return 0; 
} 