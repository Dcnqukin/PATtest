//PATA_1062 Talent and Virtue
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 100010
using namespace std;
struct Man{
	char s[10];
	int v, t, sum;
	int flag; 
}man[maxn];
int L, H, g;
bool cmp(Man a, Man b){
	if(a.flag != b.flag) return a.flag < b.flag;
	else if(a.sum != b.sum) return a.sum > b.sum;
	else if(a.v != b.v) return a.v > b.v;
	else return strcmp(a.s, b.s) < 0;
}
void SetFlag(Man &M){
	if(M.v < L || M.t < L){
		M.flag = 5;
		g--;
	} 
	else if(M.v >= H && M.t >= H)	M.flag = 1;
	else if(M.v >= H && M.t < H) M.flag = 2;
	else if(M.v >= M.t) M.flag = 3;
	else M.flag = 4;
}
int main(){
	freopen("testIn_A1062.txt", "r", stdin);
	int n;
	scanf("%d%d%d", &n, &L, &H);
	g = n;
	for(int i = 0; i < n; i++){
		scanf("%s%d%d", man[i].s, &man[i].v, &man[i].t);
		man[i].sum = man[i].v + man[i].t;
		SetFlag(man[i]);
	}
	sort(man, man + n, cmp);
	printf("%d\n", g);
	for(int i = 0; i < g; i++){
		printf("%s %d %d\n", man[i].s, man[i].v, man[i].t);
	}
	fclose(stdin);
	return 0;
}
