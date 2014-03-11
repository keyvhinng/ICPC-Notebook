// === SSSP With Negative Cycle ===
// Complexity: O(E)
// Implementation time:
// Dependency:
// Description:

#include <cstdio>
#include <vector>

using namespace std;
typedef vector<int> VI;

bool hasNegCycle(){
	for(int u=0; u<V; u++){
		for(int j=0; j<(int)adjList[u].size(); j++){
			II v = adjList[u][j];
			if(dist[v.first]>dist[u]+v.second) return true;
		}
	}
	return false;
}

void bellmanFord(int s){
	VI vist(V,INF);
	for(int i=0; i<V-1; i++)
		for(int u=0; u<V; u++)
			for(int j=0; j<(int)adjList[u].size(); j++){
				II v = adjList[u][j];
				dist[v.first] = min(dist[v.first],dist[u]+v.second);
			}
}

int main(){
	return 0;
}
