#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

vector<string> split(string s,char c){
	vector<string> ret;
	stringstream ss(s);
	string token;
	//be careful of this write,split by c
	while(getline(ss,token,c)){
		ret.push_back(token);
	}
	return ret;
}
int main(){
	string s ="9,7,6,3,23,45";
	vector<string> ret = split(s,',');
	for(auto c:ret)
		cout<<c<<endl;;
}
