// ==== Minimum Spanning Tree (kruskal) ===
// Complexity:
// Dependency: UnionFind
// Description: 

using namespace std;

void mst_kruskal(){
	vector<pair<int, II> >edgeList;
	for(int i=0; i<E; i++){
		scanf("%d%d%d",&u,&v,&w);
		List.push_back(make_pair(w,II(u,v)));
	}

	sort(edgeList.begin(), edgeList.end());

	int mst_cost = 0;
	UnionFind uf(V);
	for(int i=0; i<E; i++){
		pair<int, II> front = edgeList[i];
		if(!uf.isSameSet(front.second.first,front.second.second)){
			mst_cost += front.first;
			uf.unionSet(front.second.first,front.second.second);
		}
		if(uf.numDisjointSets==1) break;
	}
	printf("MST cost = %d\n",mst_cost);
}

int main(){
	return 0;
}
