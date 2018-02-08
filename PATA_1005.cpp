//PATA_1005 Spell It Right
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <iostream>
#define maxn 110
using namespace std;
typedef long long LL;
char* number[11] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; 
char N[maxn];
LL sum;
void print(LL sum){
	vector<int> num;
	while(sum != 0){
		num.push_back(sum % 10);
		sum = sum / 10;
	}
	for(int i = num.size() - 1; i >= 0; i--){
		printf("%s", number[num[i]]);
		if(i != 0)
			printf(" ");
		else
			printf("\n");
	}	
}
int main(){
	scanf("%s", N);
	int len = strlen(N);
	sum = 0;
	for(int i = 0; i < len; i++){
		sum += (N[i] - '0');
	}
	if(sum == 0)
		printf("%s", number[0]);
	else
		print(sum);
	return 0;
}
