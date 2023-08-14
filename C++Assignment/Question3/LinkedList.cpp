#include <iostream>

// Structure representing a node in the singly linked list
struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor
    SinglyLinkedList() {
        head = nullptr;
    }

    // Destructor
    ~SinglyLinkedList() {
        // Free the memory occupied by the linked list
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to insert a new node at the beginning of the linked list
    void insertAtBeginning(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a new node at the end of the linked list
    void insertAtEnd(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to delete the first occurrence of a given data from the linked list
    void deleteNode(int data) {
        if (head == nullptr) {
            std::cout << "Linked list is empty." << std::endl;
            return;
        }

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            std::cout << "Node with data " << data << " deleted." << std::endl;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data == data) {
                prev->next = current->next;
                delete current;
                std::cout << "Node with data " << data << " deleted." << std::endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        std::cout << "Node with data " << data << " not found." << std::endl;
    }

    // Function to search for a node with given data in the linked list
    void searchNode(int data) {
        Node* current = head;
        int position = 1;
        while (current != nullptr) {
            if (current->data == data) {
                std::cout << "Node with data " << data << " found at position " << position << "." << std::endl;
                return;
            }
            current = current->next;
            position++;
        }
        std::cout << "Node with data " << data << " not found." << std::endl;
    }

    // Function to display the linked list
    void displayList() {
        if (head == nullptr) {
            std::cout << "Linked list is empty." << std::endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    SinglyLinkedList myList;

    myList.insertAtBeginning(10);
    myList.insertAtBeginning(20);
    myList.insertAtEnd(30);
    myList.insertAtEnd(40);

    std::cout << "Linked list: ";
    myList.displayList();

    myList.searchNode(30);

    myList.deleteNode(20);

    std::cout << "Linked list after deletion: ";
    myList.displayList();

    return 0;
}

