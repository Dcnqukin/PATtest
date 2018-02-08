//PATA_1069 The Black Hole of Numbers
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
void to_array(int n, int num[]){
	for(int i = 0; i < 4; i++){
		num[i] = n % 10;
		n /= 10;
	}
}
int to_number(int num[]){
	int sum = 0;
	for(int i = 0; i < 4; i++){
		sum = sum * 10 + num[i];
	}
	return sum;
}
int main(){
	int n, MIN, MAX;
	int num[5];
	scanf("%d", &n);
	while(1){
		to_array(n, num);
		sort(num, num + 4);
		MIN = to_number(num);
		sort(num, num + 4, cmp);
		MAX = to_number(num);
		n = MAX - MIN;
		printf("%04d - %04d = %04d\n", MAX, MIN, n);
		if(n == 0 || n == 6174) break;
	}
	return 0;
}
//int main(){
//	int n, MIN, MAX, k, cnt, m;
//	int num[5];
//	for(int i = 0; i < 9999; i++){
//		cnt = 0, m = 0, n = i;
//	while(1){
//		to_array(n, num);
//		sort(num, num + 4);
//		MIN = to_number(num);
//		sort(num, num + 4, cmp);
//		MAX = to_number(num);
//		n = MAX - MIN;
//		//printf("%04d - %04d = %04d\n", MAX, MIN, n);
//		cnt++;
//		if(n == 0 || n == 6174) break;
//		}
//		if(m < cnt){
//			m = cnt;
//			k = i;
//		}
//		printf("%04d\n", i);
//	}
//	printf("%04d %04d", m, k);
//	return 0;
//}
