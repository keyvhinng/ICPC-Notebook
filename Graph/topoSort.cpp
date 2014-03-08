vector<int> ts;

void dfs2(int u){
	int v;
	vis[u]=1;
	for(int j=0; j<(int)adjList[u].size(); j++){
		v = adjList[u][j];
		if(!vist[v]) dfs2(v);
	}
	ts.push_back(u);
}

void topoSort(){
	for(int i=0; i<V; i++){
		if(!vis[i]) dfs2(i);
	}
	reverse(ts.begin(), ts.end());
}
