//PATA_1104 Sum of Number Segments
#include <cstdio>
int main(){
	int n;
	double v, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lf", &v);
		ans += v * i * (n + 1 - i);
	}
	printf("%.2f\n", ans);
	return 0;
}
