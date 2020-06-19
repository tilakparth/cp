
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


vi bellam_ford(int n, int src, vector<vi> &edges) {
	vi dis(n + 1, INT_MAX);
	dis[src] = 0;

	from(i, n - 1) {
		for (auto x : edges) {
			dis[x[1]] = min(dis[x[1]], dis[x[0]] + x[2]);
		}
	}

	for (auto x : edges) {
		if (dis[x[1]] > dis[x[0]] + x[2]) {
			cout << "Negative cycle\n";
			vi v;
			return v;
		}
	}

	from(i, n + 1)cout << i << " " << dis[i] << "\n";

	return dis;


}


int32_t main()
{
	c_p_c();
	int n, m;
	cin >> n >> m;

	vector<vi> edges;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edges.pb({a, b, w});
	}
	bellam_ford(n, 1, edges);



	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	return 0;
}
