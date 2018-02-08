//PATA_1079 Total Sales of Supply Chain
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
struct Node{
	double data;
	vector<int> child;
}node[maxn];
int n;
double p, r, total = 0;
void preorder(int index, int depth){
	if(node[index].child.size() == 0){
		total += node[index].data * pow(1 + r, depth);
		return;
	}
	for(int i = 0; i < node[index].child.size(); i++){
		preorder(node[index].child[i], depth + 1);
	}
}
int main(){
	freopen("testIn_A1079.txt", "r", stdin);
	int k, child;
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++){
		scanf("%d", &k);
		if(k == 0){
			scanf("%lf", &node[i].data);
		}else{
			for(int j = 0; j < k; j++){
				scanf("%d", &child);
				node[i].child.push_back(child);
			}
		}
	}
	preorder(0, 0);
	printf("%.1f\n", p * total);
	fclose(stdin);
	return 0;
}
