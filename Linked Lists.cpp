#include <iostream>
using namespace std;

template <typename T>
struct Node {

    T value; 
    int size;
    Node *next = nullptr;
    Node *prev = nullptr;

};

struct LinkedList {
    Node* first_node = nullptr;
    
    int size = 0;
    
    // TODO: determine what should the input of the method be and implement it
    void append(...) {
        // ...
    }
    
    Node* get_node_at_index(int index) {
        // ...
    }
    
    // TODO: determine what should the input of the method be and implement it
    void set_index(...) {
        // ...
    }
    
    void display() {
        // This method is not marked (it's optional)
        // But it will be very helpful for your debugging to have a method that
        // prints what's in the linked list currently.
    }
};

/// Test the linked list implementation
int main() {
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    
    cout << "Linked List: ";
    list.display();
    
    list.set_index(1, 25);
    cout << "Linked List after setting index 1 to 25: ";
    list.display();
    
    cout << "Item at index 2: " << list.get_node_at_index(2)->item << endl;
    return 0;
}