#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

// Function 3: Compute hash value for a string using the given formula
int hashFunction(const string& s) {
    int index = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        index = (26 * index + s[i] - ' ');
    }
    return index;
}

// Hash Table with Linear Probing
class HashTable {
private:
    int size;
    string *table;

public:
    HashTable(int tableSize) : size(tableSize) {
        table = new string[tableSize];
    }

    ~HashTable() {
        delete[] table;
    }

    // Insert a string into the hash table using linear probing for collisions
    void insert(const string& s) {
        int index = hashFunction(s) % size;
        while (!table[index].empty()) {
            index = (index + 1) % size;
        }
        table[index] = s;
    }

    // Function to print the hash table
    void printTable() {
        for (int i = 0; i < size; ++i) {
            cout << "Index " << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    // Input paragraph
    string paragraph = "This is a sample paragraph for testing the hash function.";

    // Set hash table size
    int tableSize = 10;

    // Create hash table
    HashTable hashTable(tableSize);

    // Insert words from the paragraph into the hash table
    size_t start = 0, end;
    while ((end = paragraph.find(' ', start)) != string::npos) {
        string word = paragraph.substr(start, end - start);
        hashTable.insert(word);
        start = end + 1;
    }
    string last_word = paragraph.substr(start);
    hashTable.insert(last_word);

    // Output hash table
    cout << "Hash Table:" << endl;
    hashTable.printTable();

    return 0;
}
