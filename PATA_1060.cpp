//PATA_1060 Are They Equal
#include <iostream>
#include <string>
using namespace std;
int n;
string deal(string s, int&e){
	int k = 0;
	while(s.length() > 0 && s[0] == '0')
		s.erase(s.begin());
	if(s[0] == '.'){
		s.erase(s.begin());
		while(s.length() > 0 && s[0] == '0'){
			s.erase(s.begin());
			e--;
		}
	}else{
		while(k < s.length() && s[k] != '.'){
			k++;
			e++;
		}
		if(k < s.length()){
			s.erase(s.begin() + k);
		}
	}
	if(s.length() == 0)
		e = 0;
	int num = 0;
	k = 0;
	string res;
	while(num < n){
		if(k < s.length()) res += s[k++];
		else res += '0';
		num++;
	}
	return res;
}
int main(){
	string stra, strb, strc, strd;
	cin >> n;
	cin >> stra >> strb;
	int e1 = 0, e2 = 0;
	strc = deal(stra, e1);
	strd = deal(strb, e2);
	if(strc == strd && e1 == e2){
		cout<<"YES 0."<<strc<<"*10^"<<e1<<endl;
	}else{
		cout<<"NO 0."<<strc<<"*10^"<<e1<<" 0."<<strd<<"*10^"<<e2<<endl;
	}
	return 0;
}
