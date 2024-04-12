// d is the adjacency matrix
ll d[N][N];

for (ll k = 1; k <= n; ++k) {
  	for (ll i = 1; i <= n; ++i) {
    	for (ll j = 1; j <= n; ++j) {
    		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		}	 
	}
}