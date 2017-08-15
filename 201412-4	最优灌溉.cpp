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

using namespace std;

const int N = 1010;

//Prim算法 100%
int g[N][N];
int visited[N];
int lowcost[N];
set<int> mst;

void prim(int start, int& res, int n){
	//初始化
	for (int i = 1; i <= n; i++)
		lowcost[i] = INT_MAX;
	lowcost[start] = 0;
	while (mst.size() != n){
		int v = 0;//要选择的节点
		int lowest = INT_MAX;//最小代价
		//找出最小代价的节点
		for (int i = 1; i <= n; i++){
			if (!visited[i] && lowcost[i] < lowest){
				lowest = lowcost[i];
				v = i;
			}
		}
		//该节点加入最小生成树
		visited[v] = true;
		mst.insert(v);
		res += lowest;
		//更新各个点代价
		for (int i = 1; i <= n; i++){
			if (!visited[i] && g[v][i] < lowcost[i]){
				lowcost[i] = g[v][i];
			}
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			g[i][j] = INT_MAX;
	}
	int a, b, c;
	for (int i = 0; i < m; i++){
		cin >> a >> b >> c;
		g[a][b] = c;
		g[b][a] = c;
	}
	int res = 0;
	prim(1, res, n);
	cout << res << endl;
	return 0;
}





//Kruskal算法 90%
//struct edge
//{
//	int front;
//	int to;
//	int weight;
//	edge(int f = 0, int t = 0, int w = 0) :front(f), to(t), weight(w){}
//};
//
//bool cmp(const edge& a, const edge& b){
//	return a.weight < b.weight;
//}
//
//vector<edge> g;
//set<int> mst;
//int parent[N];
//int height[N];
//
////并查集
//void init(){
//	for (int i = 0; i < N; i++){
//		parent[i] = i;
//		height[i] = 0;
//	}
//}
//
//int find(int x){
//	int root = x;
//	while (root != parent[root])
//		root = parent[root];
//	while (x != root){
//		int t = parent[x];
//		parent[x] = root;
//		x = t;
//	}
//	return root;
//}
//
//void unite(int x, int y){
//	int	rx = find(x);
//	int ry = find(y);
//	if (rx != ry){
//		if (height[rx] < height[ry])
//			parent[rx] = ry;
//		else
//			parent[ry] = rx;
//		if (height[rx] == height[ry])
//			height[rx]++;
//	}
//}
//
//void kruskal(int &res, int n){
//	init();
//	for (int i = 0; i < g.size(); i++){
//		int v = g[i].front, vv = g[i].to;
//		int x = find(v), y = find(vv);
//		if (x != y){
//			unite(x, y);
//			res += g[i].weight;
//			mst.insert(v);
//			mst.insert(vv);
//		}
//		if (mst.size() == n) break;
//	}
//}
//
//
//int main(){
//	int n, m;
//	cin >> n >> m;
//	int a, b, c;
//	for (int i = 0; i < m; i++){
//		cin >> a >> b >> c;
//		g.push_back(edge(a, b, c));
//
//	}
//	sort(g.begin(), g.end(), cmp);
//	int res = 0;
//	kruskal(res, n);
//	cout << res << endl;
//
//	return 0;
//}
//
