
#include <iostream>
using namespace std;

void rotate(int arry[], int n, int k){
	// n is array size, k is number of operations	
	for(int h = 0; h < k; h++){
		int last = arry[n-1];
		for(int i = n-1; i > 0; i--){
			arry[i] = arry[i-1];
		}
		arry[0] = last;
	}	
}

int main() {
	int n, k, q;
	cin >> n >> k >> q;	//stdin size, operation num, and query num
	int arry[n];
	int queries[q];
	
	for(int i = 0; i < n; i++){	//stdin array elements
		cin >> arry[i];
	}
	
	for(int i = 0; i < q; i++){	//stdin indexes to print
		cin >> queries[i];
	}
	
	rotate(arry, n, k);	//rotate array k times
	
	for(int i = 0; i < q; i++){	//print preferred indexes
		cout << arry[queries[i]] << endl;
	}
	
	
    return 0;
}

