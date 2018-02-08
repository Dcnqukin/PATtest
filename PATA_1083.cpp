//PATA_1083 List Grades
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1010;
struct Stu{
	char name[12];
	char id[12];
	int grade;
}stu[maxn];
bool cmp(Stu a, Stu b){
	return a.grade > b.grade;
}
int main(){
	freopen("testIn_A1083.txt", "r", stdin);
	int n, L, R;
	scanf("%d", &n);
	getchar();
	for(int i = 0; i < n; i++){
		scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
	}
	scanf("%d%d", &L, &R);
	sort(stu, stu + n, cmp);
	bool flag = false;
	for(int i = 0; i < n; i++){
		if(stu[i].grade >= L && stu[i].grade <= R){
			printf("%s %s\n", stu[i].name, stu[i].id);
			flag = true;
		}
	}
	if(flag == false)
		printf("NONE\n");
	fclose(stdin);
	return 0;
}
