
#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long int
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define from(i,n)       for(int i=0;i<(int)n;i++)
#define from_j(i,j,n)   for(int i=j;i<(int)n;i++)


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
}

int32_t main()
{
	c_p_c();
	int n, m; cin >> n >> m;
	vector<string> v(n);
	from(i, n)cin >> v[i];

	int ans = n * m;
	vector<vector<int>>dp(n, vi(m));
	int start_n = 1; int start_m = 1;
	// cout << start_n << " " << start_m << "\n";
	while (1) {
		if (2 * start_n > n)break;
		if (2 * start_m > m)break;
		from_j(i, start_n, n - start_n) {
			int flag = 1;
			char ch = v[i][start_m];
			int temp = INT_MAX;
			int y = start_m;
			if (ch != v[i - 1][y])flag = 0;
			if (ch != v[i + 1][y])flag = 0;
			if (ch != v[i][y + 1])flag = 0;
			if (ch != v[i][y - 1])flag = 0;
			temp = min(temp, dp[i - 1][y]);
			temp = min(temp, dp[i + 1][y]);
			temp = min(temp, dp[i][y - 1]);
			temp = min(temp, dp[i][y + 1]);
			if (start_m == 2) {
				cout << dp[i][y - 1] << dp[i][y + 1];
				cout << "temp = " << temp << "\n";

			}
			if (flag) {
				dp[i][y] = temp + 1;
				ans += temp + 1;
			}
		}
		cout << ans << "\n";
		from_j(i, start_m + 1, m - start_m) {
			int flag = 1;
			int temp = INT_MAX;
			int x = start_n;
			char ch = v[x][i];

			if (ch != v[x + 1][i])flag = 0;
			if (ch != v[x - 1][i])flag = 0;
			if (ch != v[x][i + 1])flag = 0;
			if (ch != v[x][i - 1])flag = 0;
			temp = min(temp, dp[x][i]);
			temp = min(temp, dp[x][i]);
			temp = min(temp, dp[x][i - 1]);
			temp = min(temp, dp[x][i + 1]);
			if (flag) {
				dp[x][i] = temp + 1;
				ans += temp + 1;
			}
		}
		cout << ans << "\n";
		if (start_m * 2 == m - 1)break;
		if (start_n * 2 == n - 1)break;
		from_j(i, start_n + 1, n - start_n) {
			int flag = 1;
			int temp = INT_MAX;
			int y = m - 1 - start_m;
			char ch = v[i][y];
			if (ch != v[i - 1][y])flag = 0;
			if (ch != v[i + 1][y])flag = 0;
			if (ch != v[i][y + 1])flag = 0;
			if (ch != v[i][y - 1])flag = 0;
			temp = min(temp, dp[i - 1][y]);
			temp = min(temp, dp[i + 1][y]);
			temp = min(temp, dp[i][y - 1]);
			temp = min(temp, dp[i][y + 1]);
			if (flag) {
				dp[i][y] = temp + 1;
				ans += temp + 1;
			}
		}
		cout << ans << "\n";
		from_j(i, start_m + 1, m - start_m - 1) {
			int flag = 1;
			int temp = INT_MAX;
			int x = n - 1 - start_n;
			char ch = v[x][i];

			if (ch != v[x + 1][i])flag = 0;
			if (ch != v[x - 1][i])flag = 0;
			if (ch != v[x][i + 1])flag = 0;
			if (ch != v[x][i - 1])flag = 0;
			temp = min(temp, dp[x][i]);
			temp = min(temp, dp[x][i]);
			temp = min(temp, dp[x][i - 1]);
			temp = min(temp, dp[x][i + 1]);
			if (flag) {
				dp[x][i] = temp + 1;
				ans += temp + 1;
			}
		}
		cout << ans << "\n";
		cout << start_n << " " << start_m << endl;
		cout << ans << "\n";
		start_m++; start_n++;
	}
	cout << ans;


	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	return 0;
}
