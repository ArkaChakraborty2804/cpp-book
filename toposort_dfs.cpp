stack<ll> toposort_dfs(ll node, v2ll &adjList, vll &visited, stack<ll> &st){
	visited[node] = 1;
	for(auto it: adjList[node]){
		if(!visited[it]){
			toposort_dfs(it);
		}
	}
	st.insert(node);


	return st;
}

/*if(st.size()==n){
	cout<<"Graph detected"<<endl;
}
*/