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

const int N = 10010;

vector<int> g[N];
int DFN[N];
int LOW[N];
int res = 0;
int index = 0;
vector<int> stac;
bool instack[N];

//Tarjan算法  80%
void tarjan(int u){
	DFN[u] = LOW[u] = ++index; //初始化
	stac.push_back(u); //入栈
	instack[u] = true; //该点在栈中
	//搜寻相邻点
	for (int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if (!DFN[v]){ //如果没被访问
			tarjan(v);
			LOW[u] = min(LOW[u], LOW[v]);
		}
		else if (instack[v]){ //如果访问过，且在栈中
			LOW[u] = min(LOW[u], DFN[v]);
		}
	}
	//找到一个强连通图的根节点,将该节点之后的节点都出栈
	if (DFN[u] == LOW[u]){
		int tmp = stac.back();
		int count = 1;
		while (tmp != u){
			stac.pop_back();
			instack[tmp] = false;
			tmp = stac.back();
			count++;
		}
		stac.pop_back();
		res += count*(count - 1) / 2;
	}
}

int main(){
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> a >> b;
		g[a].push_back(b);
	}
	for (int i = 1; i <= n; i++){
		if (!DFN[i])
			tarjan(i);
	}
	cout << res << endl;
	return 0;
}
