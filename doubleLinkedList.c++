#include <iostream>
using namespace std;

// Node class representing an element in the doubly linked list
class Node {
public:
    int Value;   // Stores the value of the node
    Node* Next;  // Pointer to the next node
    Node* Pre;   // Pointer to the previous node
    
    // Constructor to initialize a node with a value and set pointers to null
    Node(int value) {
        Value = value;
        Next = nullptr;
        Pre = nullptr;
    }
};

// Doubly Linked List class
class doubleLinkedList {
private:
    int length;  // Stores the number of nodes in the list
    Node* head;  // Points to the first node
    Node* tail;  // Points to the last node
    
public:
    // Constructor: Creates a linked list with an initial node
    doubleLinkedList(int value) {
        Node* newNode = new Node(value);  // Create the first node
        head = newNode;  // Head points to the first node
        tail = newNode;  // Tail also points to the first node since there's only one node
        length = 1;  // Initialize length to 1
    }

    // Append: Adds a new node at the end of the linked list
    void Append(int value) {
        Node* newNode = new Node(value);  // Create a new node
        if (length == 0) {  // If the list is empty
            head = newNode;
            tail = newNode;
        } else {
            tail->Next = newNode;  // Link the current tail to the new node
            newNode->Pre = tail;  // Link new node's previous to the old tail
            tail = newNode;  // Update tail to be the new node
        }
        length++;  // Increase the length of the list
    }

    // PreAppend: Adds a new node at the beginning of the linked list
    void PreAppend(int value) {
        Node* newNode = new Node(value);  // Create a new node
        if (length == 0) {  // If the list is empty
            head = newNode;
            tail = newNode;
        } else {
            head->Pre = newNode;  // Link current head's previous to new node
            newNode->Next = head;  // Link new node's next to the current head
            head = newNode;  // Update head to be the new node
        }
        length++;  // Increase the length of the list
    }
    
    // Insert: Inserts a new node at a specific index in the doubly linked list
    bool Insert(int index, int value) {
        // Step 1: Validate the index
        if (index < 0 || index > length) return false;  // Ensure the index is within valid bounds

        // Step 2: Handle special cases for inserting at the beginning or end
        if (index == 0) {  
            PreAppend(value);  // Use PreAppend if inserting at the head
            return true;
        } 
        if (index == length) {  
            Append(value);  // Use Append if inserting at the tail
            return true;
        }

        // Step 3: Create a new node with the given value
        Node* newNode = new Node(value);  

        // Step 4: Locate the insertion position
        Node* before = GetByIndex(index - 1);  // Get the node just before the insertion point
        Node* after = before->Next;  // The node currently at the insertion point

        // Step 5: Link the new node correctly
        newNode->Pre = before;  // New node's previous should point to `before`
        newNode->Next = after;  // New node's next should point to `after`
        before->Next = newNode;  // `before`'s next should now point to the new node
        if (after) {  
            after->Pre = newNode;  // `after`'s previous should point to the new node (if it exists)
        }

        // Step 6: Update the length of the list
        length++;

        return true;  // Indicate successful insertion
    }
   
    // Delete: Delete a node at a specific index in the doubly linked list
    void Delete(int index) {
        // Step 1: Validate the index
        if (index < 0 || index >= length) return;  // Ensure the index is within valid bounds
        // Step 2: Handle special cases for deleting at the beginning or end
        if (index == 0) {  
            DeleteFirst();
            return;
        } 
        if (index == length - 1) {  
            DeleteLast();
            return;
        }
        // Step 3: Find the node at the given index
        Node* temp = GetByIndex(index);
        // Step 4: Update links to bypass the node
        temp->Pre->Next = temp->Next;
        temp->Next->Pre = temp->Pre;
        // Step 5: Delete the node and update the length
        delete temp;
        length--;
    }

