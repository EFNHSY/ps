#include <bits/stdc++.h>
using namespace std;
#define MOD 10007
int n;
int dp[1001];
int search(int idx)
{
	int& ret = dp[idx];
	if (ret != 0) return ret%MOD;
	if (idx == n) return 1;

	if (idx + 1 <= n)
	{
		ret = (ret+search(idx+1)) % MOD;
	}
	if (idx + 2 <= n)
	{
		ret = (ret + 2*search(idx + 2)) % MOD;
	}
	return ret;
}
void solve2()
{
	memset(dp, 0, sizeof(dp));
	cin >> n;
	cout << search(0) << "\n";

}
void solve()
{
	int n; cin >> n;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= 1000; i++)
	{
		dp[i] = (dp[i - 1] + 2 * dp[i - 2])%MOD;
	}
	cout << dp[n] << "\n";
}
int main()
{
	solve2();
	return 0;
}