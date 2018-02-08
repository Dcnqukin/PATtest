//PATA_1138 Postorder Traversal
//输入前序序列和中序序列，输出后序序列的第一个结点
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 50010;
struct Node{
	int data;
	Node* lchild;
	Node* rchild;
};
int pre[maxn], in[maxn];
int n;
vector<int> post;
Node* create(int preL, int preR, int inL, int inR){
	if(preL > preR)
		return NULL;
	Node* root = new Node;
	root->data = pre[preL];
	int k = inL;
	for(;k <= inR; k++){
		if(in[k] == pre[preL]) break;
	}
	int numLeft = k - inL;
	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
	root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
	return root;
}

void Postorder(Node* root){
	if(root == NULL) return;
	Postorder(root->lchild);
	Postorder(root->rchild);
	post.push_back(root->data);
}

int main(){
	freopen("testIn_A1138.txt", "r", stdin);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &pre[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &in[i]);
	Node* root = create(0, n - 1, 0, n - 1);
	Postorder(root);
	printf("%d\n", post[0]);
	fclose(stdin);
	return 0;
}
