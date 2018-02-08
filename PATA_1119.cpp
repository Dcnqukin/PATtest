//PATA_1119 Pre- and Post-order Traversals
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn =50;
struct Node{
	int data;
	Node* lchild;
	Node* rchild;
};
int pre[maxn], post[maxn];
int n, index = 0;
bool flag = true;
Node* create(int preL, int preR, int postL, int postR){
	if(preL > preR)
		return NULL;
	Node* root = new Node;
	root->data = pre[preL];
	root->lchild = NULL;
	root->rchild = NULL;
	if(preL == preR)
		return root;
	int k = 0;
	for(k = preL + 1; k <= preR; k++)
		if(pre[k] == post[postR - 1]) break;
	if(k - preL > 1){
		root->lchild = create(preL + 1, k - 1, postL, postL + k - preL - 2);
		root->rchild = create(k, preR, postL + k - preL - 1, postR - 1);
	}
	else{
		flag = false;
		root->rchild = create(k, preR, postL + k - preL - 1, postR - 1);
	}
	return root;
}

void inorder(Node* root){
	if(root == NULL) return;
	inorder(root->lchild);
	if(index < n - 1)
		printf("%d ", root->data);
	else printf("%d\n", root->data);
	index++;
	inorder(root->rchild);
}

int main(){
	freopen("testIn_A1119.txt", "r", stdin);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &pre[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &post[i]);
	}
	Node* root = create(0, n - 1, 0, n - 1);
	if(flag == true){
		printf("Yes\n");
		inorder(root);
	}
	else{
		printf("No\n");
		inorder(root);
	}
	fclose(stdin);
	return 0;
}
