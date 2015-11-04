#include <iostream>
using namespace std;

int height(int n) {
	int ut_height = 1;
	if(n <= 0){
		return ut_height;
	}
	else{		
		for(int i = 1; i <= n; i++){
			if(i%2)//odd case
				ut_height *= 2;
			else
				ut_height++;
		}
	}	
    return ut_height;
}
int main() {
    int T;
    cin >> T;
    int arry[T];
    for(int i = 0; i < T; i++){
        int n;
        cin >> n;
        arry[i] = height(n);
    }
    for(int i = 0; i < T; i++)
		cout << arry[i] << endl;
    
}
