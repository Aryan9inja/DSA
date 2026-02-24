### Hashmaps 
Hashmaps are a data structure that allows you to store key-value pairs. They are also known as dictionaries, maps, or associative arrays in other programming languages.

#### Basic Operations
- **Insertion**: You can insert a key-value pair into a hashmap. If the key already exists, the value will be updated.
- **Retrieval**: You can retrieve the value associated with a specific key. If the key does not exist, it typically returns null or a default value.
- **Deletion**: You can remove a key-value pair from the hashmap using the key.
- **Existence Check**: You can check if a key exists in the hashmap.

#### Types of Hashmaps in C++
- **std::unordered_map**: This is a hash table-based implementation of a hashmap. It provides average O(1) time complexity for insertion, deletion, and retrieval operations.
- **std::map**: This is a tree-based implementation of a hashmap. It provides O(log n) time complexity for insertion, deletion, and retrieval operations. It maintains the keys in sorted order.

#### Hash Function
A hash function is used to compute the index for a given key in the hashmap. A good hash function should distribute keys uniformly across the hashmap to minimize collisions (when two different keys hash to the same index).

#### Collision Resolution
When two keys hash to the same index, a collision occurs. There are several strategies to resolve collisions:
- **Chaining**: This method uses a linked list or another data structure to store multiple key-value pairs at the same index.
- **Open Addressing**: This method finds another open index in the hashmap to store the key-value pair. Common techniques include linear probing, quadratic probing, and double hashing.

#### Performance
The performance of a hashmap depends on the quality of the hash function and the load factor (the number of entries divided by the size of the hashmap). A high load factor can lead to more collisions, which can degrade performance. Therefore, it's important to choose an appropriate size for the hashmap and a good hash function to ensure efficient operations.

#### Complexity
- **Average Case**: O(1) for insertion, deletion, and retrieval.
- **Worst Case**: O(n) for insertion, deletion, and retrieval (when all keys hash to the same index).
- **Space Complexity**: O(n) for storing n key-value pairs.
```cpp
#include <iostream>
#include <unordered_map>
int main() {
    std::unordered_map<std::string, int> hashmap;

    // Insertion
    hashmap["apple"] = 1;
    hashmap["banana"] = 2;
    hashmap["orange"] = 3;

    // Retrieval
    std::cout << "Value for 'apple': " << hashmap["apple"] << std::endl;

    // Deletion
    hashmap.erase("banana");

    // Existence Check
    if (hashmap.find("banana") != hashmap.end()) {
        std::cout << "'banana' exists in the hashmap." << std::endl;
    } else {
        std::cout << "'banana' does not exist in the hashmap." << std::endl;
    }

    return 0;
}
```
This code demonstrates basic operations on an unordered_map in C++. It shows how to insert key-value pairs, retrieve values, delete a key-value pair, and check for the existence of a key.

