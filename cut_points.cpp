ll n;
v2ll adj;

vector<bool>visited;
vll tin, low;
ll timer;

void dfs(ll v, ll p=-1){
	visited[v] = true;
	tin[v] = low[v] = timer++;

	ll children = 0;
	for(ll to: adj[v]){
		if(to == p){
			continue;
		}
		if(visited[to]){
			low[v] = min(low[v], low[to]);
		}
		else{
			dfs(to, v);
			low[v] = min(low[v], tin[to]);
			if(low[to]>=tin[v] && p!=-1)	IS_CUTPOINT(v);
			children++;
		}
		if(p==-1 && children>1){
			IS_CUTPOINT(v);
		}
	}
}

void find_cutpoints() {
  timer = 0;
  visited.assign(n, false);
  tin.assign(n, -1);
  low.assign(n, -1);
  for (ll i = 0; i < n; ++i) {
    if (!visited[i]) dfs(i);
  } 
}