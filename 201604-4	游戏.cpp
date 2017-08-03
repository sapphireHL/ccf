#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

struct pos{
    int x, y, time;
    pos(int xx=0, int yy=0, int tt=0) :x(xx), y(yy), time(tt){}
};

int dange[105][105][2]={0};//记录危险格子
int state[105][105][305]={0};//记录每个格子到达的最短时间
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};//四个方向

bool isdanger(int x, int y, int time){
    if(time >= dange[x][y][0] && time <= dange[x][y][1]) return true;
    return false;
}

int main(){
    int n, m, t, r, c, a, b;
    cin>>n>>m>>t;
    for(int i=0; i<t; i++){
        cin>>r>>c>>a>>b;
        dange[r][c][0] = a;
        dange[r][c][1] = b;
    }
    queue<pos> q;
    q.push(pos(1,1,0));
    state[1][1][0]=1;
    pos tmp;
    while(!q.empty()){
        tmp = q.front();
        int curx = tmp.x;
        int cury = tmp.y;
        int curtime = tmp.time;
        if(curx == n && cury == m) break;
        q.pop();
        for(int i=0; i<4; i++){
            int nextx = curx+dir[i][0];
            int nexty = cury+dir[i][1];
            int newtime = curtime+1;
            if(nextx >= 1 && nextx <=n && nexty >= 1 && nexty <= m && !isdanger(nextx, nexty, newtime) && !state[nextx][nexty][newtime]){
                q.push(pos(nextx, nexty, newtime));
                state[nextx][nexty][newtime]=1;
            }
        }
    }
    cout<<tmp.time<<endl;
    return 0;
}
