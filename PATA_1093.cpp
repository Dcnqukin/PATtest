//PATA_1093 Count PAT's
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
const int modnum = 1e9 + 7;
int LeftNum[maxn] = {0};
int RightNum[maxn] = {0};
int main(){
	char str[maxn];
	gets(str);
	int len = strlen(str);
	int ans = 0, j = 0;
	if(str[j] =='P')
			LeftNum[j] = 1;
	else
			LeftNum[j] = 0;
	for(int i = 1; i < len; i++){
		if(str[i] != 'P')
			LeftNum[i] = LeftNum[i - 1];
		else
			LeftNum[i] = LeftNum[i - 1] + 1;
	}
	j = len - 1;
	if(str[j] == 'T')
		RightNum[j] = 1;
	else
		RightNum[j] = 0;
	for(int i = len - 2; i >= 0; i--){
		if(str[i] != 'T')
			RightNum[i] = RightNum[i + 1];
		else
			RightNum[i] = RightNum[i + 1] + 1;
	}
	for(int i = 0; i < len; i++){
		if(str[i] == 'A')
		ans += RightNum[i] * LeftNum[i];
		if(ans > modnum)
			ans = ans % modnum;
	}
	printf("%d\n", ans);
	return 0;
}
