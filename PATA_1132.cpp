//PATA_1132 Cut Integer
#include <cstdio>
#include <cstring>
#define maxn 32
typedef unsigned long long ULL;
ULL multi, z = 0, a = 0, b = 0;
char t[maxn];
int main(){
	freopen("testIn_A1132.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	char c = getchar();
	for(int i = 0; i < n; i++){
		memset(t, '\0', sizeof(t));
		gets(t);
		int len = strlen(t);
		z = 0, a = 0, b = 0;
		for(int j = 0; j < len; j++){
			z = z * 10 + (t[j] - '0');
			if(j < len/2)
				a = a*10 + (t[j] - '0');
			else
				b = b*10 + (t[j] - '0');
		}
		multi = a * b;
		if(z == 0 || multi == 0)printf("No\n");
		else{
			if(z % multi == 0)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	fclose(stdin);
	return 0;
}
