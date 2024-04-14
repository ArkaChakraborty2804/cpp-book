#define ll long long

vector<ll> djikstra(vector<vector<ll>>&adj, ll s, ll n){
	vector<bool> visited(n+1, false);
	vector<ll> dist(n+1, LLONG_MAX);
	dist[s] = 0;
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
	pq.push({0, s});
	visited[s] = true;

	// Relax all edges
	while(!pq.empty()){
		ll u = pq.top().second;
		pq.pop();

		for(auto &edge: adj[u]){
			ll v = edge.first;
			ll w = edge.second;

			if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
		}
	}
	return dist;
}