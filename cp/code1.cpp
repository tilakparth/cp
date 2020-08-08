
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
	w(t) {
		//Enter your code here
		string s; cin >> s;
		int l = s.length();
		stack<char> brac;
		int possible = 1;
		from(i, l) {
			if (s[i] == ']') {
				if (brac.empty())possible = 0;
				else {
					if (brac.top() == '[')brac.pop();
					else possible = 0;
				}
			}
			else if (s[i] == ')') {
				if (brac.empty())possible = 0;
				else {
					if (brac.top() == '(')brac.pop();
					else possible = 0;
				}
			}
			else if (s[i] == '}') {
				if (brac.empty())possible = 0;
				else {
					if (brac.top() == '{')brac.pop();
					else possible = 0;
				}
			}
			else {
				brac.push(s[i]);
			}
		}
		if (!brac.empty())possible = 0;
		if (possible)cout << "YES\n";
		else cout << "NO\n";
	}



	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	return 0;
}
