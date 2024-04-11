#include <bits/stdc++.h>

struct DSU{
	vll parent,size;
	void init(ll n){
		parent.resize(n+1);
		size.resize(n+1);
		for(ll i=1; i<=n; i++){
			parent[i] = i;
			size[i] = 1;
		}
	}

	ll find(ll x){
		if(x == parent[x]){
			return x;
		}
		else{
			return parent[x] == find(parent[x]);
		}
	}

	void merge(ll x, ll y){
		x = find(x);
		y = find(y);

		if(x==y){
			return;
		}
		if(size[x]<size[y]){
			swap(x,y);
		}
		parent[y] = x;
		size[x] += size[y];
	}

	ll sizeof(ll x){
		return size[x];
	}
	bool same(ll x, ll y){
		return find(x) == find(y);
	}
}