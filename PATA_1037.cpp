//PATA_1037 Magic Coupon
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
typedef long long LL;
LL coupon[maxn], product[maxn];
int main(){
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &coupon[i]);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%lld", &product[i]);
	}
	sort(coupon, coupon + n);
	sort(product, product + m);
	int i = 0, j;
	LL ans = 0;
	while(i < n && i < m && coupon[i] < 0 && product[i] < 0){
		ans += coupon[i] * product[i];
		i++;
	}
	i = n - 1;
	j = m - 1;
	while(i >= 0 && j >= 0 && coupon[i] > 0 && product[j] > 0){
		ans += coupon[i] * product[j];
		i--, j--;
	}
	printf("%lld\n", ans);
	return 0;
}
