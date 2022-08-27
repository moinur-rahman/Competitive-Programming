#include<bits/stdc++.h>
using namespace std;

typedef long long int li;

#define For0(i,n) for(int i=0;i<n;i++)
#define For1(i,n) for(int i=1;i<=n;i++)

#define mx 32000
vector<int> prime;

void seive()
{
    bool isPrime[mx];
    memset(isPrime,true,sizeof(isPrime));
    for(int i=3;i*i<=mx;i=i+2)
        if(isPrime[i])
    {
        for(int j=i*i;j<=mx;j=j+i+i)
            isPrime[j]=false;
    }
    prime.push_back(2);
    for(int i=3;i<mx;i+=2)
        if(isPrime[i])
        prime.push_back(i);
}

void segSieve(li l,li r)
{
    bool isPrime[r-l+1];
    memset(isPrime,true,sizeof(isPrime));
    if(l==1)isPrime[0]=false;
    for(int i=0;prime[i]*prime[i]<=r;i++)
    {
        int currentPrime=prime[i];
        li base=(l/currentPrime)*currentPrime;
        if(base<l)base+=currentPrime;
        for(li j=base;j<=r;j+=currentPrime)
            isPrime[j-l]=false;
        if(base==currentPrime)isPrime[base-l]=true;
    }
    for(int i=0;i<r-l+1;i++)
    {
        if(isPrime[i])
            cout<<(i+l)<<endl;
    }
}

int main()
{  seive();
   li a,b;
   cin>>a>>b;
   segSieve(a,b);
}
