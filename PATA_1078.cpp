//PATA_1078 Hashing
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int N = 11111;
int prime[N], cnt = 0;
bool vis[N] = {0};
void FindPrime(){		//Euler
 	cnt = 0;
 	for(int i = 2; i < N; i++){
 		if(!vis[i])
 			prime[cnt++] = i;
 		for(int j = 0; j < cnt && i * prime[j] < N; j++){
 			vis[i * prime[j]] = true;
 			if(i % prime[j] == 0)
 				break;
		 }
	 }
}
int isPrime(int n){
	int i;
	for(i = 0; i < N; i++)
		if(n >= prime[i] && prime[i+1] >= n)
		break;
	return prime[i + 1];
}
bool hashTable[N] = {0};
int main(){
	FindPrime();
	int n, TSize, a;
	scanf("%d%d", &TSize, &n);
	TSize = isPrime(TSize);
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		int M = a % TSize;
		if(hashTable[M] == false){
			hashTable[M] = true;
			if(i == 0) printf("%d", M);
			else printf(" %d", M);
		}else{
			int step;
			for(step = 1; step < TSize; step++){
				M = (a + step*step)%TSize;
				if(hashTable[M] == false)
				{
					hashTable[M] = true;
					if(i == 0) printf("%d", M);
					else printf(" %d", M);
					break;
				}
			}
			if(step >= TSize){
				if(i > 0) printf(" ");
				printf("-");
			} 
		}
	}
	return 0;
}
