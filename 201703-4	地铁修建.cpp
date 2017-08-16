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

const int N = 100010;

struct edge
{
	int front, to, weight;
	edge(int f, int t, int w) :front(f), to(t), weight(w){}
};

bool cmp(const edge& a, const edge& b){
	return a.weight < b.weight;
}

int n, m, k, r, a, b, c;
int parent[N];
int height[N];
vector<edge> g;

//并查集
void init(){
	for (int i = 0; i < N; i++){
		parent[i] = i;
		height[i] = 0;
	}
}

int find(int x){
	int root = parent[x];
	while (parent[root] != root){
		root = parent[root];
	}
	while (x != root){
		int t = parent[x];
		parent[x] = root;
		x = t;
	}
	return root;
}

void unite(int x, int y){
	int rx = find(x), ry = find(y);
	if (rx != ry){
		if (height[rx] < height[ry])
			parent[rx] = ry;
		else
			parent[ry] = rx;
		if (height[rx] == height[ry])
			height[rx]++;
	}
}

int main(){

	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> a >> b >> c;
		g.push_back(edge(a, b, c));
	}
	sort(g.begin(), g.end(), cmp);

	init();
	int cnt = 0;
	edge cur(0, 0, 0);
  //每次取最短的边，直到1和n联通
	while (find(1) != find(n)){
		cur = g[cnt++];
		unite(cur.front, cur.to);
	}
	cout << cur.weight << endl;
	return 0;
}
