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

struct priviledge
{
	string name;
	int level;
	priviledge(string pp, int l) :name(pp), level(l){}
};

struct role
{
	string name;
	vector<priviledge> p;
};

struct user
{
	string name;
	vector<role> r;
};
int p, r, u, q;

string line, tmp;
vector<priviledge> pr;
vector<role> ro;
vector<user> us;

priviledge getPriviledge(string s){
	string name;
	int level = -1;
	if (count(s.begin(), s.end(), ':') == 0){
		name = s;
	}
	else{
		int pos = s.find(':');
		name = s.substr(0, pos);
		level = s[pos + 1] - '0';
	}
	priviledge p(name, level);
	return p;
}
int findRole(string s){
	for (int i = 0; i < ro.size(); i++){
		if (ro[i].name == s){
			return i;
		}
	}
	return -1;
}
int findUser(string s){
	for (int i = 0; i < us.size(); i++){
		if (us[i].name == s){
			return i;
		}
	}
	return -1;
}

int main(){
	cin >> p;
	for (int i = 0; i < p; i++){
		cin >> line;
		pr.push_back(getPriviledge(line));
	}

	cin >> r;
	for (int i = 0; i < r; i++){
		string name;
		int num;
		cin >> name >> num;	
		role rr;
		rr.name = name;
		for (int j = 0; j < num; j++){
			cin >> line;
			rr.p.push_back(getPriviledge(line));
		}
		ro.push_back(rr);
	}

	cin >> u;
	for (int i = 0; i < u; i++){
		string name;
		int num;
		cin >> name >> num;
		user uu;
		uu.name = name;
		for (int j = 0; j < num; j++){
			cin >> line;
			uu.r.push_back(ro[findRole(line)]);
		}
		us.push_back(uu);
	}

	cin >> q;
	for (int i = 0; i < q; i++){
		string name, pri;
		cin >> name >> pri;
		priviledge qpri = getPriviledge(pri);
		//用户不存在
		if (findUser(name) == -1){
			cout << "false" << endl;
			continue;
		}
		bool flag = false;
		int maxl = -1;
		user curu = us[findUser(name)];
		for (int j = 0; j < curu.r.size(); j++){
			for (int k = 0; k < curu.r[j].p.size(); k++){
				//找到该权限
				if (qpri.name == curu.r[j].p[k].name){
					//查询有等级权限
					if (curu.r[j].p[k].level != -1){
						if (qpri.level == -1){
							flag = true;
							//找到最高权限
							maxl = max(maxl, curu.r[j].p[k].level);
						}
						else{
							if (curu.r[j].p[k].level >= qpri.level)
								flag = true;
						}
					}
					//查询无等级权限
					else{
						if (qpri.level == -1)
							flag = true;
					}
				}
			}
		}
		if (flag && maxl != -1)
			cout << maxl << endl;
		else if (flag && maxl == -1)
			cout << "true" << endl;
		else if (!flag)
			cout << "false" << endl;
	}

	
	return 0;
}
