//PATA_1061 Dating
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define maxn 70
using namespace std;
struct dateStr{
	char str1[maxn];
	char str2[maxn];
	char srt1[maxn];
	char srt2[maxn];
	int d;
	int h;
	int m;
};
char* day[7]={"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
bool isLetter(char c){
	if(c >= 'a' && c <= 'z')
		return true;
	else if(c >= 'A' && c <= 'Z')
		return true;
	return false;
}
void setD(dateStr &r){
	int len1 = strlen(r.str1) <= strlen(r.str2) ? strlen(r.str1) : strlen(r.str2);
	int len2 = strlen(r.srt1) <= strlen(r.srt2) ? strlen(r.srt1) : strlen(r.srt2);
	int i;
	for(i = 0; i < len1; i++){
		if(r.str1[i] == r.str2[i] && r.str1[i] >= 'A' && r.str1[i] <= 'G')
			break;
	}
	r.d = i;
	for(i = r.d + 1; i < len1; i++){
		if(r.str1[i] == r.str2[i] && ((r.str1[i] >= 'A' && r.str1[i] <= 'N') || (r.str1[i] >= '0' && r.str1[i] <= '9'))){
			break;
	}
}
	r.h = i;
	for(i = 0; i < len2; i++){
		if(r.srt1[i] == r.srt2[i] && isLetter(r.srt1[i]))
			break;
	}
	r.m = i;
}
int hour(char c){
	if(c >='0' && c <='9')
	return c - '0';
	else 
	return (c - 'A' + 10);
}
void print(dateStr r){
	r.d = r.str1[r.d] - 'A';
	r.h = hour(r.str1[r.h]);
	//cout<<d<<" "<<h<<" "<<m;
	printf("%s %02d:%02d\n", day[r.d], r.h, r.m);
}

int main(){
	freopen("testIn_A1061.txt", "r", stdin);
	dateStr R;
	gets(R.str1);
	gets(R.str2);
	gets(R.srt1);
	gets(R.srt2);
	setD(R);
	print(R);
	fclose(stdin);
	return 0;
}
