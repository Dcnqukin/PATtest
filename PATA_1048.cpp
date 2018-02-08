//PATA_1048 Find Coins
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxm = 1005;
int hashTable[maxm];
int main(){
	freopen("testIn_A1048.txt", "r", stdin);
	int n, m, a;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		++hashTable[a];
	}
	for(int i = 0; i < maxm; i++){
		if(hashTable[i] && hashTable[m - i]){
			if( i == m - i && hashTable[i] <= 1)
				continue;
		printf("%d %d", i, m - i);
		return 0;
		}
	}
	printf("No Solution\n");
	fclose(stdin);
	return 0;
}
