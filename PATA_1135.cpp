//PATA_1135 Is It A Red-Black Tree
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#define RED true
#define BLACK false
using namespace std;
const int maxn = 50;
struct RBnode{
	int data;
	RBnode* parent;
	RBnode* lchild;
	RBnode* rchild;
	bool color;// if the node's color is red, we set the variable value true;
};
void insert(RBnode* &root, RBnode* parent, int data){
	if(root == NULL){
		root = new RBnode;
		root->data = abs(data);
		root->lchild = root->rchild = NULL;
		root->parent = parent;
		if(data < 0) root->color = true;
		else root->color = false;
		return;
	}
	if(abs(data) < root->data) insert(root->lchild, root, data);
	else insert(root->rchild, root, data);
}

bool is_RBT(RBnode* root, int cnt, int curcnt){
	if(root->lchild == NULL && root->rchild == NULL){
		if(root->color == RED) return false;
		if(cnt != curcnt) return false;
	}
	if(root->lchild->color == root->color || root->rchild->color == root->color) return false;
	if(root->color == BLACK){
		curcnt++;
		cnt++;
	}
	if(root->color == RED) cnt--;
	if(root->lchild != NULL) is_RBT(root->lchild, cnt+1, curcnt);
	if(root->rchild != NULL) is_RBT(root->rchild, cnt+1, curcnt);
	return true;
}

void print(bool t){
	if(t == true) printf("Yes\n");
	else printf("No\n");
}

int main(){
	freopen("testIn_A1135.txt", "r", stdin);
	int n, k, data;
	scanf("%d", &k);
	while(k--){
		RBnode* root;
		RBnode* head;
		head->color = RED;
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &data);
			insert(root, head, data);
		}
	//	bool is_RedBlackTree = is_RBT(root, 0, 0);
	//	print(is_RedBlackTree);
	}
	fclose(stdin);
	return 0;
}
