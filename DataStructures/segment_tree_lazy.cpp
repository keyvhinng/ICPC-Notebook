#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100100
using namespace std;

int st[4*MAXN]; lazy[4*MAXN];

void build(int root, int l, int r){
	if(a>b) return;
	if(a==b){
		st[root] = arr[l];
		return;
	}
	build(2*root+1,l,(r+l)/2);
	build(2*root+2,(r+l)/2+1,r);
	st[root] = max(st[2*root+1],st[2*root+2]);
}

void update(int node, int l, int r, int a, int b, int value){
	if(lazy[root]!=0){
		st[root]+=lazy[root];
		if(l!=r){
			lazy[2*node+1] += lazy[node];
			lazy[2*node+2] += lazy[node];
		}
		lazy[node]=0;
	}
	if(l>r || l>b || r<a) return;
	if(l>=a && r<=b){
		st[node] =+ value;
		if(l!=r){
			lazy[2*node+1] += value;
			lazy[2*node+2] += value;
		}
		return;
	}
	update(2*node+1, l        , (l+r)/2, a, b, value);
	update(2*node+2, (l+r)/2+1, r      , a, b, value);
	st[node] = max(st[2*node+1],st[2*node+2]);
}

int query(int node, int l, int r, int a, int b){
	if(l>r || l>b || r<a) return -INF;
	if(lazy[node]!=0){
		st[node] += lazy[node];
		if(i!=j){
			lazy[2*node+1] += lazy[node];
			lazy[2*node+2] += lazy[node];
		}
		lazy[node]=0;
	}
	if(l>=a && r<=b) return st[node];
	int q1 = query(2*node+1, l        , (l+r)/2, a, b);
	int q2 = query(2*node+2, (l+r)/2+1, r      , a, b);
	int ans = max(q1,q2);
	return ans;
}

int main(){
	int 
}
