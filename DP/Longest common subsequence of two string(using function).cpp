///longest common subsequence of two string

#include<bits/stdc++.h>
using namespace std;

typedef long long int li;

#define For(i,a,n) for(int i=a;i<n;++i)
#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)

#define pb push_back
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define OJ
#define mx 10005

int lcs[mx][mx];

int LCS(string A, string B)
{


   for(int i=0; i<=A.length(); ++i)
      for(int j=0; j<=B.length(); ++j)
      {
         /*One string is of length 0*/
         if(i==0 || j==0)
            lcs[i][j]=0;
         /*When last elements are equal*/
         else if(A[i-1]==B[j-1])
            lcs[i][j]=lcs[i-1][j-1] + 1;
         /*When last elements are not equal*/
         else
            lcs[i][j]= max(lcs[i-1][j] ,lcs[i][j-1] );
      }
   return lcs[A.length()][B.length()];
}

int main()
{
    IOS;

    string a,b;
    cin>>a>>b;   ///INPUT ABACEB ADBAVCEB
    cout<<LCS(a,b)<<"\n";
    For1(i,a.length())
    {For1(j,b.length())
    cout<<lcs[i][j]<<" ";
    cout<<endl;
    }
}
