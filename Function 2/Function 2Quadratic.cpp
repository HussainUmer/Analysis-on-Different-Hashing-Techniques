#include <iostream>
#include <string>
#include <cmath> // for square function
#include <chrono> // for timing
using namespace std;
using namespace std::chrono;

// Function 2 hash function
int hash_function_2(const string& str) {
    if (str.empty()) {
        return 0; // Return 0 for empty strings
    }
    return str.front() + str.back() + str.length();
}

class HashTable {
private:
    int size;
    string *hash_table;

public:
    HashTable(int size) : size(size) {
        hash_table = new string[size];
    }

    ~HashTable() {
        delete[] hash_table;
    }

    int hash_function(const string& key) {
        return hash_function_2(key) % size;
    }

    void insert(const string& key) {
        int index = hash_function(key);
        if (hash_table[index].empty()) {
            hash_table[index] = key;
        } else {
            // Quadratic probing
            int i = 1;
            int offset = 1;
            int hashed_index;
            while (true) {
                hashed_index = (index + i * offset) % size;
                if (hash_table[hashed_index].empty()) {
                    hash_table[hashed_index] = key;
                    break;
                }
                i++;
                offset = pow(i, 2); // Using successive squares for quadratic probing
            }
        }
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            cout << "Index " << i << ": ";
            if (!hash_table[i].empty()) {
                cout << hash_table[i];
            } else {
                cout << "[Empty]";
            }
            cout << endl;
        }
    }
};

int main() {
    // Initialize hash table with size 10
    HashTable table(10);

    // Input paragraph
    string paragraph = "This is a sample paragraph for testing the hash function.";

    // Start timing
    auto start = high_resolution_clock::now();

    // Insert words from the paragraph into the hash table
    int start_index = 0;
    while (start_index < paragraph.size()) {
        int end_index = paragraph.find(' ', start_index);
        if (end_index == string::npos) {
            end_index = paragraph.size();
        }
        string word = paragraph.substr(start_index, end_index - start_index);
        table.insert(word);
        start_index = end_index + 1;
    }

    // Stop timing
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // Round the execution time to the nearest 10 microseconds
    int rounded_duration = round(duration.count() / 10.0) * 10;

    // Print the populated hash table
    table.print();

    // Print execution time
    cout << "Execution time: " << rounded_duration << " microseconds" << endl;

    return 0;
}
