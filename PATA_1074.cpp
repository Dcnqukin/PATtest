//PATA_1074 Reversing Linked List
#include <cstdio>
#include <iostream>
#include <algorithm>
const int maxn = 100010;
using namespace std;
struct Node{
	int address, data, next;
	int order;
	Node(){
		order = maxn;
	}
}node[maxn];
bool cmp(Node a, Node b){
	return a.order < b.order;
}
int main(){
	freopen("testIn_A1074.txt", "r", stdin);
	int begin, n, k;
	scanf("%d%d%d", &begin, &n, &k);
	int address, data, next;
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &address, &data, &next);
		node[address].address = address;
		node[address].data = data;
		node[address].next = next;
	}
	int order = 0;
	address = begin;
	while(address != -1){
		node[address].order = order++;
		address = node[address].next;
	}
	sort(node, node + maxn, cmp);
	n = order;
	for(int i = 0; i < n/k ; i++){
		for(int j = (i + 1) * k - 1; j > i * k; j--)
			printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address);
		printf("%05d %d ", node[i * k].address, node[i * k].data);
		if(i < n/k - 1)
		printf("%05d\n", node[(i + 2) * k - 1].address);
		else{
			if( n % k == 0){
				printf("-1\n");
			}else{
				printf("%05d\n", node[(i + 1)*k].address);
				for(int i = n / k * k; i < n; i++){
					printf("%05d %d ", node[i].address, node[i].data);
					if( i < n - 1)
					printf("%05d\n", node[i + 1].address);
					else
					printf("-1\n");
				}
			}
		}
	}
	fclose(stdin);
	return 0;
}
