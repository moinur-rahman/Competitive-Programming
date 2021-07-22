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

int lps[mx][mx];
string s;
int LPS(int i,int j)
{
if(lps[i][j])
return lps[i][j];

if(i==j)
return lps[i][j]=1;

if(s[i]==s[j]&&i+1==j)
return lps[i][j]=2;

if(s[i]==s[j])
return lps[i][j]=LPS(i+1,j-1)+2;

return lps[i][j]=max(LPS(i,j-1),LPS(i+1,j));

}

int main()
{
    cin>>s;
   
    cout<<LPS(0,s.length()-1);

}
