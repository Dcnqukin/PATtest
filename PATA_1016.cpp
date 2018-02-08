//PATA_1016 Phone Bills
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int toll[25];
const int maxn = 1010;
struct Record{
	string name;
	int month, dd, hh, mm;
	bool flag;
}rec[maxn],temp;
bool cmp(Record a, Record b){
	int s = a.name.compare(b.name);
	if(s != 0) return s < 0;
	else if(a.month != b.month) return a.month < b.month;
	else if(a.dd != b.dd) return a.dd < b.dd;
	else if(a.hh != b.hh) return a.hh < b.hh;
	else return a.mm < b.mm;
}

void getans(int on, int off, int& time, int& money){
	temp = rec[on];
	while(temp.dd < rec[off].dd || temp.hh < rec[off].hh || temp.mm < rec[off].mm){
		time ++;
		money += toll[temp.hh];
		temp.mm++;
		if(temp.mm >= 60){
			temp.mm = 0;
			temp.hh++;
		}
		if(temp.hh >= 24){
			temp.hh = 0;
			temp.dd++;
		}
	}
}

int main(){
	freopen("testIn_A1016.txt", "r", stdin);
	for(int i = 0; i < 24; i++)
		scanf("%d", &toll[i]);
	int n;
	scanf("%d", &n);
	for(int i= 0; i < n; i++){
		cin >> rec[i].name;
		scanf("%d:%d:%d:%d ", &rec[i].month, &rec[i].dd, &rec[i].hh, &rec[i].mm);
		string str;
		cin >> str;
		if(str == "on-line") rec[i].flag = true;
		else rec[i].flag = false;
	}
	sort(rec, rec + n, cmp);
	int on = 0, off, next;
	while(on < n){
		int needPrint = 0;
		next = on;
		while( next < n && (rec[next].name == rec[on].name)){
			if(needPrint == 0 && rec[next].flag == true)	needPrint = 1;
			else if(needPrint == 1 && rec[next].flag == false)	needPrint = 2;
			next++;
		}
		if(needPrint < 2){
		on = next;
		continue;
	}
	int AllMoney = 0;
	cout<<rec[on].name;
	printf(" %02d\n", rec[on].month);
	while(on < next){
		while(on < next -1 && !(rec[on].flag == true && rec[on+1].flag == false))
		on++;
	off = on + 1;
	if(off == next){
		on = next;
		break;
	}
	printf("%02d:%02d:%02d ", rec[on].dd, rec[on].hh, rec[on].mm);
	printf("%02d:%02d:%02d ", rec[off].dd, rec[off].hh, rec[off].mm);
	int time = 0, money = 0;
	getans(on, off, time, money);
	AllMoney += money;
	printf("%d $%.2f\n", time, money / 100.0);
	on = off + 1;
	}
	printf("Total amount: $%.2f\n", AllMoney / 100.0);
	}
	fclose(stdin);
	return 0;
}
