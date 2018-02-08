//PATA_1085 Perfect Sequence
//Algorithm: two pointers
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 100010;
int main(){
	freopen("testIn_A1085.txt", "r", stdin);
	int n, p, a[maxn];
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int i = 0, j = 0, count = 1;
	while(i < n && j < n){
		while(j < n && a[j] <= (LL) a[i] * p){
			count = max(count, j - i + 1);
			j++;
		}
		i++;
	}
	printf("%d\n", count);
	fclose(stdin);
	return 0;
}

