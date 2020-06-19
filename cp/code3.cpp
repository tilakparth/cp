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
#endif
}

int merge(vector<int> &arr, int starti, int endi) {
	int temp[endi - starti + 1];
	int ans = 0;                        // 0
	int index = 0;                      //0
	int mid = (starti + endi) / 2;  // mid =2
	int i = starti ; int j = mid + 1;     // i=2 , j=3
	while ((i <= mid) || (j <= endi)) {
		if (i > mid) temp[index++] = arr[j++];
		else if (j > endi) {
			temp[index++] = arr[i++];
			ans += j - mid - 1;
		}
		else {
			if (arr[i] == arr[j]) {
				int tem = arr[i];             //tem =3
				int pos = j;                     // pos=3
				while ((i <= mid) && (arr[i] == tem)) {
					temp[index++] = arr[i++];   // index=1 , i=3
					// cout<<"pos= "<<pos<<" mid= "<<mid<<endl;
					ans += pos - mid - 1;      //ans=0
				}
				while ((j <= endi) && (arr[j] == tem))temp[index++] = arr[j++];
			}
			else if (arr[i] < arr[j]) {
				//  cout<<"PARTH \n";
				temp[index++] = arr[i++];
				ans += j - mid - 1;
			}
			else temp[index++] = arr[j++];
		}
	}
	for (int in = starti; in <= endi; in++)arr[in] = temp[in - starti];
	return ans;
}

int  merge_sort(vector<int> &arr, int starti, int endi) {

	if (starti >= endi)return 0;
	int mid = (starti + endi) / 2;
	int ans = 0;
	ans += merge_sort(arr, starti, mid);
	ans += merge_sort(arr, mid + 1, endi);
	// cout<<"starti="<<starti<<" endi= "<<endi<<endl;
	// cout<<ans<<endl;
	int temp = merge(arr, starti, endi);
	ans += temp;
	// cout<<temp<<" "<<ans<<endl;
	return ans;
}


int32_t main()
{
	c_p_c();

	int n; cin >> n; vector<int> arr;
	from(i, n) {
		int a;
		cin >> a;
		arr.pb(a);
	}
	cout << merge_sort(arr, 0, n - 1) << endl;

	return 0;
}