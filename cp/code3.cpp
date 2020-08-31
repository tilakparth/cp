
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


int solve(int c1, int c2, int swords, int axes, int s, int w) {
	int ans = 0;
	if (s > w) {
		swap(s, w);
		swap(swords, axes);
	}
	int temp1 = min(c1 / s, swords);
	c1 -= s * temp1;
	ans += temp1;

	int temp2 = min(c1 / w, axes);
	ans += temp2;
	c1 -= w * temp2;
	if (temp1 + temp2 == swords + axes) {
		return temp1 + temp2;
	}
	// cout << temp1 << " " << temp2 << "\n";
	axes -= temp2;

	int diff = w - s;
	if (diff) {
		int count = c1 / diff;
		count = min(count, temp1);
		count = min(count, axes);
		temp1 -= count;
		axes -= count;
	}
	swords -= temp1;

	ans += min((c2 / s), swords);
	c2 -= s * min((c2 / s), swords);
	ans += min(c2 / w, axes);
	return ans;
}


int32_t main()
{
	c_p_c();
	w(t) {
		//Enter your code here
		int c1, c2; cin >> c1 >> c2;
		// if (c2 < c1)swap(c1, c2);
		int swords, axes; cin >> swords >> axes;
		int s, w; cin >> s >> w;
		int ans = solve(c1, c2, swords, axes, s, w);
		ans = max(ans, solve(c2, c1, swords, axes, s, w));
		cout << ans << "\n";
	}



	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	return 0;
}
