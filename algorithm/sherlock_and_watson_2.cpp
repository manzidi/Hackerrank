#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
	int n, k, q;
	cin >> n >> k >> q;	//stdin size, operation num, and query num
	vector<int> vec;
	int queries[q];
	
	int tmp;
	for(int i = 0; i < n; i++){	//stdin array elements
		cin >> tmp;
		vec.push_back(tmp);
	}
	
	
	for(int i = 0; i < q; i++){	//stdin indexes to print
		cin >> queries[i];
	}
	for(int i = 0; i < k; i++)
		rotate(vec.begin(), vec.begin()+1, vec.end());
	
	for(int i = 0; i < q; i++){	//print preferred indexes
		cout << vec[queries[i]] << endl;
	}
	
	
    return 0;
}

