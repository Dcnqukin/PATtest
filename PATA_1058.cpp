//PATA_1058 A+B in Hogwarts
#include <cstdio>
#include <algorithm>
typedef long long LL;
using namespace std;
struct Hogwarts{
	LL G;
	int S;
	int K;
	Hogwarts(int g = 0, int s = 0, int k = 0){
		G = g;
		S = s;
		K = k;
	}
};
Hogwarts AaddB(Hogwarts a, Hogwarts b){
	Hogwarts r;
	r.K = a.K + b.K;
	if(r.K >= 29){
		r.S += 1;
		r.K -= 29;
	}
	r.S = a.S + b.S + r.S;
	if(r.S >= 17){
		r.G += 1;
		r.S -= 17;
	}
	r.G = a.G + b.G + r.G;
	return r;
}

int main(){
	freopen("testIn_A1058.txt", "r", stdin);
	Hogwarts A, B;
	scanf("%lld.%d.%d", &A.G, &A.S, &A.K);
	scanf("%lld.%d.%d", &B.G, &B.S, &B.K);
	Hogwarts R = AaddB(A,B);
	printf("%lld.%d.%d\n", R.G, R.S, R.K);
	fclose(stdin);
	return 0;
}
