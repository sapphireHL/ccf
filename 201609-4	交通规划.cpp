#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 10005;

struct node{
    int v;//节点
    int dis;//节点到起点的距离
    node(int vv=0, int dd=0):v(vv), dis(dd){}
    friend bool operator <( node n1,  node n2){
        return n1.dis>n2.dis;
    }
};

struct edge{
    int v;//边的另一个点
    int cost;//边权重
    edge(int vv=0, int cc=0):v(vv), cost(cc){}
};

vector<edge> nodes[N];//无向图
int visited[N]={0};//节点是否访问
int dist[N];//每个节点到起点的最短距离
int cost[N];//每个节点连通的最小代价

void dijkstra(int start){
    for(int i=0; i<N; i++){
        dist[i] = INT_MAX;
        cost[i] = INT_MAX;
    }
    dist[start]=0;
    cost[start]=0;
    priority_queue<node> q;//优先队列
    q.push(node(start, 0));

    node tmp;
    while(!q.empty()){
        tmp = q.top();
        q.pop();
        int v = tmp.v;
        if(!visited[v]){
            visited[v]=1;
            int neighbors = nodes[v].size();
            for(int i=0; i<neighbors; i++){
                int nextv = nodes[v][i].v;
                if(visited[nextv]) continue;
                int ccost = nodes[v][i].cost;
                int newdis = ccost+dist[v];
                if(dist[nextv] > newdis){
                    dist[nextv] = newdis;
                    cost[nextv] = ccost;
                    q.push(node(nextv, newdis));
                }
                //距离相同代价为较短边
                if(dist[nextv] == newdis)
                    cost[nextv] = min(cost[nextv], ccost);
            }
        }
    }
}

int main(){
    int n, m, res=0;
    cin>>n>>m;
    int a, b, c;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        nodes[a].push_back(edge(b, c));
        nodes[b].push_back(edge(a, c));
    }
    dijkstra(1);
    for(int i=2; i<=n; i++) res += cost[i];
    cout<<res<<endl;
    return 0;
}
