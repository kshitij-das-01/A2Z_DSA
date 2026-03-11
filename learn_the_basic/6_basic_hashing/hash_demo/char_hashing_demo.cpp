#include <iostream>
#include <map>

using std::cin; using std::cout;

// brute force
int hash_brute(char ch, std::string str)
{
	int cnt = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ch)
			cnt++;
	}
	return cnt;
}

// optimized
void hash_opt(int q, std::string str)
{
	// pre compute
	// for a-z
	int *hash = new int[26];
	for (int i = 0; i < str.length(); i++)
		hash[str[i] - 'a']++;
	
	// ASCII from 0-255 [A-Z, a-z]
	// int *hash2 = new int[256];
	// for (int i = 0; i < str.length(); i++)
	// 	hash2[str[i]]++;

	// fetch
	for (int i = 0; i < q; i++)
	{
		char ch;
		cin >> ch;
		cout << "Freq: " << hash[ch - 'a'] << '\n';
	}
}

// using map
void hash_map(std::string str)
{
	std::map<int, int> mp;
	// unordered map can be used as well, it does not store the data in sorted order
	// std::unordered_map<int, int> ump;

	// pre compute
	for (int i = 0; i < str.length(); i++)
		mp[str[i]]++;

	// print
	for (auto ls : mp) {
		char ch = ls.first;
		cout << ch << " -> " << ls.second << '\n';
	}
}

// using map with query
void hash_map_query(int q, std::string str)
{
	std::map<int, int> mp;
	// unordered map can be used as well, it does not store the data in sorted order
	// std::unordered_map<int, int> ump;

	// pre compute
	for (int i = 0; i < str.length(); i++)
		mp[str[i]]++;
	
	// fetch
	for (int i = 0; i < q; i++)
	{
		char ch;
		cin >> ch;
		cout << "Freq: " << mp[ch] << '\n';
	}
}

int main(void)
{
	std::string str;
	cin >> str;

	cout << "Queries: ";
	int q;
	cin >> q;

	// optimized
	hash_map_query(q, str);

	// for (int i = 0; i < q; i++)
	// {
	// 	char ch;
	// 	cin >> ch;
		// brute force
	// 	cout << "Freq: " << hash_brute(ch, str) << '\n';
	// }
	return 0;
}