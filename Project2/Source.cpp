#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	scanf_s("%d", &t);
	for (int j = 0; j < t; j++) {
		int n, m;
		scanf_s("%d %d", &n, &m);
		int len = min(n, m);
		int arr[20][20], pal[20][20] = { 1 };
		int sum = n * m;
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < m; k++)
			{
				scanf_s("%d", &arr[i][j]);
			}
		}  //scan
		for (int var = 3; var <= len; var = var + 2) {
			int f = var / 2;
			for (int i = f; i < (n - f); i++) {
				for (int k = f; k < (m - f); k++) {
					if (pal[i][j]) {
						if ((arr[i - f][j] == arr[i + f][j]) && (arr[i][j + f] == arr[i][j - f])) {
							sum++;
						}
						else pal[i][j] = 0;
					}
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
