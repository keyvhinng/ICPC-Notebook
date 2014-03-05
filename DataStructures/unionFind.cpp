//Complexity:
//Implementation time:
//Dependency:
//Description:

classs UnionFind{
	private:
		vector<int> p, rank;
		int nDS;
	public:
		UnionFind(int N){
			rank.assign(N,0);
			for(int i=0; i<N; i++) p[i]=i;
			nDS = N;
		}

		int findSet(int i){
			return (p[i]==i)? i:(p[i]=findSet(p[i]));
		}

		bool isSameSet(int i, int){ return findSet(i)==findSet(j);}

		void unionSet(int i, int j){
			if(!isSameSet(i,j)){
				nDS--;
				int x = findSet(i), y = findSet(j);
				if(rank[x]>rank[y]) p[y]=x;
				else{
					p[x]=y;
					if(rank[x]==rank[y]) rank[y]++;
				}
			}
		}

		int numDisjointSets(){
			return nDS;
		}
};
