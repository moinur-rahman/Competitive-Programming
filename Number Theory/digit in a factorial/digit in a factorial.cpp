///finding the digit of a factorial///

#include<bits/stdc++.h>
using namespace std;

typedef long long int li;

#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)

int fact(int n)
{
    double sum=0;

    for(int i=1;i<=n;i++)
    sum=sum+log10(i);

    return sum;
}
int main()
{
    int n;
    cin>>n;
    cout<<fact(n)+1<<endl;

}
