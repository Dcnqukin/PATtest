//PATA_1055 The World's Richest
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int Age[maxn] ={0};
struct Person{
	int age, worth;
	char name[10];
}ps[maxn], valid[maxn];
int n, k, m, Amin, Amax;
bool cmp(Person a, Person b){
	if(a.worth != b.worth) return a.worth > b.worth;
	else if(a.age != b.age) return a.age < b.age;
	else return strcmp(a.name, b.name) < 0;
}

int main(){
	freopen("testIn_A1055.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%s%d%d", ps[i].name, &ps[i].age, &ps[i].worth);
	}
	sort(ps, ps + n, cmp);
	int validNum = 0;
	for(int i = 0; i < n; i++){
		if(Age[ps[i].age]< 100){
			Age[ps[i].age]++;
			valid[validNum++] = ps[i];
		}
	}
	for(int i = 0; i < k; i++){
		scanf("%d%d%d", &m, &Amin, &Amax);
		printf("Case #%d:\n", i+1);
		int printNum = 0;
		for(int j = 0; j < validNum && printNum < m; j++){
			if(valid[j].age >= Amin && valid[j].age <= Amax){
				printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].worth);
				printNum++;
			}
		}
		if(printNum == 0)
			printf("None\n");
	}
	fclose(stdin);
	return 0;
}
