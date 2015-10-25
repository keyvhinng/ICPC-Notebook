#include <bits/stdc++.h>
#define MAXN 1000

int n;

int ft[MAXN+1];

//at -> 0-base
void update(int at, int by){
	while(at<n){
		ft[at]+=by;
		at |= (at+1);
	}
}

//at -> 0-base
int query(int at){
	int sum=0;
	while(at>=0){
		sum+=ft[at];
		at = (at&(at+1))-1;
	}
	return sum;
}

//Range Updateds
int dataMul[MAXN+1];
int dataAdd[MAXN+1];

void update2(int at, int mul, int add){
	while(at<n){
		dataMul[at]+=mul;
		dataAdd[at]+=add;
		at |= (at+1);
	}
}

void range_update(int a, int b, int by){
	update2(a,by,-by*(a-1));
	update2(b+1,-by,by*b);
}

int range_query(int at){
	int mul = 0;
	int add = 0;
	int start = at;
	while(at>=0){
		mul += dataMul[at];
		add += dataAdd[at];
		at = (at&(at+1))-1;
	}
	return mul*start + add;
}

int main(){
	int nop, nq;
	int at, by;

	/*
	memset(ft,0,sizeof(ft));
	scanf("%d",&n);
	scanf("%d",&nop);

	for(int i=0; i<nop; i++){
		scanf("%d%d",&at,&by);
		printf("update %d %d\n",at,by);
		update(at,by);
		for(int j=0; j<=n; j++){
			printf(" %2d",j);
		}
		printf("\n");
		for(int j=0; j<=n; j++){
			printf(" %2d",ft[j]);
		}
		printf("\n");
		printf("\n");
	}

	scanf("%d",&nq);
	for(int i=0; i<nq; i++){
		scanf("%d",&at);
		printf("%d\n",query(at));
	}
	*/


	//Range update
	int a, b;

	memset(dataMul,0,sizeof(dataMul));
	memset(dataAdd,0,sizeof(dataAdd));

	scanf("%d",&n);
	scanf("%d",&nop);

	for(int i=0; i<nop; i++){
		scanf("%d%d",&a,&b);
		range_update(a,b,1);
	}
	return 0;
}
