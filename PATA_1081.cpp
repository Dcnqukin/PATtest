//PATA_1081 Rational Sum
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Fraction{
	ll up, down;
};
ll gcd(ll a, ll b){
	return b == 0? a : gcd(b, a%b);
}
Fraction reduction(Fraction result){
	if(result.up == 0){
		result.down = 1;
	}else {
		ll d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
}
Fraction add(Fraction a, Fraction b){
	Fraction result;
	result.up = a.up*b.down + a.down*b.up;
	result.down = a.down*b.down;
	return reduction(result);
}

void showResult(Fraction result){
	result = reduction(result);
	if(result.down == 1) printf("%lld\n", result.up);
	else if(abs(result.up) > result.down){
		printf("%lld %lld/%lld\n", result.up / result.down, abs(result.up) % result.down, result.down);		
	}else {
		printf("%lld/%lld\n", result.up, result.down);
	}
}

int main(){
	freopen("testIn_A1081.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	Fraction sum, temp;
	sum.up = 0; sum.down = 1;
	for(int i = 0; i < n; i++){
		scanf("%lld/%lld", &temp.up, &temp.down);
		sum = add(sum, temp);
	}
	showResult(sum);
	fclose(stdin);
	return 0;
}