    // DeleteLast: Removes the last node from the list
    void DeleteLast() {
        if (length == 0) return;  // If list is empty, do nothing
        
        Node* temp = tail;  // Store the node to delete
        if (length == 1) {  // If there's only one node
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->Pre;  // Move tail to the previous node
            tail->Next = nullptr;  // Disconnect the last node
        }
        delete temp;  // Free memory
        length--;  // Decrease list length
    }

    // DeleteFirst: Removes the first node from the list
    void DeleteFirst() {
        if (length == 0) return;  // If list is empty, do nothing
        
        Node* temp = head;  // Store the node to delete
        if (length == 1) {  // If there's only one node
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->Next;  // Move head to the next node
            head->Pre = nullptr;  // Disconnect the first node
        }
        delete temp;  // Free memory
        length--;  // Decrease list length
    }

    // GetByIndex: Retrieves a node at a specific index
    Node* GetByIndex(int index) {
        if (index < 0 || index >= length) return nullptr;  // Check for out-of-bounds
        
        Node* temp;
        if (index <= length / 2) {  // If index is in the first half, traverse from the head
            temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->Next;
            }
        } else {  // If index is in the second half, traverse from the tail
            temp = tail;
            for (int i = length - 1; i > index; i--) {  // Traverse backwards
                temp = temp->Pre;
            }
        }
        return temp;  // Return the found node
    }
    
    // SetByIndex: Updates the value of a node at a specific index
    bool SetByIndex(int index, int value) {
        Node* temp = GetByIndex(index);  // Get node at the given index
        if (temp) {  // Ensure the node exists before modifying
            temp->Value = value;  // Update the node's value
            return true;
        }
        return false;
    }
    
    // Print: Displays the values in the linked list
    void Print() {
        if (length == 0) {  // If list is empty
            cout << "Empty list" << endl;
            return;
        }
        Node* temp = head;
        while (temp) {  // Traverse and print each node
            cout << temp->Value << " ";
            temp = temp->Next;
        }
        cout << endl;
    }
    
    //////////////////////////////////////////////////( ** Interview Questions **)/////////////////////////////////////
   
    //DLL: Swap First and Last ( ** Interview Question)
    void swapFirstLast() {
        // Check if the list has less than 2 nodes
        if (length < 2) return;
     
        // Store head node's value in a temp variable
        int temp = head->Value;
     
        // Set head node's value to tail node's value
        head->Value = tail->Value;
     
        // Set tail node's value to the original head node's value
        tail->Value = temp;
    }
    
    //DLL: Reverse ( ** Interview Question)
    void Reverse() {
        if (length < 2) return;  // No need to reverse if list has 0 or 1 elements
    
        Node* current = head;
        Node* temp = nullptr;
    
        // Swap the Next and Pre pointers for each node
        while (current) {
            temp = current->Pre;  
            current->Pre = current->Next;
            current->Next = temp;
            current = current->Pre;  // Move to the next node (which is now in `Pre`)
        }
    
        // Swap head and tail pointers
        temp = head;
        head = tail;
        tail = temp;
    
        // Ensure the new tail's `Next` is null
        tail->Next = nullptr;
    }
    
    //DLL: Palindrome Checker ( ** Interview Question)
    bool isPalindrome() {
        if (length <= 1) return true;
    
        Node* forwardNode = head;
        Node* backwardNode = tail;
        for (int i = 0; i < length / 2; i++) {
            if (forwardNode->Value != backwardNode->Value) return false;
            forwardNode = forwardNode->Next;
            backwardNode = backwardNode->Pre;
        }
        return true;
    }
    
    
    //DLL: swapPairs ( ** Interview Question)
    void swapPairs() {
        // If the list is empty or has only one node, no need to swap
        if (length < 2) return;
        // Create a dummy node to simplify swapping logic, especially for the head
        Node* dummyNode = new Node(0);
        dummyNode->Next = head;
        head->Pre = dummyNode; // Connect dummy node to head
        Node* current = head; // Start swapping from the first node
        while (current && current->Next) { // Ensure there are at least two nodes to swap
            Node* first = current;
            Node* second = current->Next;
            // Connect the previous node to the second node (swap start)
            first->Pre->Next = second;
            // Update first node's Next pointer to skip second node
            first->Next = second->Next;
            // Update second node's Next pointer to point to first (swapping)
            second->Next = first;
            // Update second node's Pre pointer to point to first's previous node
            second->Pre = first->Pre;
            // Update first node's Pre pointer to point to second
            first->Pre = second;
            // If there is a node after first, update its Pre pointer to first
            if (first->Next != nullptr) {
                first->Next->Pre = first;
            }
            // Move current pointer forward by two nodes to continue swapping
            current = first->Next;
        }
        // Update head to point to the new first node
        head = dummyNode->Next;
        head->Pre = nullptr; // Remove dummy node reference
        delete dummyNode; // Free memory to avoid memory leaks
    }
    
    // Destructor: Frees memory by deleting all nodes
    ~doubleLinkedList() {
        Node* temp = head;
        while (temp) {  // Traverse and delete each node
            Node* next = temp->Next;
            delete temp;
            temp = next;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
};
// Main function to test the linked list implementation
int main() {
    // Create a linked list with an initial value of 1
    doubleLinkedList* myDll = new doubleLinkedList(1);
    cout << "Initial list with value 1: ";
    myDll->Print();

    // Append values 2, 3, 4, 5, 6 to the list
    cout << "Appending values 2, 3, 4, 5, 6 to the list...\n";
    myDll->Append(2);
    myDll->Append(3);
    myDll->Append(4);
    myDll->Append(5);
    myDll->Append(6);
    cout << "Current List: ";
    myDll->Print();

    // Prepend value 0 to the list
    cout << "\nPrepending value 0 to the list...\n";
    myDll->PreAppend(0);
    cout << "Updated List: ";
    myDll->Print();

    // Insert value 99 at index 3
    cout << "\nInserting value 99 at index 3...\n";
    myDll->Insert(3, 99);
    cout << "List after insertion: ";
    myDll->Print();

    // Delete the first node
    cout << "\nDeleting the first node...\n";
    myDll->DeleteFirst();
    cout << "List after deleting first node: ";
    myDll->Print();

    // Delete the last node
    cout << "\nDeleting the last node...\n";
    myDll->DeleteLast();
    cout << "List after deleting last node: ";
    myDll->Print();

    // Delete node at index 2
    cout << "\nDeleting node at index 2...\n";
    myDll->Delete(2);
    cout << "List after deleting node at index 2: ";
    myDll->Print();

    // Set value at index 2 to 13
    cout << "\nSetting value at index 2 to 13...\n";
    myDll->SetByIndex(2, 13);
    cout << "Updated List: ";
    myDll->Print();

    // Get value at index 2
    cout << "\nGetting value at index 2...\n";
    Node* nodeAtIndex2 = myDll->GetByIndex(2);
    if (nodeAtIndex2) {
        cout << "Value at index 2: " << nodeAtIndex2->Value << "\n";
    } else {
        cout << "Index out of range!\n";
    }

    // Swap first and last nodes
    cout << "\nSwapping first and last nodes...\n";
    myDll->swapFirstLast();
    cout << "List after swapping first and last nodes: ";
    myDll->Print();

    // Reverse the list
    cout << "\nReversing the list...\n";
    myDll->Reverse();
    cout << "List after reversing: ";
    myDll->Print();

    // Check if the list is a palindrome
    cout << "\nChecking if the list is a palindrome...\n";
    if (myDll->isPalindrome()) {
        cout << "The list is a palindrome.\n";
    } else {
        cout << "The list is not a palindrome.\n";
    }

    // Swap pairs of nodes
    cout << "\nSwapping pairs of nodes...\n";
    myDll->swapPairs();
    cout << "List after swapping pairs: ";
    myDll->Print();

    // Free allocated memory
    delete myDll;
    cout << "\nMemory freed. Program ended successfully.\n";

    return 0;
}
