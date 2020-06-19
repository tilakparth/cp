#include <bits/stdc++.h>
using namespace std;

bool f(int x, int y) {
	return x > y;
}

int main() {
	// your code goes here 
	vector <int> A = { 11,2,3,4 };

	// 	for(int i=0;i<A.size();i++){
	// 	    cout<<A[i]<<" ";
	// 	}
	// 	cout<<endl; //to print all elements of a

	// 	sort(A.begin(),A.end());

	// 	for(int i=0;i<A.size();i++){
	// 	    cout<<A[i]<<" ";
	// 	}
	// 	cout<<endl; //to print all elements of a	

	bool present = binary_search(A.begin(), A.end(), 3);
	bool present2 = binary_search(A.begin(), A.end(), 100);
	// 	cout<<present<<endl<<present2<<endl;

	A.push_back(100);
	present2 = binary_search(A.begin(), A.end(), 100);
	// 	cout<<present2<<endl;
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(123);

	// 	2,3,4,11,100,100,100,100,100,123

	vector<int> ::iterator it = lower_bound(A.begin(), A.end(), 100);
	vector<int> ::iterator it2 = upper_bound(A.begin(), A.end(), 100);

	// 	cout<<*it<<endl<<*it2<<endl<<it2-it<<endl;

	sort(A.begin(), A.end(), f);

	vector<int> ::iterator it3;
	for (int x : A) {
		cout << x << " ";
	}
	cout << endl; //to print all elements of a	

	sort(A.begin(), A.end());
	for (it3 = A.begin(); it3 < A.end(); it3++) {
		cout << *it3 << " ";
	}
	cout << endl; //to print all elements of a

	return 0;
}
