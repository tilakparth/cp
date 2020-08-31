
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
	int t; cin >> t;
	from(j, t) {
		cout << "Case #" << j + 1 << ": ";
		int n, m, k, s; cin >> n >> m >> k >> s;
		vi p(n); from(i, k)cin >> p[i];
		int a, b, c, d; cin >> a >> b >> c >> d;
		from_j(i, k, n)p[i] = (a * p[i - 2] + b * p[i - 1] + c) % d + 1;
		vi q(m); from(i, k)cin >> q[i];
		cin >> a >> b >> c >> d;
		from_j(i, k, m)q[i] = (a * q[i - 2] + b * q[i - 1] + c) % d + 1;
		cout << "\n";
		for (auto it : p)cout << it << " ";
		cout << "\n";
		for (auto it : q)cout << it << " ";
		// unordered_map<int, int> m ;
		int endi = 0;

	}



	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	return 0;
}
