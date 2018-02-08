//PATA_1077 Kuchiguse
#include <iostream>
#include <string>
#include <algorithm>
#define maxn 110
using namespace std;
string str[maxn];
int main(){
	freopen("testIn_A1077.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	int mlen = 1e12;
	int ans = 0;
	getchar();
	for(int i = 0; i < n; i++){
		getline(cin, str[i]);
		reverse(str[i].begin(), str[i].end());
		if(str[i].length() < mlen)
			mlen = str[i].length();
	}
	for(int i = 0; i < mlen; i++){
		char c = str[0][i];
		bool same = true;
		for(int j = 1; j < n; j++)
			if(str[j][i] != c){
				same = false;
				break;
			}
		if(same) ans++;
		else break;
	}
	if(ans){
		for(int i = ans - 1; i >= 0; i--){
			printf("%c", str[0][i]);
		}
	}else{
		printf("nai");
	}
	fclose(stdin);
	return 0;
}
