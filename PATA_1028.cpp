//PATA_1028 List Sorting
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Student{
	int id;
	string name;
	int grade;
}stu[maxn];

bool cmp1(Student a, Student b){
	return a.id < b.id;
}

bool cmp2(Student a, Student b){
	int s = a.name.compare(b.name);
	if(s != 0) return s < 0;
	else return a.id < b.id;
}

bool cmp3(Student a, Student b){
	if(a.grade != b.grade) return a.grade < b.grade;
	else return a.id < b.id;
}

int main(){
	freopen("testIn_A1028.txt", "r", stdin);
	int n, c;
	scanf("%d%d", &n, &c);
	for(int i = 0; i < n; i++){
		scanf("%d", &stu[i].id);
		char c = getchar();
		cin >> stu[i].name;
		scanf("%d", &stu[i].grade);
	}
	if(c == 1) sort(stu, stu + n, cmp1);
	else if(c == 2) sort(stu, stu + n, cmp2);
	else if(c == 3) sort(stu, stu + n, cmp3);
	for(int i = 0; i < n; i++){
		printf("%06d ", stu[i].id);
		cout<<stu[i].name;
		printf(" %d\n", stu[i].grade);
	}
	fclose(stdin);
	return 0;
}
