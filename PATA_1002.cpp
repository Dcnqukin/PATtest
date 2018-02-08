#PATA_1002 A+B for Polynomials
---
```
#include <cstdio>
#include <algorithm>
#include <cmath> 
using namespace std;
const int maxn = 1010;
double e[maxn] = {};
int main(){
	freopen("testIn_A1002.txt", "r", stdin);//用于读入文件
	int k, n, num = 0;
	double a;
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		scanf("%d %lf", &n, &a);
		e[n] += a;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		scanf("%d %lf", &n, &a);
		e[n] += a;
	}
	for(int i = 0; i < maxn; i++){
		if(e[i] != 0.0)
			num++;
	}
	printf("%d", num);
	for(int i = maxn - 1; i >= 0; i--)
	{
		if(e[i] != 0.0){
			printf(" %d ", i);
			printf("%.1f", e[i]);
		}
	}
	fclose(stdin);
	return 0;
}
```
**输入文件如下：**
---
2 1 2.4 0 3.2
2 2 1.5 1 0.5

**输出结果如下：**
3 2 1.5 1 2.9 0 3.2
