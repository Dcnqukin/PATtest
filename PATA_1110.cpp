//PATA_1110 Complete Binary Tree
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 25;
struct Node{
	int lchild, rchild;
}node[maxn];
bool notRoot[maxn] = {false};
int n, last = 0, cnt = 0;
bool isComplete;
int strToNum(char str[]){
	if(str[0] == '-') return -1;
	else{
		int id;
		sscanf(str, "%d", &id);
		notRoot[id] = true;
		return id;
	}
}

int findRoot(){
	for(int i = 0; i < n; i++)
		if(notRoot[i] == false)
			return i;
}

//levelorder
bool isCBT(int root){
	queue<int> q;
	q.push(root);
	cnt++;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(node[now].lchild == -1){
			break;
		}else if(node[now].lchild != -1){
			cnt++;
			q.push(node[now].lchild);
			last = node[now].lchild;
		}
		if(node[now].rchild == -1){
			break;
		}else if(node[now].rchild != -1){
			cnt++;
			q.push(node[now].rchild);
			last = node[now].rchild;
		}
	}
	if(cnt < n) return false;
	else	return true;
}

int main(){
	freopen("testIn_A1110.txt", "r", stdin);
	char lchild[5], rchild[5];
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s %s", lchild, rchild);
		node[i].lchild = strToNum(lchild);
		node[i].rchild = strToNum(rchild);
	}
	int root = findRoot();
	isComplete = isCBT(root);
	if(isComplete == false)
		printf("NO %d\n", root);
	else
		printf("YES %d\n", last);
	fclose(stdin);
	return 0;
}
