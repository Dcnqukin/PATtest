//PATA_1112 Stucked Keyboard
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
#define maxn 1010
bool hashTable[40] = {0};
bool current[40] = {0};
int n;
char str[maxn];
string ans;
int change(char c){
	if(c >= '0' && c <= '9') return c - '0';
	else if(c >= 'a' && c <= 'z') return c - 'a' + 10;
	else if(c == '_') return 37;
}
char convert(int i){
	if(i >= 0 && i <= 9) return '0' + i;
	else if(i >= 10 && i <= 36) return 'a' + i - 10;
	else if(i == 37) return '_';
}
bool isR(char str[], int n, int i){
	int num = 0;
	char c = str[i];
	for(int j = i; j < i + n; j++){
		if(str[j] == c)
			num++;
	}
	if(num == n){
		return true;
	}else
		return false;
}
int main(){
	freopen("testIn_A1112.txt", "r", stdin);
	scanf("%d", &n);
	char c = getchar();
	gets(str);
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		int id = change(str[i]);
		if(isR(str, n, i) == true){
			if(hashTable[id] == false && current[id] == false){
				hashTable[id] == true;
				ans += str[i];
			}else if(hashTable[id] == false && current[id] == true){
				ans += str[i];	
			}else if(hashTable[id] == true && current[id] == true){
				i += n - 1;
				ans += str[i];
			}
		}
		else if(isR(str, n, i) == false && hashTable[id] == false && current[id] == false){
				current[id] = true;
				ans += str[i];
		}
	}
	for(int i = 0; i < 40; i++){
		if(hashTable[i] == true)
			printf("%d", i);
	}
	printf("\n");
	cout<<"ANS"<<ans;
	fclose(stdin);
	return 0;
}
