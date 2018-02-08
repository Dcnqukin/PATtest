//PATA_1099 Build A Binary Search Tree
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;
struct Node{
	int data;
	int lchild, rchild;
}node[maxn];
int n, data, j = 0, num = 0;
queue<int> qlevel;
vector<int> vi;
void print(int id){
	printf("%d", id);
	num++;
	if(num < n) printf(" ");
	else printf("\n");
}

void inorder(int root){
	if(node[root].lchild != -1)
		inorder(node[root].lchild);
	node[root].data = vi[j];
	j++;
	if(node[root].rchild != -1)
		inorder(node[root].rchild);
}

void levelorder(int root){
	qlevel.push(root);
	while(!qlevel.empty()){
		int now = qlevel.front();
		qlevel.pop();
		print(node[now].data);
		if(node[now].lchild != -1) qlevel.push(node[now].lchild);
		if(node[now].rchild != -1) qlevel.push(node[now].rchild);
	}
}

int main(){
	freopen("testIn_A1099.txt", "r", stdin);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &node[i].lchild, &node[i].rchild);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &data);
		vi.push_back(data);
	}
	sort(vi.begin(), vi.end());
	inorder(0);
	levelorder(0);
	fclose(stdin);
	return 0;
}
