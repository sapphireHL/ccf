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
bool visited[N];
bool visitededge[N][N];
int deg[N];//各个顶点度数
stack<int> res;

//只过了50%
void dfs(int u){
	visited[u] = true;
	for (int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if (!visitededge[u][v] && !visitededge[v][u]){
			visitededge[u][v] = visitededge[v][u] = true;
			dfs(v);
			res.push(v);
		}
	}
}

int main(){
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> a >> b;
		deg[a]++;
		deg[b]++;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	//保证字典序最小
	for (int i = 1; i <= n; i++)
		sort(g[i].begin(), g[i].end());

	//无向图中如果存在欧拉通路，条件是：
	//	1. 图连通；
	//	2. 所有顶点的度数为偶数，或者，只有两个顶点的度数为奇数, 出发点必为奇度数。
	/*int count = 0;
	for (int i = 1; i <= n; i++){
		if (deg[i] % 2 == 1)
			count++;
	}
	if (count == 0){
		dfs(1);
	}
	else if (count == 2){
		if (deg[1] % 2 == 1)
			dfs(1);
		else{
			cout << -1 << endl;
			return 0;
		}
	}
	else{
		cout << -1 << endl;
		return 0;
	}*/
	dfs(1);
	if (res.size() != m){
		cout << -1 << endl;
		return 0;
	}
	cout << 1;
	while (!res.empty()){
		cout << ' ' << res.top();
		res.pop();
	}
	cout << endl;
	return 0;
}
