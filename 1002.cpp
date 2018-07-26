#include <iostream>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int sum = 0;
	string str[10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
	for (int i = 0; i<s.length(); i++)
		sum += s[i] -'0';
	string sum_string = to_string(sum);
	for (int i = 0; i<sum_string.length(); i++)
	{
		int n = sum_string[i] - '0';
		if (i != 0)cout << " ";
		cout << str[n];
	}
	return 0;
}
