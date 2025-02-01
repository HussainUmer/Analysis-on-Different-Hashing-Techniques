# Hashing Techniques Evaluation

## **Objective**
This project evaluates the performance of different string hash functions when utilized with three hashing techniques: linear probing, quadratic probing, and double hashing. The goal is to identify the most efficient approach for handling string-based data storage and retrieval tasks.

## **Key Features**
- **Implemented Hash Functions**:
  1. **Function 1**: Sum of ASCII values of each character.
  2. **Function 2**: First and last letter plus the string length (Cichelli method).
  3. **Function 3**: String-based index calculation using ASCII values (Ramakrishna method).

- **Hashing Techniques**:
  - **Linear Probing**
  - **Quadratic Probing**
  - **Double Hashing**

## **Results**
- **Double hashing** proved to have the lowest execution time, showing superior performance.
- **Linear probing** demonstrated the highest execution time, making it the least efficient of the techniques tested.
- Among the hash functions, **Function 3** (Ramakrishna) showed the best performance.

## **Time Complexity**
The time complexity of all hash functions is **O(n)**, as each function iterates over every character in the string.

## **Searching in Hash Table**
- **Hashing the Search Key**: The key is hashed using the same function used for insertion.
- **Potential Challenges**: Collisions and false positives/negatives can affect retrieval efficiency.
- **Mitigation**: Using prime numbers and efficient collision resolution techniques like double hashing can minimize these issues.
