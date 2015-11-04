#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void printall(vector<int> ar){
	for(vector<int>::iterator i = ar.begin(); i != ar.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void insertionSort(vector <int>  ar) {
	int size = (int)ar.size();
	int last = ar[size-1];
	for(int i = size -2; i >= 0; i--){
		if(ar[i] > last){
			ar[i+1] = ar[i];
			if(i == 0)
				ar[i] = last;
			printall(ar);
		}
		else{
			ar[i+1] = last;
			printall(ar);
			break;
		}
	}

}

int main(void) {
    vector <int>  ar;
    int size;
    cin >> size;
    for(int i=0; i<size; i++) {
        int tmp;
        cin >> tmp;
        ar.push_back(tmp); 
    }

    insertionSort(ar);

    return 0;
}
