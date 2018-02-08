//PATA_1050 String Subtraction
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 10010;
bool hashTable[128] = {false};
int main(){
	freopen("testIn_A1050.txt", "r", stdin);
	char str1[maxn], str2[maxn];
	cin.getline(str1, maxn);
	cin.getline(str2, maxn);
	for(int i = 0; i < strlen(str2); i++){
		hashTable[str2[i]] = true;
	}
	for(int i = 0; i < strlen(str1); i++){
		if(hashTable[str1[i]] == false)
			printf("%c", str1[i]);
	}
	printf("\n");
	fclose(stdin);
	return 0;
}
