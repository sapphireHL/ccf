#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
#include <queue>
#include <deque>

using namespace std;

const int N = 1005;

//6个状态
//0：前n位只用了2
//1：前n位只用了2，0
//2：前n位只用了2，3
//3：前n位只用了2，0，1
//4：前n位只用了2，0，3
//5：前n位只用了2，0，1，3
long long dp[N][6] = { 0 };//不用long long过不了所有样例
int mod = 1000000007;

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		dp[i][0] = 1;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 2) % mod;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
		dp[i][3] = (dp[i - 1][1] + dp[i - 1][3] * 2) % mod;
		dp[i][4] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4] * 2) % mod;
		dp[i][5] = (dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5] * 2) % mod;
	}
	cout << dp[n][5] << endl;
	return 0;
}
