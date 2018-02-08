#include <cstdio>
#include <set>
using namespace std;
const int maxn = 51;
set<int> S[maxn];
void compare(int a, int b){
	int same = 0, totalNum = S[b].size();
	set<int>::iterator it;
	for(it = S[a].begin(); it != S[a].end(); it++){
		if(S[b].find(*it) != S[b].end()) same++;
		else totalNum++;
	}
	printf("%.1f%\n", same * 100.0 / totalNum);
}
int main(){
	freopen("testIn_A1063.txt", "r", stdin);
	int n, m, k, a, b, temp;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &m);
		for(int j = 0; j < m; j++){
			scanf("%d", &temp);
			S[i].insert(temp);
		}
	}
	scanf("%d", &k);
	while(k--){
		scanf("%d%d", &a, &b);
		compare(a, b);
	}
	return 0;
}
