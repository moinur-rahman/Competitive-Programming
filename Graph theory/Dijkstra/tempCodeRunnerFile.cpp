
void dijkstra(ll s,ll n)
{
  priority_queue<pi,vector<pi>,greater<pi> > Q;///distance and source
  for(ll i=1;i<=n;++i)
  dist[i]=1e18;
  Q.push(make_pair(0,s));
  dist[s]=0;
  while (!Q.empty())
  {
   ll u=Q.top().second;

    Q.pop();
    for (ll i = 0; i < v[u].size() ; i++)  ///adjacent node of u
    {    ll f=v[u][i].first;   /// .first is the second node and .second is the weight

      if( dist[u]+v[u][i].second<dist[f] )
       {
         dist[f] = dist[u] + v[u][i].second ;
         Q.push(make_pair(dist[f],f));
         parent[f]=u;
       }
    }
  }
}