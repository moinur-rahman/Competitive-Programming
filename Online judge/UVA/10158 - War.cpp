#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> Pi;
typedef map<ll, ll> mi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T nrem(T x, T y) { return ((x % y) + y) % y; }
const ll M = 1e9 + 7;
ll mod(ll x) { return ((x % M + M) % M); }

#define loop(i, a, b) for (int i = a; i <= b; ++i)
#define rloop(i, a, b) for (int i = a; i >= b; --i)
#define For0(i, n) for (int i = 0; i < n; ++i)
#define For1(i, n) for (int i = 1; i <= n; ++i)
#define Forl0(i, n) for (ll i = 0; i < n; ++i)
#define Forl1(i, n) for (ll i = 1; i <= n; ++i)
#define fi freopen("input.txt", "r", stdin);
#define fo freopen("output.txt", "w", stdout);
#define pb push_back
#define mp make_pair
#define endl "\n"
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define cs 500005
#define pi acos(-1)
#define INF (int)INFINITY

void in()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int n;

int parent[cs], sz[cs];

void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v)
{
    if (parent[v] == v)
    {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    int u = find_set(a);
    int v = find_set(b);
    if (u != v)
    {
        parent[v] = u;
    }
}

int enemy(int x)
{
    return x + n;
}

void solve()
{

    cin >> n;

    For1(i, 2 * n + 1)
    {
        make_set(i);
    }

    int a, b, c;
    while (1)
    {
        cin >> c >> a >> b;
        if (!a && !b && !c)
        {
            break;
        }
        // if (a > b)
        // {
        //   swap(a, b);
        // }
        if (c == 1)
        {
            if (find_set(a) == find_set(enemy(b)) || find_set(b) == find_set(enemy(a)))
            {
                cout << -1 << endl;
                continue;
            }
            union_sets(a, b);
            union_sets(enemy(a), enemy(b));
        }
        else if (c == 2)
        {
            if (find_set(a) == find_set(b) || find_set(enemy(a)) == find_set(enemy(b)))
            {
                cout << -1 << endl;
                continue;
            }
            union_sets(a, enemy(b));
            union_sets(b, enemy(a));
        }
        else if (c == 3)
        {
            if (find_set(a) == find_set(b) || find_set(enemy(a)) == find_set(enemy(b)))
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else
        {
            if (find_set(a) == find_set(enemy(b)) || find_set(b) == find_set(enemy(a)))
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }
}

int main()
{
    in();
    IOS int t = 1;
    // cin >> t;
    For1(i, t)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}