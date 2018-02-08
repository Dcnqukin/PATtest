//PATA_1088 Rational Arithmetic
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
struct Fraction{
	ll up, down;
};
vector<Fraction> ans;
char sign[4] = {'+', '-', '*', '/'};
ll gcd(ll a, ll b){
	return (b == 0)? a : gcd(b, a % b);
}
Fraction reduction(Fraction r){
	if(r.up == 0){
		r.down = 1;
	}else{
		ll d = gcd(abs(r.up), abs(r.down));
		r.up /= d;
		r.down /= d;
	}
	return r;
}
Fraction add(Fraction a, Fraction b){
	Fraction r;
	r.up = a.up*b.down + a.down*b.up;
	r.down = a.down*b.down;
	return reduction(r);
}
Fraction minu(Fraction a, Fraction b){
	Fraction r;
	r.up = a.up*b.down - a.down*b.up;
	r.down = a.down*b.down;
	return reduction(r);
}
Fraction multi(Fraction a, Fraction b){
	Fraction r;
	r.up = a.up * b.up;
	r.down = a.down * b.down;
	return reduction(r);
}
Fraction divide(Fraction a, Fraction b){
	Fraction r;
	r.up = a.up * b.down;
	r.down = a.down * b.up;
	if(r.down < 0){
		r.up = -r.up;
		r.down = -r.down;
	}
	return reduction(r);
}
void showResult(Fraction r){
	r = reduction(r);
	if(r.up >= 0){
		if(r.down == 1) printf("%lld", r.up);
		else if(abs(r.up) > r.down){
			printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
		}else{
			printf("%d/%d", r.up, r.down);
		}
	}else if(r.up < 0){
		if(r.down == 1) printf("(%lld)", r.up);
		else if(abs(r.up) > r.down){
			printf("(%lld %lld/%lld)", r.up / r.down, abs(r.up) % r.down, r.down);
		}else{
			printf("(%d/%d)", r.up, r.down);
		}
	}
}
int main(){
	Fraction a, b;
	scanf("%lld/%lld%lld/%lld", &a.up, &a.down, &b.up, &b.down);
	ans.push_back(add(a, b));
	ans.push_back(minu(a, b));
	ans.push_back(multi(a, b));
	if(b.up != 0)
	ans.push_back(divide(a, b));
	for(int i = 0; i < 4; i++){
		showResult(a);
		cout<<" "<<sign[i]<<" ";
		showResult(b);
		cout<<" = ";
		if(b.up == 0 && i == 3)
		cout<<"Inf";
		else showResult(ans[i]);
		cout<<endl;
	}
	return 0;
}
