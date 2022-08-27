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
#define IOS                         \
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

set<int> v[105];

int parent[105];

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
  return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b)
{
  int x = find_set(a);
  int y = find_set(b);

  if (x != y)
  {
    parent[y] = x;
  }
}

void solve()
{
  int t;
  scanf("%d", &t);

  For1(k, t)
  {
    if (k == 1)
    {
      getchar();
      getchar();
    }
    memset(parent, 0, sizeof parent);

    char s[50];
    gets(s);
    int p, t;
    sscanf(s, "%d %d", &p, &t);
    For1(i, p)
    {
      v[i].clear();
      make_set(i);
    }
    // if (t == 0)
    // {
    //   if (p > 0)
    //   {
    //     cout << 1 << endl;
    //   }
    //   else
    //   {
    //     cout << 0 << endl;
    //   }
    //   continue;
    // }
    // cout << p << " " << t << endl;

    while (gets(s))
    {
      if (!strlen(s))
      {
        break;
      }
      int a, b;
      sscanf(s, "%d %d", &a, &b);
      v[a].insert(b);
      // cout << a << " " << b << endl;
      // cout << s << endl;
    }

    for (int i = 1; i < p; i++)
    {
      for (int j = i + 1; j <= p; j++)
      {
        if (v[i] == v[j] && v[i].size() && v[j].size())
          union_set(i, j);
      }
    }
    int f = 0;
    For1(i, p)
    {
      if (!v[i].size())
      {
        f = 1;
      }
    }
    map<int, int> mk;
    For1(i, p)
    {
      if (v[parent[i]].size())
        mk[parent[i]]++;
    }
    if (k != 1)
    {
      cout << endl;
    }

    cout << mk.size() + f << endl;

    // For0(i, p + 1)
    // {
    //   cout << parent[i] << " ";
    // }
    // cout << endl;
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