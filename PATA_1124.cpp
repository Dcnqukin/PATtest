//PATA_1124 Raffle for Weibo Followers
#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 1010;
string str[maxn];
map<string, bool> mp;
map<string, bool>::iterator it;
int main(){
	freopen("testIn_A1124.txt", "r", stdin);
	int m, n, s;
	scanf("%d%d%d", &m, &n, &s);
	for(int i = 0; i < m; i++){
		cin>>str[i];
		mp[str[i]] = false;
	}
	if(m < s)
		cout<<"Keep going..."<<endl;
	else{
		for(int i = s - 1; i < m; i += n){
			it = mp.find(str[i]);
			if(it->second == true){
				i -=n;
				i++;
			}
			else
			{
				cout<<str[i]<<endl;
				it->second = true;
			}
		}
	}
	fclose(stdin);
	return 0;
}
