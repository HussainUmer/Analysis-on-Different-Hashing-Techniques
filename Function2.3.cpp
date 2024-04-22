#include <iostream>
#include <string>
#include <cmath> // for square function
using namespace std;

// Function 2 hash function
int hash_function_2(const string& str) {
    if (str.empty()) {
        return 0; // Return 0 for empty strings
    }
    return str.front() + str.back() + str.length();
}

// Secondary hash function for double hashing
int secondary_hash_function(const string& str) {
    // A simple secondary hash function, you may choose another function for your specific needs
    return str.length() % 7 + 1; // Modulo 7 plus 1 to avoid returning 0
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
            // Double hashing
            int offset = secondary_hash_function(key);
            int hashed_index = (index + offset) % size;
            int i = 1;
            while (!hash_table[hashed_index].empty()) {
                hashed_index = (index + i * offset) % size;
                i++;
            }
            hash_table[hashed_index] = key;
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

    // Insert words from the paragraph into the hash table
    int start = 0;
    while (start < paragraph.size()) {
        int end = paragraph.find(' ', start);
        if (end == string::npos) {
            end = paragraph.size();
        }
        string word = paragraph.substr(start, end - start);
        table.insert(word);
        start = end + 1;
    }

    // Print the populated hash table
    table.print();

    return 0;
}
