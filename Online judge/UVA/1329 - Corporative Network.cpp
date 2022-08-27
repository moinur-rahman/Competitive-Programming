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

int parent[cs], sz[cs];

void make_set(int v)
{
    parent[v] = v;
}

int find_set(int v)
{
    if (parent[v] == v)
    {
        return v;
    }
    return find_set(parent[v]);
}

int calc_sum(int v)
{
    if (parent[v] == v)
    {
        return 0;
    }

    return sz[v] + calc_sum(parent[v]);
}

void union_set(int a, int b)
{
    // a = find_set(a);
    // b = find_set(b);

    if (a != b)
    {
        parent[b] = a;
    }
}

void solve()
{
    memset(parent, 0, sizeof parent);
    memset(sz, 0, sizeof sz);
    int n;
    cin >> n;

    char c;
    cin >> c;
    For1(i, n)
    {
        make_set(i);
    }
    // For0(i, n + 1)
    // {
    //   cout << parent[i] << " ";
    // }
    // cout << endl;

    // For0(i, n + 1)
    // {
    //   cout << sz[i] << " ";
    // }
    // cout << endl;
    while (c != 'O')
    {
        int i, j;
        if (c == 'E')
        {
            cin >> i;
            cout << calc_sum(i) << endl;
        }
        else
        {
            cin >> i >> j;
            sz[i] = abs(i - j) % 1000;
            if (find_set(i) != find_set(j))
            {
                union_set(j, i);
            }
        }
        // cout << endl;
        // For0(i, n + 1)
        // {
        //   cout << parent[i] << " ";
        // }
        // cout << endl;

        // For0(i, n + 1)
        // {
        //   cout << sz[i] << " ";
        // }
        // cout << endl;
        cin >> c;
    }
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