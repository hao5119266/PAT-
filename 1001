#include <iostream>
using namespace std;

int Callatz(int a);
int main() {
	int a, n;
	cin >> a;
	n = Callatz(a);
	cout << n<<endl;
}
int Callatz(int a) {
	static int n = 0;
	if (a == 1) { return n; }
	if (a % 2 == 0) {
		a = a / 2;
		n++;
		Callatz(a);
	}
	else {
		a = (3*a + 1) / 2;
		n++;
		Callatz(a);
	}
}
