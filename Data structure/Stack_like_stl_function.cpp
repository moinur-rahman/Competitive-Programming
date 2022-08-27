#include<bits/stdc++.h>
using namespace std;

typedef long long int li;

#define For(i,a,n) for(int i=a;i<n;++i)
#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)
#define fi freopen("input.txt","r",stdin);
#define fo freopen("output.txt","w",stdout);
#define pb push_back
#define mp make_pair
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define mx 100005
//#ifndef ONLINE_JUDGE
//fi;
//fo;
//#endif

int Stack_max;

typedef struct
{
    int top;
    int data[mx];
void push(int item)
{
    if(top<Stack_max)
    {
        data[top]=item;

        top++;
    }
    else
    {
        cout<<"Stack is full"<<endl;
    }
}
int pop()
{
    int item;

    if(top==0)
    {
    cout<<"Stack is empty!\n";
    return -1;
    }
    else
    {
        top--;

        item=data[top];
    }

    return item;
}
}Stack;




int main()
{
//fi
IOS

Stack_max = 5;

int item;
Stack s;

s.top=0;

s.push(1);
s.push(2);
s.push(3);

item=s.pop();
cout<<item<<endl;
item=s.pop();
cout<<item<<endl;
item=s.pop();
cout<<item<<endl;
cout<<s.pop()<<endl;
}
