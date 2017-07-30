
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>?
using namespace std;
vector<string> split(string str, char sep) {
	stringstream ss(str);
	vector<string> res;
	string temp;
	while (getline(ss, temp, sep)) {
		res.push_back(temp);
	}
	return res;
}
int main() {
	string line;
	while (getline(cin, line)) {
		vector<string> res = split(line, ' ');
		vector<string> parameters;
		for (int i = 0; i<res.size(); i++) {
			if (res[i].find('"') != string::npos) {
				string temp = res[i];
				int j = i + 1;
				for (; j<res.size(); j++) {
					temp += string(" ") + res[j];
					if (res[j].find('"') != string::npos)
						break;
				}
				//auto it = remove(temp.begin(), temp.end(), '"');
				//temp.erase(it, temp.end());
				//parameters.push_back(temp);
            
                string a = temp.substr(1,temp.size()-2);
                parameters.push_back(a);
				i = j;
			}
			else {
				parameters.push_back(res[i]);
			}
		}
		cout << parameters.size() << endl;
		for (auto e : parameters) {
			cout << e << endl;
		}
	}
	return 0;
}