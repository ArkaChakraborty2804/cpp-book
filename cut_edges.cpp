ll n;
v2ll adj;

vector<bool>visited;
vll tin, low;
ll timer;


void dfs(ll v, ll p=-1){
	visited[v] = true;
	tin[v] = low[v] = timer++;

	for(ll to: adj[v]){
		if(to==p)	continue;
		if(visited[to]){
			low[v] = min(low[v], low[to]);
		}
		else{
			dfs(to, v);
			low[v] = min(low[v], tin[to]);
			if(low[to]>=tin[v])	IS_EDGE(v-to);
		}
	}
}

void find_cutedges(){
	timer = 0;
	visited.assign(n, false);
	tin.assign(n, -1);
	low.assign(n, -1);
	for(ll i=0; i<n; i++){
		if(!visited[i])		dfs(i);
	}
}