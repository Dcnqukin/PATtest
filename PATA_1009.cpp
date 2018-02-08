//PATA_1009 Product of Polynomials
#include <cstdio>
const int maxn = 2050;
struct Poly{
	int exp;
	double cof;
}poly[1001];
double ans[maxn];
int main(){
	freopen("testIn_A1009.txt", "r", stdin);
	int n, m, num = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d %lf", &poly[i].exp, &poly[i].cof);
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int exp;
		double cof;
		scanf("%d %lf", &exp, &cof);
		for(int j = 0; j < n; j++)
			ans[exp +poly[j].exp] += (cof * poly[j].cof);
	}
	for(int i = 0; i < maxn; i++)
		if(ans[i] != 0.0)
			num++;
	printf("%d", num);
	for(int i = maxn - 1; i >= 0; i--)
		if(ans[i] != 0.0) printf(" %d %.1f", i, ans[i]);
	fclose(stdin);
	return 0;
}

/* 测试文件
2 1 2.4 0 3.2
2 2 1.5 1 0.5
输出结果
3 3 3.6 2 6.0 1 1.6
*/
