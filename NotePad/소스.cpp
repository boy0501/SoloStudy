#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string str; string tmp; int result = 0;
	bool check = false;
	cin >> str;
	for (int i = 0; i <= str.length(); i++) {
		if (str[i] != '-' && str[i] != '+' && i != str.length()) {
			tmp += str[i];
		}
		else {
			if (!check) {
				result += stoi(tmp, nullptr, 10);
				tmp.clear();
			}
			else {
				result -= stoi(tmp, nullptr, 10);
				tmp.clear();
			}
		}

		if (str[i] == '-')
			check = true;
	}
	cout << result;
}