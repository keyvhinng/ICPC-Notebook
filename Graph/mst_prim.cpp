// === Minimum Spanning Tree (Prim)
// Complexity:
// Dependency:
// Description:

vector<int> taken;
priority_queue<II> pq;

void process(int vtx){
	taken[vtx] = 1;
	for(int j=0; j<(int)adjList[vtx].size(); j++){
		II v = adjList[vtx][j];
		if(!taken[v.first]) pq.push(II(-v.second,-v.first));
	}
}


void mst_prim(){
	int mst_cost;
	taken.assign(V,0);
	process(0);
	mst_cost = 0;
	while(!pq.empty()){
		II front = pq.top(); pq.pop();
		u = -front.second; w = -front.first;
		if(!taken[u]){
			mst_cost += w, process(u);
		}
	}
	printf("MST = %d\n",mst_cost);
}

int main(){
	return 0;
}
