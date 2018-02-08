//PATA_1051 Pop Sequence
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 1010;
int arr[maxn];
stack<int> s;
int m, n, k;
int main(){
	freopen("testIn_A1051.txt", "r", stdin);
	scanf("%d%d%d", &m, &n, &k);
	while(k--){
		while(!s.empty())
			s.pop();
		for(int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);
		int current = 1;
		bool flag = true;
		for(int i = 1; i <= n; i++){
			s.push(i);
			if(s.size() > m){
				flag = false;
				break;
			}
			while(!s.empty() && s.top() == arr[current]){
				s.pop();
				current++;
			}
		}
		if(s.empty() == true && flag == true)
			printf("YES\n");
		else
			printf("NO\n");
	}
	fclose(stdin);
	return 0;
}
