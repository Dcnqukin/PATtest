//PATA_1075 PAT Judge
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int n, k, m, temp;
vector<int> p;
struct Stu{
	int id;
	int s[5];
	int flag;
	bool g;
	int sum;
	Stu(){
		id = 100000;
		memset(s, -1, sizeof(s));
		flag = 0;
		g = false;
		sum = 0;
	}
}stu[maxn];
bool cmp(Stu a, Stu b){
	if(a.sum != b.sum) return a.sum > b.sum;
	else if(a.flag != b.flag) return a.flag > b.flag;
	else return a.id < b.id;
}
bool cmp1(Stu a, Stu b){
	return a.id < b.id;
}
void print(Stu a){
	printf(" %d", a.sum);
	for(int i = 0; i < k; i++){
		if(a.s[i] == -1)
			printf(" -");
		else
			printf(" %d", a.s[i]);
	}
	printf("\n");
}
int main(){
	freopen("testIn_A1075.txt", "r", stdin);
	scanf("%d%d%d", &n, &k, &m);
	for(int i = 0; i < k; i++){
		scanf("%d", &temp);
		p.push_back(temp);
	}
	for(int i = 0; i < m; i++){
		int uid,pid, ps;
		scanf("%d%d%d", &uid, &pid, &ps);
		if(stu[uid].s[pid - 1] < ps)
		{
			stu[uid].s[pid - 1] = ps;
			stu[uid].g = true;
		}
		if(ps == -1 && stu[uid].s[pid - 1] == -1) //测试点5错误原因是，某人第一次提交成功，但第二次编译不成功，被覆盖。 
		stu[uid].s[pid - 1] = 0; 
		stu[uid].id = uid;
	}
	sort(stu, stu + maxn, cmp1);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 5; j++){
			if(stu[i].s[j] >= 0)
			stu[i].sum += stu[i].s[j];
			if(stu[i].s[j] == p[j])
				stu[i].flag++;
		}
	}
	sort(stu, stu + maxn, cmp);
	int rank = 1, score = stu[0].sum;
	for(int i = 0; i < n; i++){
		if(stu[i].sum == 0 && stu[i].g == false)
			break;
		else{
			if(stu[i].sum == score){
				printf("%d %05d", rank, stu[i].id);
				print(stu[i]);
			}
			else{
				rank = i + 1;
				score = stu[i].sum;
				printf("%d %05d", rank, stu[i].id);
				print(stu[i]);
			}
		}
	}
	fclose(stdin);
	return 0;
}
