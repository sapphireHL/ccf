#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <stack>
#include <algorithm>

using namespace std;

const int N = 1000;
int dp[N][N]={0};
int sum[N] = {0};

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin>>a[i];
        sum[i] = i==0?a[i]:sum[i-1]+a[i];
    }

    for(int len = 2; len <= n; len++){
        for(int i=0; i<=n-len; i++){
            int j = i+len-1;
            dp[i][j] = INT_MAX;
            int sumij = sum[j]-sum[i]+a[i];
            for(int k=i; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+sumij);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}
