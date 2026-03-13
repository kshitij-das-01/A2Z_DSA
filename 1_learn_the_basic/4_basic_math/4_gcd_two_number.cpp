#include <iostream>

using std::cin; using std::cout;

// iterating through each number from 1 to min(n1, n2) and updating the gcd through the loop
int gcd_calculate_1(int n1, int n2)
{
	int result = 1;

	if (n1 > n2) {
		n1 = n1 + n2;
		n2 = n1 - n2;
		n1 = n1 - n2;
	}

	// using swapping if the number is greater
	for (int i = 0; i < n1; i++)
	{
		if ((n1 % i == 0) && (n2 % i == 0)) {
			result = i;
		}
	}

	// using min function
	for (int i = 0; i < std::min(n1, n2); i++)
	{
		if ((n1 % i == 0) && (n2 % i == 0)) {
			result = i;
		}
	}

	return result;
}

// still iterating through a numbers but in reverse order as it will not take that many iterations to reach the gcd
// iterate through min(n1,n2) to 1
int gcd_calculate_2(int n1, int n2)
{
	int result = 1;

	// using swapping if the number is greater
	if (n1 > n2) {
		n1 = n1 + n2;
		n2 = n1 - n2;
		n1 = n1 - n2;
	}

	for (int i = n1; i > 0; i--)
	{
		if ((n1 % i == 0) && (n2 % i == 0)) {
			result = i;
			break;
		}
	}

	// using min function
	for (int i = std::min(n1, n2); i > 0; i--)
	{
		if ((n1 % i == 0) && (n2 % i == 0)) {
			result = i;
			break;
		}
	}

	return result;
}

// Euclidean Algorithm: using iteration
void gcd_calculate_3(int n1, int n2)
{
	while (n1 > 0 && n2 > 0) 
	{
		if (n1 > n2) {
			n1 = n1 % n2;
		}
		else {
			n2 = n2 % n1;
		}
	}

	if (n1 == 0) 
		cout << n2;
	else 
		cout << n1;
}

// Euclidean algorithm: using recursion
int gcd_calculate_4(int n1, int n2)
{
	if (n1 == 0)
		return n2;
	
	return gcd_4(n2 % n1, n1);
}

// using vector to store factor and checking the max common factor
int gcd_calculate_5(int n1, int n2)
{
	std::vector<int> f1, f2;

	for (int i = 1; i * i <= std::min(n1, n2); i++)
	{
		if (n1 % i == 0) {
			f1.push_back(i);

			if (n1 / i != i)
				f1.push_back(n1/i);
		}

		if (n2 % i == 0) {
			f2.push_back(i);

			if (n2 / i != i)
				f2.push_back(n2/i);
		}
	}

	std::sort(f1.begin(), f1.end());
	std::sort(f2.begin(), f2.end());

	// for (int ls : f1)
	// 	cout << ls << ' ';
	// cout << '\n';	

	// for (int ls : f2)
	// 	cout << ls << ' ';
	// cout << '\n';	
	
	int gcd;
	int i = f1.size() - 1, j = f2.size() - 1;

	while (i > 0 && j > 0)
	{
		if (f1[i] == f2[j])
			gcd = f1[i];

		if (f1[i] > f2[j])
			i--;
		else
			j--;
	}

	return gcd;
}


int main(void)
{
	int N1, N2;
	cout << "N1 = "; cin >> N1;
	cout << "N2 = "; cin >> N2;

	gcd_calculate_3(N1, N2);
	return 0;
}