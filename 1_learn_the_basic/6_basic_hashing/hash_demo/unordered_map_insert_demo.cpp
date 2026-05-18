#include <iostream>
#include <unordered_map>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

/*
 * This program demonstrates how to use the insert method in unordered_map
 * to count the frequency of elements in an array.
 *
 * Two methods are shown:
 * 1. Using the insert method (which returns a pair<iterator, bool>)
 * 2. Using the [] operator (simpler and more common for frequency counting)
 *
 * We then compare the results to ensure they are the same.
 */

// Function to count frequency using insert method
unordered_map<int, int> freqUsingInsert(const vector<int>& arr) {
    unordered_map<int, int> freqMap;
    for (int num : arr) {
        // Try to insert the element with count 1
        auto ret = freqMap.insert({num, 1});
        // If insertion failed (because the key already exists), increment the count
        if (!ret.second) {
            (ret.first->second)++;
        }
    }
    return freqMap;
}

// Function to count frequency using [] operator (for comparison)
unordered_map<int, int> freqUsingBracket(const vector<int>& arr) {
    unordered_map<int, int> freqMap;
    for (int num : arr) {
        freqMap[num]++; // This automatically initializes to 0 if not present, then increments
    }
    return freqMap;
}

// Function to print the frequency map
void printFreqMap(const unordered_map<int, int>& freqMap) {
    cout << "Element -> Frequency\n";
    for (const auto& pair : freqMap) {
        cout << pair.first << " -> " << pair.second << '\n';
    }
}

int main() {
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Compute frequency using insert method
    unordered_map<int, int> freqInsert = freqUsingInsert(arr);
    // Compute frequency using bracket operator
    unordered_map<int, int> freqBracket = freqUsingBracket(arr);

    cout << "\nFrequency using insert method:\n";
    printFreqMap(freqInsert);

    cout << "\nFrequency using [] operator:\n";
    printFreqMap(freqBracket);

    // Check if both methods yield the same result
    if (freqInsert == freqBracket) {
        cout << "\nBoth methods produce the same frequency map.\n";
    } else {
        cout << "\nWarning: The two methods produce different results!\n";
    }

    // Optional: Allow querying frequencies
    cout << "\nEnter number of queries: ";
    int q;
    cin >> q;
    cout << "Enter the numbers to query:\n";
    for (int i = 0; i < q; i++) {
        int queryNum;
        cin >> queryNum;
        // Using the insert method result (or bracket, they are the same)
        cout << "Frequency of " << queryNum << ": " << freqInsert[queryNum] << '\n';
    }

    return 0;
}