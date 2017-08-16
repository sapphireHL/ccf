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

const int N = 20010;

vector<int> g[N];
int res = 0;
bool visited[N];
int last = 0;//记录最远点

void bfs(int start){
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()){
		int layersize = q.size();
		while (layersize--){
			int cur = q.front();
			visited[cur] = true;
			last = cur;
			q.pop();
			int size = g[cur].size();
			for (int i = 0; i < size; i++){
				if (!visited[g[cur][i]])
					q.push(g[cur][i]);
			}
		}
		res++;
	}
}

int main(){
	int n, m, a;
	cin >> n >> m;
	for (int i = 2; i <= n; i++){
		cin >> a;
		g[a].push_back(i);
		g[i].push_back(a);
	}
	for (int i = n + 1; i <= n + m; i++){
		cin >> a;
		g[a].push_back(i);
		g[i].push_back(a);
	}
	//两遍bfs，第一遍找到一个最远点，第二遍找到另一个最远点
	bfs(1);
	res = 0;
	for (int i = 1; i <= n + m; i++)
		visited[i] = false;
	bfs(last);
	cout << res - 1 << endl;
	return 0;
}
