// === SSSP Without Negatice Cycles ===
// Complexity:
// Dependency:
// Description:

#define INF 100000000

using namespace std;
typedef pair<int,int> II;

void dijkstra(int s){
	VI dist(V, INF); dist[s]=0;
	priority_queue<II, vector<II> greater<II> >pq; pq.push(II(0,s));
	while(!pq.empty()){
		II front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if(d>dist[u]) continue;
		for(int j=0; j<(int)adjList[u].size(); j++){
			II v = adjList[u][j];
			if(dist[u]+v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				pq.push(II(dist[v.first],v.first));
			}
		}
	}
	return;
}
