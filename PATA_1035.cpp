//PATA_1035 Password
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
#define N 1010
struct Password{
	char user[N];
	char p[N];
	bool flag;
}t[N];
bool is(char c){
	if(c == '0' || c == '1' || c == 'l' || c == 'O')
		return true;
	return false;
}
void change(char &c){
	if(c == '0')
		c = '%';
	else if(c == '1')
		c = '@';
	else if(c == 'l')
		c = 'L';
	else if(c == 'O')
		c = 'o';
}
int main(){
	freopen("testIn_A1035.txt", "r", stdin);
	int n, len = 0, cnt = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", t[i].user);
		scanf("%s", t[i].p);
		t[i].flag = true;
	}
	for(int i = 0; i < n; i++){
		int slen = strlen(t[i].p);
		for(int j = 0; j < slen; j++){
			if(is(t[i].p[j]) == true)
				change(t[i].p[j]);
			else len++;
		}
		if(len == slen){
			t[i].flag = false;
			cnt++;
		}
		len = 0;
	}
	if(cnt == n){
		if(n == 1)
			printf("There is %d account and no account is modified", cnt);
		else
			printf("There are %d accounts and no account is modified", cnt);
	}
	else{
		printf("%d\n", n - cnt);
		for(int i = 0; i < n; i++){
			if(t[i].flag == true)
			printf("%s %s\n", t[i].user, t[i].p);
		}
	}
	fclose(stdin);
	return 0;
}
