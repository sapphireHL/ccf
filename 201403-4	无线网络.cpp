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
typedef long long ll;

const int N = 210;

struct node
{
	ll x, y;
	node(ll  xx, ll yy) :x(xx), y(yy){}
};


int n, m, k, a, b;
ll r;

int g[N][N];
int mink[N];//经历的最少的k
bool visited[N];
vector<node> nodes;
queue<int> q;
int res = 0;

void bfs(){
	q.push(0);
	while (!q.empty()){
		int layersize = q.size();
		while (layersize--){
			int cur = q.front();
			q.pop();
			visited[cur] = true;
      //搜索范围，若当前已经添加k个，只在前n个路由器中搜索
			int searchrange = mink[cur] == k ? n : n + m;
			for (int i = 0; i < searchrange; i++){
				if (!visited[i] && g[cur][i]){
					if (i == 1){
						return;
					}
					q.push(i);
					visited[i] = true;
					mink[i] = i >= n ? mink[cur] + 1 : mink[cur];
				}
			}
		}
		res++;
	}
}

int main(){
	
	cin >> n >> m >> k >> r;
	for (int i = 0; i < n; i++){
		cin >> a >> b;
		nodes.push_back(node(a, b));
	}
	for (int i = 0; i < m; i++){
		cin >> a >> b;
		nodes.push_back(node(a, b));
	}
	for (int i = 0; i < nodes.size(); i++){
		for (int j = i + 1; j < nodes.size(); j++){
			if ((nodes[i].x - nodes[j].x)*(nodes[i].x - nodes[j].x) + (nodes[i].y - nodes[j].y)*(nodes[i].y - nodes[j].y) <= r*r){
					g[i][j] = g[j][i] = 1;
			}
		}
	}

	bfs();
	cout << res << endl;

	return 0;
}
