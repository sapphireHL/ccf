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
int a[N];

int main(){
	int n, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	a[n] = 0;
	stack<int> s;

	for (int i = 0; i <= n; ){
		if (s.empty() || a[i] > a[s.top()]){
			s.push(i);
			i++;
		}
		else{
			int topindex = s.top();
			s.pop();
			if (s.empty())
				res = max(res, a[topindex] * i);
			else
				res = max(res, a[topindex] * (i - s.top() - 1));
		}
	}
	cout << res << endl;
	return 0;
}
