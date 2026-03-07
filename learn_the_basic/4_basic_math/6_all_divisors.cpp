#include <iostream>
#include <vector>
#include <set>

using std::cin; using std::cout; using std::vector; using std::set;

// we are running the loop till sqrt of n and add them to the vector if it is a divisor also to not add if it is a perfect square
// vector approach which would need sorting after loop
void divisors_1(int n)
{
	vector<int> div_list;

	for (int i = 1; i * i <= n; i++)
	{
		if (n % i == 0){
			div_list.push_back(i);

			if (i * i != n) {
				div_list.push_back((int)(n/i));
			}
		}
	}

	std::sort(div_list.begin(), div_list.end());

	for (auto ls : div_list) {
		cout << ls << " ";
	}
}

// set approach to avoid sorting after the loop ends
void divisors_2(int n)
{
	set<int> div_list;

	for (int i = 1; i * i <= n; i++)
	{
		if (n % i == 0) {
			div_list.insert(i);

			if (i * i != n) {
				div_list.insert((int)(n/i));
			}
		}
	}

	// not required for set STL
	// std::sort(div_list.begin(), div_list.end());

	for (auto ls : div_list) {
		cout << ls << " ";
	}
}

// running till the n number and checking if it is a divisor
void divisors_3(int n)
{
	vector<int> res;

	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0) {
			res.push_back(i);
		}
	}
	
	std::sort(res.begin(), res.end());

	for (auto ls : res) {
		cout << ls << " ";
	}
}

int main(void)
{
	int N;
	cin >> N;

	divisors_1(N);
	return 0;
}