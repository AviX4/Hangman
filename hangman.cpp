#include <bits/stdc++.h>
#include <iostream>
#include "ch.h"
using namespace std;

string create(string s,map<char,int>& m,string& s1){
	for(int i=0;i<2;i++){
		int j=rand()%9;
		m[s[j]]++;
	}
	s1=s;
	for(int i=0;i<s.length();i++){
		if(m.find(s1[i])!=m.end()){
			s1[i]='_';
		}
	}
	return s1;

}

void search(char a,map<char,int>& m,string& s,string& s1,int& res){
	if(m.find(a)==m.end()){
		res++;
		hangman(res);
		if(res==7){
			cout<<"You lost";
		}
		return;
	}else{
		for (int i = 0; i < s.length(); ++i)
		{
			if(s[i]==a){
				s1[i]=a;
			}
		}
		if(s1==s){
			cout<<"YOU WON";
			return;
		}
		return;
	}
}


int main(){
	string s="ADBCQAABCBA";
	string s1;
	map<char,int> m;
	create(s,m,s1);
	int res=0;
	while(res!=7){
		cout<<s1;
		char k;
		cin>>k;
		search(k,m,s,s1,res);
	}
	cout<<s;

}