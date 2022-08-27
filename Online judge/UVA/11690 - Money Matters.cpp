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

int n, m;
int parent[cs], sz[cs];

void make_set(int v)
{
    parent[v] = v;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {

        parent[b] = a;
        sz[a] += sz[b];
    }
}

void solve()
{

    cin >> n >> m;

    For0(i, n)
    {
        cin >> sz[i];
        make_set(i);
    }
    // For0(i, n)
    // {
    //   cout << parent[i] << " ";
    // }
    // cout << endl;

    // For0(i, n)
    // {
    //   cout << sz[i] << " ";
    // }
    // cout << endl;
    For0(i, m)
    {
        int u, v;
        cin >> u >> v;
        union_sets(u, v);

        // For0(i, n)
        // {
        //   cout << parent[i] << " ";
        // }
        // cout << endl;

        // For0(i, n)
        // {
        //   cout << sz[i] << " ";
        // }
        // cout << endl;
    }
    For0(i, n)
    {
        if (sz[find_set(i)])
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    cout << "POSSIBLE" << endl;
}

int main()
{
    in();
    IOS int t = 1;
    cin >> t;
    For1(i, t)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}