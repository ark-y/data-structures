#include <iostream>
using namespace std;

template <typename T>
struct Node {

    T item; 
    Node *next = nullptr;
    Node *prev = nullptr;

};

template <typename T>
struct LinkedList {
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    
    int size = 0;
    
    // TODO: determine what should the input of the method be and implement it
    void append(T item) {
        Node* new_node_ptr = new Node<T>;
        new_node_ptr->item = item;

        // If there are no nodes in my chain, this will be the first and last one
        if (head == nullptr) {
            head = tail = new_node_ptr;
            new_node_ptr->prev = nullptr; //nth before so null

            size++;
            
            return;
        }

        // Last one is already stored so add the pointer to the last one
        tail->next = new_node_ptr;
        new_node_ptr->prev = tail; //store prev 
        tail = new_node_ptr; 

        size++;
    }
    
    Node<T>* get_node_at_index(int index) {
        Node<T>* current_node = head;
        while (index > 0 && current_node != nullptr) {
            current_node = current_node->next;
            index--;
        }
        return current_node;
    }
    
    // TODO: determine what should the input of the method be and implement it
    void set_index(int index, T item) {
        Node<T>* node_at_index = get_node_at_index(index);
        if (node_at_index != nullptr) {
            node_at_index->item = item;
        }
    }
    
    void display() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList<int> list;
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