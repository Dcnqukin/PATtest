//PATA_1042 Shuffling Machine
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>post;
struct Card{
	int v;
	int position;
}card[56];
bool cmp(Card a, Card b){
	return a.position < b.position;
}
void init(){
	for(int i = 0; i < 56; i++){
		card[i].v = i + 1;
		card[i].position = i + 1;
	}
}
void roll(){
	for(int i = 0; i < 54; i++){
		card[i].position = post[i];
	}
	sort(card, card + 55, cmp);
}
void print(Card a){
	int n;
	if(a.v % 13 != 0){
		n = a.v / 13;
		a.v = a.v % 13;
	}else{
		n = a.v / 13 - 1;
		a.v = 13;
	}
	switch(n){
		case 0:{
			printf("S%d", a.v);
			break;
		}
		case 1:{
			printf("H%d", a.v);
			break;
		}
		case 2:{
			printf("C%d", a.v);
			break;
		}
		case 3:{
			printf("D%d", a.v);
			break;
		}
		case 4:{
			printf("J%d", a.v);
			break;
		}
	}
}

int main(){
	freopen("testIn_A1042.txt", "r", stdin);
	init();
	int k, temp;
	scanf("%d", &k);
	for(int i = 0; i < 54; i++){
		scanf("%d", &temp);
		post.push_back(temp);
	}
	while(k--)
		roll();
	for(int i = 0; i < 54; i++){
		print(card[i]);
		if(i != 53) printf(" ");
	}
	printf("\n");
	fclose(stdin);
	return 0;
}
