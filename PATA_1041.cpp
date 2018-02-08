//PATA_1041 Be Unique
#include<cstdio>
#include<algorithm>
#include<cstring>

const int maxn = 100010;
struct Bet{
	int data;
	bool flag;
}bet[maxn];

/*	bool cmp(bet a, bet b)
		return a.flag > b.flag; */

int main(){
	freopen("testIn_A1041.txt", "r", stdin);
	for(int i = 0; i < maxn; i++)
		bet[i].flag = false;
	int n;
	int hashTable[10010] = {0};
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &bet[i].data);
		hashTable[bet[i].data] += 1;
	}
	for(int i = 0; i < n; i++){
		if(hashTable[bet[i].data] == 1){
			printf("%d\n", bet[i].data);
			break;
		}
		if(i == n - 1)
			printf("None\n");
		
	}
	fclose(stdin);
	return 0;
}
