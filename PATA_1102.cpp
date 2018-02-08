//PATA_1102 Invert a Binary Tree
//Data Structure: Static Binary List
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 110;
struct Node{
	int data;
	int lchild, rchild;
}node[maxn];
bool notRoot[maxn] = {false};
int n, num = 0;
void print(int id){
	printf("%d", id);
	num++;
	if(num < n) printf(" ");
	else printf("\n");
}

//level-order
void levelorder(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		print(x);
		if(node[x].lchild != -1) q.push(node[x].lchild);
		if(node[x].rchild != -1) q.push(node[x].rchild);
	}
}

//in-order
void inorder(int root){
	if( root == -1)
		return;
	inorder(node[root].lchild);
	print(root);
	inorder(node[root].rchild);
}

//post-order 
void postorder(int root){
	if( root == -1)
		return;
	postorder(node[root].lchild);
	postorder(node[root].rchild);
	swap(node[root].lchild, node[root].rchild);
}

int strToNum(char c){
	if( c == '-') return -1;
	else{
		notRoot[c - '0'] = true;
		return c - '0';
	}
}

int findRoot(){
	for(int i = 0; i < n; i++)
		if(notRoot[i] == false)
			return i;	
}

int main(){
	freopen("testIn_A1102.txt", "r", stdin);
	scanf("%d", &n);
	char lchild, rchild;
	for(int i = 0; i < n; i++){
		scanf("%*c%c %c", &lchild, &rchild);
		node[i].lchild = strToNum(lchild);
		node[i].rchild = strToNum(rchild);
	}
	int root = findRoot();
	postorder(root);
	levelorder(root);
	num = 0;
	inorder(root);
	
	fclose(stdin);
	return 0;
}
