# Doubly Linked List Implementation in C++

This repository contains a C++ implementation of a **Doubly Linked List** data structure. A doubly linked list is a linear data structure where each node contains a value and two pointers: one to the next node and one to the previous node. This allows for bidirectional traversal, making operations like insertion, deletion, and traversal more efficient in certain scenarios.

## Table of Contents
1. [Features](#features)
2. [Implementation Details](#implementation-details)
3. [Usage](#usage)
4. [Example Code](#example-code)
5. [Contributing](#contributing)
6. [License](#license)

---

## Features

- **Node Operations**:
  - Append a node to the end of the list.
  - Prepend a node to the beginning of the list.
  - Insert a node at a specific index.
  - Delete a node at a specific index.
  - Delete the first or last node.

- **List Operations**:
  - Reverse the list.
  - Swap the first and last nodes.
  - Swap pairs of nodes.
  - Check if the list is a palindrome.

- **Utility Functions**:
  - Get a node by index.
  - Update the value of a node by index.
  - Print the list.

---

## Implementation Details

The doubly linked list is implemented using two classes:
1. **`Node`**: Represents a single node in the list. Each node contains:
   - `Value`: The data stored in the node.
   - `Next`: A pointer to the next node.
   - `Pre`: A pointer to the previous node.

2. **`doubleLinkedList`**: Manages the list and provides methods for operations like insertion, deletion, traversal, and more. Key features include:
   - Efficient traversal in both directions.
   - Dynamic resizing as nodes are added or removed.
   - Memory management to avoid leaks.

---

## Usage

To use this implementation in your project:
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/doubly-linked-list.git
   ```
2. Include the `doublyLinkedList` class in your C++ project.
3. Create an instance of the `doubleLinkedList` class and use its methods to manipulate the list.

---

## Example Code

Here’s an example of how to use the `doubleLinkedList` class:

```cpp
#include <iostream>
#include "doubleLinkedList.h"

int main() {
    // Create a new doubly linked list
    doubleLinkedList* myList = new doubleLinkedList(1);

    // Append values to the list
    myList->Append(2);
    myList->Append(3);
    myList->Append(4);

    // Prepend a value to the list
    myList->PreAppend(0);

    // Insert a value at index 2
    myList->Insert(2, 99);

    // Print the list
    std::cout << "Current List: ";
    myList->Print();

    // Reverse the list
    myList->Reverse();
    std::cout << "Reversed List: ";
    myList->Print();

    // Check if the list is a palindrome
    if (myList->isPalindrome()) {
        std::cout << "The list is a palindrome.\n";
    } else {
        std::cout << "The list is not a palindrome.\n";
    }

    // Delete the list to free memory
    delete myList;

    return 0;
}
```

### Output:
```
Current List: 0 1 99 2 3 4 
Reversed List: 4 3 2 99 1 0 
The list is not a palindrome.
```

---

## Contributing

Contributions are welcome! If you’d like to contribute to this project, please follow these steps:
1. Fork the repository.
2. Create a new branch for your feature or bugfix.
3. Commit your changes.
4. Submit a pull request with a detailed description of your changes.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Acknowledgments

- This implementation was created as part of a learning exercise to understand doubly linked lists and their applications.
- Special thanks to the C++ community for providing valuable resources and inspiration.

---

Feel free to explore the code, raise issues, or suggest improvements. Happy coding! 🚀
```

### How to Use:
1. Copy the above code.
2. Create a file named `README.md` in your GitHub repository.
3. Paste the code into the `README.md` file.
4. Commit and push the changes to your repository.

This will create a professional and well-structured `README.md` file for your project!
