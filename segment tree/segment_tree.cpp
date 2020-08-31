// Segement Tree for min element in a range based queries

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

void buildTree(vi &a, int starti, int endi, int index, vi & tree) { // function to build a segment tree
	if (starti == endi) {
		tree[index] = a[starti];
		return;
	}
	int mid = (starti + endi) / 2;
	buildTree(a, starti, mid, 2 * index, tree);
	buildTree(a, mid + 1, endi, 2 * index + 1, tree);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	// cout << starti << " " << endi << " " << tree[index] << "\n";
	return;
}
int query(vi &tree, int s_start, int s_end, int q_start, int q_end, int index) {
	if (s_start > q_end || q_start > s_end) return inf; // case of no overlap;
	if (s_start >= q_start && s_end <= q_end) return tree[index] ; // case of complete overlap;
	int mid = (s_start + s_end) / 2;
	int left = query(tree, s_start, mid, q_start, q_end, 2 * index);
	int right = query(tree, mid + 1, s_end, q_start, q_end, 2 * index + 1);
	return min(left, right);      // case of partial overlap  // function to find min element in given query
}
void update(vi &tree, int s_start, int s_end, int pos, int value, int index) { // Updates the tree for updates in array
	if (s_start > pos || s_end < pos)return; // out of bound case or no overlapping case
	if (s_start == s_end) {           // start == end => we are at pos => complete overlap
		tree[index] = value;
		return;
	}
	int mid = (s_start + s_end) / 2;
	update(tree, s_start, mid, pos, value, 2 * index);
	update(tree, mid + 1, s_end, pos, value, 2 * index + 1);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;
}
void range_updates(vi &tree, int s_start, int s_end, int u_start, int u_end, int increment, int index) {
	if (s_start > u_end || s_end < u_start)return; // No overlapping
	if (s_start == s_end) {    // leaf node,one point in the update range
		tree[index] += increment;
		return;
	}
	// recursive case
	int mid = (s_start + s_end) / 2;
	range_updates(tree, s_start, mid, u_start, u_end, increment, 2 * index);
	range_updates(tree, mid + 1, s_end, u_start, u_end, increment, 2 * index + 1);
	tree[index] = min(tree[index * 2], tree[2 * index + 1]);
	return ;
}

int32_t main()
{
	c_p_c();
	vector<int> a = {1, 3, 2, -5, 6, 4};
	int n = a.size();
	vector<int> tree(4 * n + 1, INT_MAX);
	// for (auto it : a)cout << it << " ";
	// cout << "\n";
	buildTree(a, 0, n - 1, 1, tree);
	// for (int i = 1; i <= 13; i++)cout << tree[i] << " ";
	update(tree, 0, n - 1, 3, 5, 1);  // new array = {1,3,2,5,6,4}
	range_updates(tree, 0, n - 1, 3, 5, 10, 1); // new array ={1,3,2,15,16,14}
	w(t) {
		int l, r; cin >> l >> r;
		cout << query(tree, 0, n - 1, l, r, 1) << "\n";
	}
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	return 0;
}
