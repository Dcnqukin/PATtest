//PATA_1092 To Buy or Not to Buy
#include <cstdio>
#include <cstring>
const int maxn = 1010;
int hashTable[80] = {0}, miss = 0;
int change(char c){
	if(c >= '0' && c <= '9') return c - '0';
	if(c >= 'a' && c <= 'z') return c - 'a' + 10;
	if(c >= 'A' && c <= 'Z') return c - 'A' + 36;
}
int main(){
	//freopen("testIn_A1092.txt", "r", stdin);
	char first[maxn], second[maxn];
	gets(first);
	gets(second);
	int len1 = strlen(first);
	int len2 = strlen(second);
	for(int i = 0; i < len1; i++){
		int id = change(first[i]);
		hashTable[id]++;
	}
	for(int i = 0; i < len2; i++){
		int id = change(second[i]);
		hashTable[id]--;
		if(hashTable[id] < 0){
			miss++;
		}
	}
	if(miss > 0)printf("No %d\n", miss);
	else printf("Yes %d\n", len1 - len2);
	//fclose(stdin);
	return 0;
}
