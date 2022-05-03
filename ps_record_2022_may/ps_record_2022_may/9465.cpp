#include <bits/stdc++.h>
using namespace std;
/*
* top down 
* int n;
int v[100001][2];
int dp[100001][3];
int search(int idx, int c)
{
	int& ret = dp[idx][c];
	if (ret != -1) return ret;
	if (idx == n + 1) return 0;
	
	if (c == 0)
	{
		int temp_max = max(search(idx + 1, 0), search(idx + 1, 1));
		temp_max = max(search(idx + 1, 2), temp_max);
		ret = max(temp_max, ret);
	}
	else if (c == 1)
	{
		int temp_max = max(search(idx + 1, 0), search(idx + 1, 2)) + v[idx][0];
		ret = max(temp_max, ret);
	}
	else
	{
		int temp_max = max(search(idx + 1, 0), search(idx + 1, 1)) + v[idx][1];
		ret = max(temp_max, ret);
	}

	return ret;
}
void solve()
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> v[i][0];
	for (int i = 1; i <= n; i++) cin >> v[i][1];
	cout << search(0, 0) <<"\n";
	
} 
* 
* 
*/
int v[100001][3];
int dp[100001][3];
void solve()
{
	memset(dp, 0, sizeof dp);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin>>  v[i][1];
	for (int i = 1; i <= n; i++) cin >> v[i][2];

	for (int i = 1; i <= n; i++)
	{
		/*		// j = 0
		dp[i][0] = max(dp[i - 1][0], dp[i][0]);
		dp[i][0] = max(dp[i - 1][1], dp[i][0]);
		dp[i][0] = max(dp[i - 1][2], dp[i][0]);
		// j = 1
		dp[i][1] = max(dp[i - 1][0] + v[i][1], dp[i][1]);
		dp[i][1] = max(dp[i - 1][2] + v[i][1], dp[i][1]);

		// j = 2
		dp[i][2] = max(dp[i - 1][0] + v[i][2], dp[i][2]);
		dp[i][2] = max(dp[i - 1][1] + v[i][2], dp[i][2]);
		*/

		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (j!=0&&j == k) continue;
				dp[i][j] = max(dp[i][j], dp[i - 1][k] + v[i][j]);
			}
			
		}
	}
	int ans = 0;
	ans = max(ans, dp[n][0]);
	ans = max(ans, dp[n][1]);
	ans = max(ans, dp[n][2]);
	cout << ans << "\n";
}
int main()
{
	int t; cin >> t;
	//while (t--) solve(); top-down
	while (t--) solve(); //bottomup
	return 0;
}