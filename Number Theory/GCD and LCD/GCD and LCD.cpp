#include<bits/stdc++.h>
using namespace std;

typedef long long int li;
#define For0(i,n) for(int i=0;i<n;i++)
#define For1(i,n) for(int i=1;i<=n;i++)

#define mx 100005

int gcd(int a,int b)
{
    if(a%b==0) return b;
    return gcd(b,a%b);
}

double gcd(double a, double b) 
{ 
    if (a < b) 
        return gcd(b, a); 
  
    if (fabs(b) < 0.001) 
        return a; 
  
    else
        return (gcd(b, a - floor(a / b) * b)); 
} 
  
int lcm(int a,int b)
{
    return (a*b)/gcd(a,b);
}
int main()
{
int a,b;
cin>>a>>b;
cout<<gcd(a,b)<<endl;
cout<<lcm(a,b)<<endl;
}

