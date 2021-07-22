#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> Pi;
typedef map<ll,ll> mi;

template<class T> T nrem(T x,T y){return ((x%y)+y)%y;}
const ll M=1e9+7;
ll mod(ll x){return ((x%M+M)%M);}

#define loop(i,a,b) for(int i=a;i<=b;++i)
#define rloop(i,a,b) for(int i=a;i>=b;--i)
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
#define cs 200005
#define pi acos(-1)
#define INF (int)INFINITY

void in()
    {
      #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
      #endif
    }

struct node {
    bool endmark;
    node* next[26 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;
void insert(char* str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}
bool search(char* str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}
void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}

int main()
{

  //  puts("ENTER NUMBER OF WORDS");
    root = new node();
    int num_word;
    cin >> num_word;
    for (int i = 1; i <= num_word; i++) {
        char str[50];
        scanf("%s", str);
        insert(str, strlen(str));
    }
 //   puts("ENTER NUMBER OF QUERY";);
    int query;
    cin >> query;
    for (int i = 1; i <= query; i++) {
        char str[50];
        scanf("%s", str);
        if (search(str, strlen(str)))
            puts("FOUND");
        else
            puts("NOT FOUND");
    }
    del(root); //ট্রাইটা ধ্বংস করে দিলাম
    return 0;
}
