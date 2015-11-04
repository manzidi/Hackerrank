#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long unsigned fibonnaci_modified(int a, int b, int n){
	long long unsigned results = b; 
	for(int i = 2; i < n; i++){
		results = a + b*b;
		a = b;
		b = results;
	}	
	return results;
}

int main() {
    int a, b , n;
    cin >> a >> b >> n;
    cout << fibonnaci_modified(a,b,n); 
    return 0;
}
