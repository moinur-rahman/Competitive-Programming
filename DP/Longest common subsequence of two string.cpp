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
int LCS[mx][mx];

int main()
{
    IOS;
    int m,n,o=0,e=0;
    string a,b;
    cin>>a>>b;   ///INPUT ABACEB and ADBAVCEB
    m=a.length();
    n=b.length();

    For1(i,m)
    For1(j,n)
    {
        if(a[i-1]==b[j-1])
            LCS[i][j]=1+LCS[i-1][j-1];
        else
            LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
    }
    For1(i,m)
    {For1(j,n)
    cout<<LCS[i][j]<<" ";
    cout<<endl;
    }
}
