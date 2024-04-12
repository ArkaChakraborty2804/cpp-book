#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector <ll> toposort(vector<vector<ll>> &adj, ll n){
	vector<ll>indegree(n+1,0);
	for(auto row: adj){
		for(auto col: row){
			indegree[col]++;
		}
	}

	queue<ll> q;
	for(ll i=1; i<n+1; i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}

	vector<ll>result;
	while(!q.empty()){
		ll node = q.front();
		q.pop();
		result.push_back(node);
		for(ll neighbour: adj[node]){
			indegree[neighbour]--;
			if(indegree[neighbour]==0){
				q.push(neighbour);
			}
		}
	}

	if(result.size()!=n){
		return {};
	}
	return result;
}

signed main(){
	ll n;	cin>>n;
	vector<vector<ll>>adj[n+1];

	ll e;	cin>>e;
	ll x, y;
	for(ll i=0; i<e; i++){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	vector <ll> = toposort(adj, n);
}