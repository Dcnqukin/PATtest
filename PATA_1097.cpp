//PATA_1097 Deduplication on a Linked List
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100005;
const int TABLE = 100010;
struct Node{
	int address, data, next;
	int order;
}node[maxn];
bool isExist[TABLE] = {false};
bool cmp(Node a, Node b){
	return a.order < b.order;
}

int main(){
	memset(isExist, false, sizeof(isExist));
	int begin, n, address;
	scanf("%d%d", &begin, &n);
	for(int i = 0; i < maxn; i++)
		node[i].order = 2*maxn;
	for(int i = 0; i < maxn; i++){
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;
	}
	int p = begin, countValid = 0, countRemoved = 0;
	while(p != -1){
		if(!isExist[abs(node[p].data)]){
			isExist[abs(node[p].data)] = true;
			node[p].order = countValid++;
		}
		else
			node[p].order = maxn + countRemoved++;
		p = node[p].next; 
	}
	int count = countValid + countRemoved;
	if( count == 0){
		printf("0 -1\n");
	}else{
		sort(node, node + maxn, cmp);
		for(int i = 0; i < count; i++)
		{
			if(i != countValid - 1 && i != count -1)
				printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
			else
				printf("%05d %d -1\n", node[i].address, node[i].data);
		}
	}
	return 0;
}
