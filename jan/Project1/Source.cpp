#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	scanf_s("%d", &t);
	for (int i = 0; i < t; i++) {
		int n;
		scanf_s("%d", &n);
		long long int no = pow(10, n);
		long long int a, s, b, c, d, e;
		scanf_s("%lld", &a);
		s = 2 * no + a;
		printf("%lld\n", s);
		fflush(stdout);
		scanf_s("%lld", &b);
		c = no - b;
		printf("%lld\n", c);
		fflush(stdout);
		scanf_s("%lld", &d);
		e = no - d;
		printf("%lld\n", e);
		fflush(stdout);
		int ans;
		scanf_s("%d", &ans);
		if (ans == -1)break;
	}

	return 0;
}
