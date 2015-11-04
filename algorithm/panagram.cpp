#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	string str;
	getline(cin,str);
	vector<char> alphabet;
	for(size_t j = 0; j < str.length(); j++){
		char ch = toupper(str[j]);
		if(isalpha(ch)){		
			if(find(alphabet.begin(), alphabet.end(), ch) == alphabet.end()){
				alphabet.push_back(ch);
			}	
		}
	}
	if(alphabet.size() == 26)
		cout << "pangram" << endl;
	else
		cout << "not pangram" << endl;
    return 0;
}

