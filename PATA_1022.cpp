//PATA_1022 Digital Library
#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

map<string, set<int> > mpTitle, mpAuthor, mpKey, mpPub, mpYear;

void query(map<string, set<int> >& mp, string& str){
	if(mp.find(str) == mp.end()) printf("Not Found\n");
	else{
		for(set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++){
			printf("%07d\n", *it);
		}
	}
}

int main(){
	freopen("testIn_A1022.txt", "r", stdin);
	int n, number;
	string title, author, key, pub, year;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &number);
		char c = getchar();
		getline(cin, title);
		mpTitle[title].insert(number);
		getline(cin, author);
		mpAuthor[author].insert(number);
		while( cin>> key){
			mpKey[key].insert(number);
			c = getchar();
			if(c == '\n') break;
		}
		getline(cin, pub);
		mpPub[pub].insert(number);
		getline(cin, year);
		mpYear[year].insert(number);
	}
	int m, type;
	string temp;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d: ", &type);
		getline(cin, temp);
		cout<<type<<": "<<temp<<endl;
		switch(type){
			case 1: {
				query(mpTitle, temp);
				break;
			}
			case 2:{
				query(mpAuthor, temp);
				break;
			} 
			case 3:{
				query(mpKey, temp);
				break;
			}
			case 4:{
				query(mpPub, temp);
				break;
			}
			case 5:{
				query(mpYear, temp);
				break;
			}
		}
	}
	fclose(stdin);
	return 0;
}
