#include <iostream>

using std::cin; using std::cout;

// solution by using another variable
void name_print_1(int i, int n)
{
	if (i > n) {
		return;
	}
	cout << "Kshitij ";
	name_print_1(i+1, n);
}

// solution by using the original variable copy.
void name_print_2(int n) 
{
	if (n < 1) {
		return;
	}
	cout << "Kshitij ";
	name_print_2(n-1);
}

int main(void)
{
	int n;
	cin >> n;

	name_print_1(1, n);
	cout << '\n';
	name_print_2(n);
	return 0;
}