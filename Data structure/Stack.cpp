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
}Stack;

void push(Stack *s, int item)
{
    if(s->top<Stack_max)
    {
        s->data[s->top]=item;

        s->top++;
    }
    else
    {
        cout<<"Stack is full"<<endl;
    }
}

int pop(Stack *s)
{
    int item;

    if(s->top==0)
    {
    cout<<"Stack is empty!\n";
    return -1;
    }
    else
    {
        s->top--;

        item=s->data[s->top];
    }

    return item;
}
int main()
{
//fi
IOS

Stack_max = 5;

int item;
Stack s;

s.top=0;

push(&s,1);
push(&s,2);
push(&s,3);

item=pop(&s);
cout<<item<<endl;
item=pop(&s);
cout<<item<<endl;
item=pop(&s);
cout<<item<<endl;
}
