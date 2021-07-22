#include<bits/stdc++.h>
using namespace std;

typedef long long int li;
typedef long long ll;

#define For(i,a,n) for(int i=a;i<n;++i)
#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)
#define fi freopen("input.txt","r",stdin);
#define fo freopen("output.txt","w",stdout);
#define pb push_back
#define mp make_pair
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define cs 10005

//#ifndef ONLINE_JUDGE
//fi;
//fo;
//#endif



int LCS(string A, string B)
{  
  int lcs[A.length()+1][B.length()+1];
   for(int i=0; i<=A.length(); ++i)
      for(int j=0; j<=B.length(); ++j)
      {
         if(i==0 || j==0)
            lcs[i][j]=0;
         else if(A[i-1]==B[j-1])
            lcs[i][j]=lcs[i-1][j-1] + 1;
         else
            lcs[i][j]= max(lcs[i-1][j] ,lcs[i][j-1] );
      }
   return lcs[A.length()][B.length()];
}


int main()
{    IOS
     string a,b;
     while(getline(cin,a))
     {
       getline(cin,b);
       cout<<LCS(a,b)<<endl;
     }
} 

