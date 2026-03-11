#include <iostream>
#include <map>

using std::cin; using std::cout;

// brute force
int hash_brute(int num, int *arr, int size)
{
	int cnt = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == num)
			cnt++;
	}
	return cnt;
}

// optimized
void hash_opt(int q, int *arr, int size)
{
	// pre compute
	int *hash = new int[size+1];
	for (int i = 0; i < size; i++)
		hash[arr[i]]++;

	// query
	for (int i = 0; i < q; i++)
	{
		int num;
		cin >> num;
		cout << "Freq: " << hash[num] << '\n';
	}
}

// using map
void hash_map(int *arr, int size)
{
	std::map<int, int> mp;
	// unordered map can be used as well, it does not store the data in sorted order
	// std::unordered_map<int, int> ump;

	// pre compute
	for (int i = 0; i < size; i++)
		mp[arr[i]]++;

	// print
	for (auto ls : mp){
		cout << ls.first << " -> " << ls.second << '\n';
	}
}

// using map while passing query for the frequency
void hash_map_query(int q, int *arr, int size)
{
	std::map<int, int> mp;
	// unordered map can be used as well, it does not store the data in sorted order
	// std::unordered_map<int, int> ump;
	
	// pre compute
	for (int i = 0; i < size; i++)
		mp[arr[i]]++;
	
	// fetch
	for (int i = 0; i < q; i++)
	{
		int num;
		cin >> num;
		cout << "Freq: " << mp[num] << '\n';
	}
}

int main(void)
{
	cout << "Size: ";
	int n;
	cin >> n;

	int *arr = new int[n];
	for (int i = 0; i < n; i++) 
		cin >> arr[i];	
		
	cout << "Queries: ";
	int q;
	cin >> q;
		
	// optimized solution using hashing
	// hash_opt(q, arr, n);

	// using map and printing all freq
	// hash_map(arr, n);

	// using map and passing query
	hash_map_query(q, arr, n);


	// brute force iterating through the whole array to find the number of times it occurs
	// for (int i = 0; i < q; i++)
	// {
	// 	int num;
	// 	cin >> num;		
		// cout << hash_brute(num, arr, n) << '\n';
	// }

	return 0;
}