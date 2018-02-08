//PATA_1133 Splitting A Linked List
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100010;
//const int INF = 1e9 + 7;
vector<int> v[4];
struct List{
	int address, data, next;
	int order;
	int flag;
	List(){
		order = maxn;
	}
}node[maxn];
int main(){
	freopen("testIn_A1133.txt", "r", stdin);
	int begin, n, right;
	scanf("%d%d%d", &begin, &n, &right);
	int address;
	for(int i = 0; i < n; i++){
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;
	}
	int p = begin;
	while(p != -1){
		if(node[p].data < 0) v[0].push_back(p);
		else if(node[p].data <= right) v[1].push_back(p);
		else v[2].push_back(p);
		p = node[p].next;
	}

	int flag = 0;  
    for (int i = 0; i < 3; i++) {  
        for (int j = 0; j < v[i].size(); j++) {  
            if (flag == 0) {  
                printf("%05d %d ", v[i][j], node[v[i][j]].data);  
                flag = 1;  
            } else {  
                printf("%05d\n%05d %d ", v[i][j], v[i][j], node[v[i][j]].data);  
            }  
        }  
    }  
    printf("-1");
	return 0;
}
