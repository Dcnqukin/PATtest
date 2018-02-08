#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;



int main()
{
	int n1,n2;
	long temp;
	vector<long>s1;
	vector<long>s2;
	scanf("%d",&n1);
	for(int i=0 ; i < n1 ; i++)
	{
		scanf("%d",&temp);
		s1.push_back(temp);
	}
	scanf("%d",&n2);
	for(int i=0; i < n2 ; i++)
	{
		scanf("%d",&temp);
		s2.push_back(temp);
	}
	vector<long>mid;
	int i,j;
	long s;
	for(i=0 , j=0; i < s1.size() && j < s2.size();)
	{
		if( s1[i] <= s2[j]){
			s = s1[i];
			i++;
		}
		else
		{
			s = s2[j];
			j++;
		}
		mid.push_back(s);
		if(mid.size() == (s1.size() + s2.size() + 1)/2){
			cout<<mid[mid.size() - 1] <<endl;
			break;
		}
		
	}
	
	if(mid.size() != (s1.size() + s2.size() + 1)/2){
		while(i < s1.size())
		{
			mid.push_back(s1[i]);
			if(mid.size() != (s1.size() + s2.size() + 1)/2){
				cout<<mid[mid.size() - 1] <<endl;
				break;
			}
			i++;
		}
		while(j < s2.size())
		{
			mid.push_back(s2[j]);
			if(mid.size() != (s1.size() + s2.size() + 1)/2){
				cout<<mid[mid.size() - 1] <<endl;
				break;
			}
			j++;
		}
	}
	return 0;
}
