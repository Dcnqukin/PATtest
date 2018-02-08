//PATA_1090 Highest Price in Supply Chain
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 100010;
int n, num = 0, maxDepth = 0;
double p, r, total;
vector<int> child[maxn];
void preorder(int index, int depth){
	if(child[index].size() == 0){
		if(depth > maxDepth){
			maxDepth = depth;
			num = 1;
		}else if(depth == maxDepth)
			num++;
		return;
	}
	for(int i = 0; i < child[index].size(); i++){
		preorder( child[index][i], depth + 1);
	}
}
int main(){
	freopen("testIn_A1090.txt", "r", stdin);
	int father, root;
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++){
		scanf("%d", &father);
		if(father != -1)
			child[father].push_back(i);
		else
			root = i;
	}
	preorder(root, 0);
	printf("%.2f %d\n", p * pow(1 + r, maxDepth), num);
	fclose(stdin);
	return 0;
}
