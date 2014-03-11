// Autor: Douglas Santos
// Complexity:
// Dependency:
// Description:

#include <vector>
#include <cstdio>
#include <cstdio>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 120
#define MAXT 10

int adj[MAXN][MAXN];
int tt[MAXT]; //terminal vertices
int n, nt;    //number of vertices and terminals

int memo[1<<MAXT][MAXT];

vector<int> mask[MAXT];

void getMask(int mask, int e, int &x, int &y, int n){
	int j=0;
	x=0;
	y=0;
	for(int i=0; i<n; i++){
		while(!(mask & (1<<j))){
			j++;
		}
		if(e & (1<<i)){
			x = x | (1<<j);
		}else{
			y = y | (1<<j);
		}
		j++;
	}
}

int minstree(){
	floyd();
	if(nt==2) return f[tt[0]][tt[1]];
	for(int t=0; t<nt-1; t++){
		mask[t].clear();
		for(int j=0; j<n; j++){
			memo[(1<<t)][j] = d[j][tt[t]];
		}
	}
	for (int i=0; i<=(1<<(nt-1))-1; i++){
		int x = __builtin_popcon(i);
		if(x>1) mask[x].push_back(i);
	}
	for (int m=2; m<=nt-2; m++){
		for(int k=0; k<mask[m].size(); k++){
			int msk = mask[m][k];
			for(int i=0; i<n; i++) memo[msk][i] = INF;
			for(int j=0; j<n; j++){
				int u = INF;
				int e;
				for(e=0; e<(1<<(m-1)); e++){
					e = e | (1<<(m-1));
					int x, y;
					getMask(msk,e,x,y,m);
					u = min(u,memo[x][j]+memo[y][j]);
				}
				for(int i=0; i<n; i++)
					memo[msk][i] = min(memo[msk][i], d[i][j]+u);
			}
		}
	}
	int v = INF;
	int q = tt[nt-1];
	for(int j=0; j<n; j++){
		int u = INF;
		for(int e=1; e<(1<<(nt-1)); e++){
			u = min(u,memo[e][j] + memo[e^((1<<nt-1))-1][j]);
		}
		v = min(v, d[q][j]+u);
	}
	return v;
}

int main(){
	scanf("%d%d",&n,&nt);
	for(int i=0; i<nt; i++){
		int u;
		scanf("%d",&u);
		u--;
		tt[i]=u;
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d",&adj[i][j]);
	printf("%d\n",minstree());
	return 0;
}

