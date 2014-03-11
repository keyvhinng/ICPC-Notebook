// ==== SSSPP Without Negative Cycle (2) ===
// Complexity: O(E+V)
// Implementation time:
// Dependecy:
// Description:

int adj[MAXN][MAXN];
int cost[MAXN][MAXN];
int nadj[MAXN];

int D[MAXN], vist[MAXN], p[MAXN];

void min DFS(int u){
	int v, w;
	vis[u]=1;
	for(int j=0; j<nadj[u]; j++){
		v = adj[u][j];
		w = cost[u][j];
		if(!vis[v]) minDFS(v);
		if(D[u]>D[v]+w){
			D[u] = D[v] + w;
			p[u] = v;
		}
	}
	return;
}

int minDAG(int s, int d, int n){
	memset(D,0x3f,n*sizeof(int));
	memset(vis,0,n*sizeof(int));
	D[d]=0;
	minDFS(s);
	return D[s];
}

int main(){
	int n, m;
	int s, d;
	int u, v, w;
	while(scanf("%d%d",&n,&m)==2 && n!=0){
		scanf("%d%d",&s,&d);
		memset(nadj,0,sizeof(nadj));
		for(int i=0; i<m; i++){
			scanf("%d%d%d",&u,&v,&w);
			adj[u][nadj[u]] = v;
			cost[u][nadj[u]++] = w;
		}
		printf("%d\n",minDAG(s,d,n));
	}
	return 0;
}
