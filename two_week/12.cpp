#include <iostream>
#include <set>
using namespace std;

int main() {
	int arr[10] = { 7, 1, 2, 3, 4, 4, 5, 5, 6, 7 };
	set<int> s;
	for (int i = 0; i < 10; i++) {
		s.insert(arr[i]);
	}
	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
	cout << *iter << " ";
}
	return 0;
}