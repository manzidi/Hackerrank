#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    long long int arry[t];
    long long int sum = 0;
    for(int i = 0; i < t; i++){
		cin >> arry[i];
		sum += arry[i];
	}  
	cout << sum;  
    return 0;
}
