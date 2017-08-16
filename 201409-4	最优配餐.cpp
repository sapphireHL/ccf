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

const int N = 1010;

int g[N][N] = { 0 };
vector<pair<int, int> > shop;
map<pair<int, int>, int> order;
long long res = 0;
int n, m, k, d, a, b, c;
int mintime[N][N];//到达各个点的最短时间
int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
queue<pair<int, int> > q;
bool visited[N][N];

void bfs(){
	int time = 1;
	while (!q.empty()){
		int layersize = q.size();
		while (layersize--){
			pair<int, int> cur = q.front();
			q.pop();
			visited[cur.first][cur.second] = 1;
			for (int i = 0; i < 4; i++){
				int nextx = cur.first + dir[i][0];
				int nexty = cur.second + dir[i][1];
				if (nextx < 1 || nextx > n || nexty < 1 || nexty > n) continue;
				if (visited[nextx][nexty]) continue;
				if (g[nextx][nexty] == 1) continue;
				q.push(pair<int, int>(nextx, nexty));
				visited[nextx][nexty] = 1;
				mintime[nextx][nexty] = min(time, mintime[nextx][nexty]);
			}
		}
		time++;
	}
}

int main(){
	
	cin >> n >> m >> k >> d;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			mintime[i][j] = INT_MAX;
	}
	for (int i = 0; i < m; i++){
		cin >> a >> b;
		shop.push_back(pair<int, int>(a, b));
		q.push(pair<int, int>(a, b));//多个起点入队列
		mintime[a][b] = 0;
		visited[a][b] = true;
	}
	for (int i = 0; i < k; i++){
		cin >> a >> b >> c;
		pair<int, int> tmp = pair<int, int>(a, b);
		order[tmp] += c;
	}
	for (int i = 0; i < d; i++){
		cin >> a >> b;
		g[a][b] = 1;
	}

	bfs();

	for (map<pair<int, int>, int>::iterator i = order.begin(); i != order.end(); i++){
		pair<int, int> dst = i->first;
		int num = i->second;
		int low = mintime[dst.first][dst.second];
		res += low*num;
	}
	cout << res << endl;
	return 0;
}
