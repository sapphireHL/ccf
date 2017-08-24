#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
#include <queue>
#include <deque>
#include <limits>
#include <stack>

using namespace std;

string curdir, line, tmp;


int main(){
	int n;
	cin >> n;
	getline(cin, line);
	getline(cin, curdir);
	for (int i = 0; i < n; i++){
		string res;
		vector<string> path;
    //注意不能用cin>>line， cin不能处理输入为空的情况
		getline(cin, line);
		if (line == ""){
			cout << curdir << endl;
			continue;
		}
		if (line[0] != '/'){
			stringstream ss(curdir);
			while (getline(ss, tmp, '/')){
				if (tmp != "")
					path.push_back(tmp);
			}
		}
		stringstream ss(line);
		while (getline(ss, tmp, '/')){
			if (tmp != ""){
				if (tmp == ".."){
					if (path.size() > 0)
						path.pop_back();
				}
				else if (tmp != ".")
					path.push_back(tmp);
			}
		}
		if (path.size() == 0)
			res += '/';
		for (int i = 0; i < path.size(); i++){
			res += "/" + path[i];
		}
		cout << res << endl;
	}
	
	return 0;
}
