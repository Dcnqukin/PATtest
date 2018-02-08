//PATA_1053 Path of Equal Weight
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 110;
struct Node{
	int weight;
	vector<int> child;
}node[maxn];
bool cmp(int a, int b){
	return node[a].weight > node[b].weight;
}
//preorder: calculating sum of weights

int n, m, S;
int path[maxn];
void preorder(int index, int numNode, int sum){
	if(sum > S) return;
	if(sum == S){
		if(node[index].child.size() != 0)	return;
		for(int i = 0; i < numNode; i++){
			printf("%d", node[path[i]].weight);
			if(i < numNode - 1) printf(" ");
			else	printf("\n");
		}
		return;
	}
	for(int i = 0; i < node[index].child.size(); i++){
		int child = node[index].child[i];
		path[numNode] = child;
		preorder(child, numNode + 1, sum + node[child].weight);
	}
}

int main(){
	freopen("testIn_A1053.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &S);
	for(int i = 0; i < n; i++)
		scanf("%d", &node[i].weight);
	int id, k, child;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &id, &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &child);
			node[id].child.push_back(child);
		}
		sort(node[id].child.begin(), node[id].child.end(), cmp);
	}
	path[0] = 0;
	preorder(0, 1, node[0].weight);
	fclose(stdin);
	return 0;
}

