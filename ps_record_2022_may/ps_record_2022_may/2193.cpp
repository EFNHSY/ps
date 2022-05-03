#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
int n;
ll dp[91][2];
ll search(int idx, int c)
{
	ll& ret = dp[idx][c];
	if (ret != -1) return ret;
	if (idx == n) return 1;
	if (c == 0)
	{
		ret = max(search(idx + 1, 0) + search(idx + 1, 1),ret);
	}
	else
	{
		ret = max(search(idx + 1, 0),ret);
	}
	return ret;
} 
void solve()
{
	memset(dp, -1, sizeof dp);
	 cin >> n;
	 cout << search(1, 1) << "\n";
}*/

ll dp[91][2];
void solve()
{
	int n; cin >> n;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = max(dp[i][0], dp[i - 1][0]+dp[i-1][1]);
		dp[i][1] = max(dp[i][1], dp[i - 1][0]);
	}
	cout << dp[n][0]+dp[n][1] << "\n";
}
int main()
{
	solve();
	return 0; 
}