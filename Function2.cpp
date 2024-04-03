#include <iostream>
#include <string>
using namespace std;

// Function 2 hash function
int hash_function_1(const string& str) {
    int hash_value = 0;
    for (char ch : str) {
        hash_value += ch; // Sum the ASCII values of characters
    }
    return hash_value;
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
        return hash_function_1(key) % size;
    }

    void insert(const string& key) {
        int index = hash_function(key);
        if (hash_table[index].empty()) {
            hash_table[index] = key;
        } else {
            // Quadratic probing
            int i = 1;
            while (!hash_table[(index + i*i) % size].empty()) {
                i++;
            }
            hash_table[(index + i*i) % size] = key;
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
    // Initialize hash table with size 12
    HashTable table(12);

    // Input paragraph
    string paragraph = "The quick brown fox jumps over the lazy dog.";

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
