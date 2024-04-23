#include <iostream>
#include <string>
#include <chrono>
using namespace std;

// Function 3: Compute hash value for a string using the given formula
int hashFunction(const string& s, int tableSize) {
    int index = 0;
    for (int i = 0; i < s.length(); ++i) {
        index = (26 * index + s[i] - ' ');
    }
    return index % tableSize; // Ensure index is within table size
}

// Secondary hash function for double hashing
int secondaryHashFunction(const string& s, int tableSize) {
    int index = 0;
    for (char c : s) {
        index += c;
    }
    return index % tableSize; // Ensure index is within table size
}

// Hash Table with Double Hashing
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

    // Insert a string into the hash table using double hashing for collisions
    void insertDoubleHashing(const string& s) {
        int index = hashFunction(s, size);
        int step = secondaryHashFunction(s, size);
        int originalIndex = index;

        while (!table[index].empty()) {
            index = (index + step) % size;
            // If we've traversed the whole table without finding an empty slot, break to prevent infinite loop
            if (index == originalIndex) {
                cout << "Table is full, cannot insert: " << s << endl;
                return;
            }
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
    auto old = chrono::steady_clock::now();
    // Input paragraph
    string paragraph = "artificial intelligence ai has been one of the most fascinating and rapidly advancing fields of technology in recent years it encompasses a variety of approaches that aim to imitate the human mind and perform tasks that would normally require human intelligence in this essay we will delve into the world of ai examining its definition history current applications and future potential the concept of artificial intelligence can be traced back to the times of ancient greece and ancient china however it was not until the mid 20th century that scientists began experimenting with machines that could exhibit intelligence on their own in 1956 the term artificial intelligence was coined at an academic conference at dartmouth college by john mccarthy after that ai research progressed rapidly with major advancements in systems able to learn from data and adapt to changing circumstances in recent years the rapid growth of computing power and the availability of vast amounts of data have led to an explosion in the applications of ai in our daily lives ai is now used in a variety of applications ranging from virtual assistants like siri or alexa autonomous vehicles to medical diagnosis to automated trading algorithms the potential of ai is simply limitless with the continuing advances in its hardware and software capabilities we can expect to see more complex and intelligent ai systems being deployed in the years ahead however there are also significant ethical and philosophical questions that come along with the advancement of ai what will happen when ai capabilities exceed that of humans will ai systems ever have consciousness and emotions how do we strike a balance between the benefits of ai and its humanity we are only beginning to explore these profound questions and solutions to these problems are not straightforward despite the challenges artificial intelligence presents it also provides countless opportunities for growth and advancement in various fields there is no denying that ai has already revolutionized many aspects of our lives from how we work to how we communicate and entertain ourselves the future of ai is bright and full of promise as there is still much to be explored and discovered in this rapidly evolving field overall artificial intelligence is a field that continues to amaze provoke and push the boundaries of what we think is possible and its impact will only continue to grow in the years ahead artificial intelligence ai is often defined as the ability of machines to perform tasks that typically require human intelligence these tasks include but are not limited to visual perception speech recognition decision making and language translation ai systems can be classified into several categories based on their capabilities and functions one common classification is based on the type of intelligence exhibited by the system narrow ai also known as weak ai refers to systems that are designed and trained for a specific task such as playing chess or recognizing faces narrow ai systems excel in their specific domain but lack the ability to generalize their knowledge or skills to other domains general ai also known as strong ai refers to systems that possess the ability to understand learn and apply knowledge across different domains these systems can perform any intellectual task that a human can do they have the ability to reason solve problems and adapt to new situations while general ai remains a long term goal of ai research most of the ai systems that exist today fall under the category of narrow ai another classification of ai systems is based on their level of autonomy autonomous ai systems are capable of performing tasks without human intervention they can make decisions and take actions based on their understanding of the environment and their goals examples of autonomous ai systems include self driving cars and autonomous drones semi autonomous ai systems on the other hand require human supervision and intervention for certain tasks these systems can perform some tasks independently but may require human input for more complex or ambiguous situations an example of a semi autonomous ai system is a virtual assistant like siri or alexa which can perform tasks like setting reminders or answering questions but may require human intervention for tasks that require deeper understanding or context ai systems can also be classified based on their learning capabilities machine learning is a subfield of ai that focuses on developing algorithms that enable computers to learn from data and improve their performance over time there are several approaches to machine learning including supervised learning unsupervised learning and reinforcement learning supervised learning involves training a model on labeled data where each input is associated with the correct output the model learns to make predictions by generalizing from the labeled examples supervised learning is commonly used in tasks such as image classification and speech recognition unsupervised learning involves training a model on unlabeled data where the goal is to discover hidden patterns or structures in the data clustering and dimensionality reduction are common unsupervised learning techniques reinforcement learning involves training an agent to interact with an environment and learn the optimal actions to take in order to maximize a reward reinforcement learning has been successfully applied to a wide range of tasks including game playing robotics and autonomous navigation deep learning is a subfield of machine learning that focuses on developing artificial neural networks with multiple layers of interconnected nodes these networks are inspired by the structure and function of the human brain deep learning has achieved remarkable success in recent years particularly in tasks such as image and speech recognition natural language processing and autonomous driving the success of deep learning can be attributed to several factors including the availability of large labeled datasets advances in computing power and the development of efficient training algorithms ai has a wide range of applications across various industries and domains one of the most prominent applications of ai is in healthcare ai systems are being used to assist clinicians in diagnosing diseases predicting patient outcomes and personalizing treatment plans for individual patients ai has the potential to revolutionize healthcare by improving the accuracy and efficiency of medical diagnosis reducing medical errors and optimizing healthcare delivery another important application of ai is in autonomous vehicles ai technologies such as computer vision and machine learning are being used to develop self driving cars that can navigate complex environments and interact safely with other vehicles and pedestrians autonomous vehicles have the potential to reduce accidents improve traffic flow and provide greater mobility for people with disabilities ai is also being used in finance and economics to automate trading strategies detect fraudulent activities and optimize investment portfolios ai powered chatbots are being used by businesses to provide customer support and assistance ai is also being used in education to personalize learning experiences and provide individualized instruction to students ai tutors can adapt to each student's learning style pace and preferences helping them to master concepts more effectively and efficiently ai is also being used in entertainment and creative industries to generate music art and literature ai generated content can be used to create new forms of entertainment and inspire human creativity however ai also raises ethical and social issues that need to be addressed as ai becomes more advanced and pervasive there are concerns about job displacement economic inequality privacy and security biases and discrimination and the misuse of ai for malicious purposes it is important for policymakers researchers and industry leaders to work together to develop regulations and guidelines that ensure ai is used ethically responsibly and for the benefit of society overall artificial intelligence has the potential to transform the way we live work and interact with the world it offers countless opportunities for innovation and advancement but also poses challenges and risks as we continue to explore and develop ai technologies it is important to consider the ethical social and economic implications and to ensure that ai is developed and deployed in a way that promotes human well being and protects our values and rights.";

    // Set hash table size
    int tableSize = 1350; // Increase table size

    // Create hash table
    HashTable hashTable(tableSize);

    // Insert words from the paragraph into the hash table using double hashing
    int start = 0;
    while (start < paragraph.size()) {
        int end = paragraph.find(' ', start);
        if (end == string::npos) {
            end = paragraph.size();
        }
        string word = paragraph.substr(start, end - start);
        
        hashTable.insertDoubleHashing(word); // Use double hashing
        start = end + 1;
    }

    // Output hash table
    cout << "Hash Table:" << endl;
    hashTable.printTable();

    auto duration = chrono::steady_clock::now() - old;
    std::cout << "Execution time: " << chrono::duration_cast<chrono::microseconds>(duration).count() << " microseconds" << endl;

    return 0;
}
