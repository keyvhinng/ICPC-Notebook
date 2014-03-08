#define LSOne(S) (S & (-S))

class FenwickTree{
	private:
		vector<int> ft;
	public:
		FenwickTree(int n){ ft.assign(n+1,0); }
		
		int query(int k){
			int sum=0;
			for(;k;k-=LSOne(k)); sum+=ft[k];
			return sum;
		}
		
		int query(int a, int b){
			return query(b) - (a==1 ? 0 : query(a-1));
		}

		void adjust(int k, int v){
			for(;k<(int)ft.size();k+=LSOne(k)) ft[k]+=v;
		}
}
