class SegmentTree{
	private:
		vector<int> st, A;
		int n;
		int left(int p)  {return p<<1;}
		int right(int p) {return (p<<1)+1;}

		void build(int p, int L, int R){
			if(L==R)
				st[p]=A[L];
			else{
				build(left(p) , L        , (L+R)/2);
				build(right(p), (L+R)/2+1, R      );
				int p1 = st[left(p)], p2 = st[right(p)];
				st[p] = p1<=p2? p1:p2;
			}
		}

		void query(int p, int L, int R, int i, int j){
			if(i>R || j<L) return -1;
			if(L>=i && R<=j) return st[p];
			if(p1==-1) return p2;
			if(p2==-1) return p1;
			return (p1<=p2)? p1 : p2;
		}

		void update(int p, int L, int R, int i, int nv){
			if(L==R){
				st[p] = nv;
			}else{
				int mid = (L+R)/2;
				if(i<=mid)
					update(left(p) , L    , mid, i, nv);
				else
					update(right(p), mid+1, R,   i, nv);	
				st[p] = min(st[left(p)], st[right(p)]);
			}
		}

public:
		SegmentTree(const vector<int> &_A){
			A = _A;
			n = (int)A.size();
			st.assign(4*n,0);
			build(1,0,n-1);
		}
};
