#include <cstdio>
#include <algorithm>

#define INF 1000000000

using namespace std;

void floyd_warshall(){
	/*
	for(int i=0; i<V; i++)
		for(int j=0; j<V; j++)
			p[i][j] = i;
	*/
	for(int k=0; k<V; k++)
		for(int i=0; i<V; i++)
			for(int j=0; j<V; j++){
				adjMatrix[i][j] = min(adjMatrix[i][j],adjMatrix[i][k]+adjMatrix[k][j]);
				//p[i][j] = p[k][j];
			}
	return;
}

int main(){

	return 0;
}
