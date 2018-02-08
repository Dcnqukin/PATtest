//PATA_1011 World Cup Betting
#include <cstdio>
#include <map>
using namespace std;
map<double, char> mp[3];
int main(){
	freopen("testIn_A1011.txt", "r", stdin);
	double w, t, l;
	double ans = 1.0;
	for(int i = 0; i < 3; i++){
		scanf("%lf%lf%lf", &w, &t, &l);
		mp[i][w] = 'W';
		mp[i][t] = 'T';
		mp[i][l] = 'L';
	}
	map<double, char>::iterator it;
	for(int i = 0; i < 3; i++){
		it = mp[i].begin();
		it++;
		it++;
		ans *= it->first;
		printf("%c ", it->second);
	}
	ans = (ans*0.65 - 1)*2;
	printf("%.2f\n", ans);
	fclose(stdin);
	return 0;
}
