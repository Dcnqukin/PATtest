//PATA_1008 Elevator
#include <cstdio>
#include <vector>
using namespace std;
vector<int> ele;
int sum;
int Elevator(int a, int b){
	if(a > b)
		return (a - b)*4;
	else if(a < b)
		return (b - a)*6;
	else if(a == b)
		return 0;
}
int main(){
//	freopen("testIn_A1008.txt", "r", stdin);
	int n, temp;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &temp);
		ele.push_back(temp);
	}
	sum = (ele[0] - 0)*6;
	for(int i = 0; i < n - 1; i++){
		sum += Elevator(ele[i], ele[i + 1]);
	}
	sum += n * 5;
	printf("%d\n", sum);
//	fclose(stdin);
	return 0;
}

/* 测试文件
3 2 3 1
输出结果
41
