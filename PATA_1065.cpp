//PATA_1065 A+B and C(64bit)
#include <cstdio>
int main(){
	int n, t = 1;
	scanf("%d", &n);
	while(n--){
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		long long res = a + b;
		bool flag;
		if(a > 0 && b > 0 && res < 0) flag = true;
		else if(a < 0 && b < 0 && res >= 0) flag = false;
		else if(res > c) flag = true;
		else flag = false;
		if(flag == true)
			printf("Case #%d: true\n", t++);
		else
			printf("Case #%d: false\n", t++);
	}
	return 0;
}
