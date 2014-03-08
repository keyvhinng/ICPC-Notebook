// === Strongly Connected Components ===
//Complexity
//Dependency
//Description

int adj[MAXN][MAXN];
int nadj[MAXN];

int dfs_low[MAXN], dfs_num[MAXN], dfs_parent[MAXN], av[MAXN];
int vis[MAXN];
int numSCC, counter;
vector<int> S;

void tarjanSCC(int u){
	int v;
	dfs_low[u] = dfs_num[u] = counter++;
	S.push_back(u);
	vis[u] = 1;
	for(int j=0; j<nadj[u]; j++){
		v = adj[u][j];
		if(dfs_num[v]==-1)
			tarjanSCC(v);
		if(vis[u])
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
	}
	
	if(dfs_low[u]==dfs_num[u]){
		printf("SCC %d\n",++numSCC);
		while(1){
			v = s.back(); S.pop_back(); visited[v]=0;
			printf(" %d",v);
			if(u==v) break;
		}
		printf("\n");
	}
}
