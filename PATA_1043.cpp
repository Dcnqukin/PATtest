#include <cstdio>
#include <vector>
using namespace std;
struct Node{
	int data;
	Node* lchild;
	Node* rchild;
};

void insert(Node* &root, int data){
	if(root == NULL){
		root = new Node;
		root->data = data;
		root->lchild = root->rchild = NULL;
		return;
	}
	else if(data < root->data && root != NULL) insert(root->lchild, data);
	else if(data >= root->data && root != NULL) insert(root->rchild, data);
}

void preOrder(Node* root, vector<int>&vi){
	if(root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->lchild, vi);
	preOrder(root->rchild, vi);
}

void preOrderMirror(Node* root, vector<int>&vi){
	if(root == NULL) return;
	vi.push_back(root->data);
	preOrderMirror(root->rchild, vi);
	preOrderMirror(root->lchild, vi);
}

void postOrder(Node* root, vector<int>&vi){
	if(root == NULL) return;
	postOrder(root->lchild, vi);
	postOrder(root->rchild, vi);
	vi.push_back(root->data);
}

void postOrderMirror(Node* root, vector<int>&vi){
	if(root == NULL) return;
	postOrderMirror(root->rchild, vi);
	postOrderMirror(root->lchild, vi);
	vi.push_back(root->data);
}

vector<int> origin, pre, preM, post, postM;
int main(){
	freopen("testIn_A1043.txt", "r", stdin);
	int n, data;
	Node* root = NULL;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &data);
		origin.push_back(data);
		insert(root, data);
	}
	
	preOrder(root, pre);
	preOrderMirror(root, preM);
	postOrder(root, post);
	postOrderMirror(root, postM);
	if(origin == pre){
		printf("YES\n");
		for(int i = 0; i < post.size(); i++){
			printf("%d", post[i]);
			if(i < post.size() - 1) printf(" ");
		}
	} else if(origin == preM){
		printf("YES\n");
		for(int i = 0; i < postM.size(); i++){
			printf("%d", postM[i]);
			if(i < postM.size() - 1) printf(" ");
		}
	} else{
		printf("NO\n");
	}
	fclose(stdin);
	return 0;
}
