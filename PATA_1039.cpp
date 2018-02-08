//PATA_1039 Course List for Student
//Using map STL may result in a timeout
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 40005;
const int maxm = 26*26*26*10+1;
vector<int> selectCourse[maxm];

int getID(char name[]){
	int id = 0;
	for(int i = 0; i < 3; i++)
		id = id*26 + (name[i] - 'A');
	id = id*10 + (name[3] - '0');
	return id;
}

int main(){
	freopen("testIn_A1039.txt", "r", stdin);
	freopen("testOut_A1039.txt", "w", stdout);
	char name[5];
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < k; i++){
		int course, x;
		scanf("%d%d", &course, &x);
		for(int j = 0; j < x; j++){
			scanf("%s", name);
			int id = getID(name);
			selectCourse[id].push_back(course);
		}
	}
	for(int i = 0; i < n; i++){
		scanf("%s",name);
		int id = getID(name);
		sort(selectCourse[id].begin(), selectCourse[id].end());
		printf("%s %d", name, selectCourse[id].size());
		for(int j = 0; j < selectCourse[id].size(); j++)
			printf(" %d",selectCourse[id][j]);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
