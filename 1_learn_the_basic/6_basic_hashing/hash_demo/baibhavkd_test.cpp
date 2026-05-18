#include <iostream>
#include <vector>
#include <unorderedmap>
#include <map>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    // if < n
    arr[3] = 9;
    // if > n
    arr.push_back(10); // arr[n] = 10;

    std::unorderedmap<int, int> ump;

    // key = array ka index | value = random values by user;
    for (int i = 0; i < q; i++)
    {
        int temp;
        cin >> temp;

        ump.insert({i, temp});
    }

    int idx;
    cin >> idx;

    int temp2;
    cin >> temp2;

    ump.insert({idx, temp2});
}
