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
        Node<T>* new_node_ptr = new Node<T>;
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
        if (index < 0){return nullptr;}

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

int tests_run = 0, tests_failed = 0;

void check(bool condition, const string& name) {
    tests_run++;
    if (!condition) {
        tests_failed++;
        cout << "FAIL: " << name << endl;
    }
}

int main() {
    // // --- empty list ---
    // LinkedList<int> empty;
    // check(empty.size == 0, "empty: size is 0");
    // check(empty.head == nullptr && empty.tail == nullptr, "empty: head and tail are null");
    // check(empty.get_node_at_index(0) == nullptr, "empty: get index 0 is null");
    // empty.set_index(0, 99);
    // check(empty.size == 0 && empty.head == nullptr, "empty: set_index does nothing");
    // empty.display(); // should just print a blank line, not crash

    // // --- one element ---
    // LinkedList<int> one;
    // one.append(5);
    // check(one.size == 1, "one: size is 1");
    // check(one.head == one.tail, "one: head and tail are the same node");
    // check(one.head->prev == nullptr && one.head->next == nullptr, "one: no neighbours");
    // check(one.get_node_at_index(0)->item == 5, "one: get index 0");
    // check(one.get_node_at_index(1) == nullptr, "one: index 1 is out of range");

    // // --- several elements ---
    // LinkedList<int> list;
    // list.append(10);
    // list.append(20);
    // list.append(30);
    // check(list.size == 3, "list: size is 3");
    // check(list.head->item == 10, "list: head is first item");
    // check(list.tail->item == 30, "list: tail is last item");
    // check(list.get_node_at_index(0)->item == 10, "list: get index 0");
    // check(list.get_node_at_index(1)->item == 20, "list: get index 1");
    // check(list.get_node_at_index(2)->item == 30, "list: get index 2");

    // // prev / next links
    // check(list.head->next->item == 20, "links: head->next");
    // check(list.tail->prev->item == 20, "links: tail->prev");
    // check(list.head->prev == nullptr, "links: head->prev is null");
    // check(list.tail->next == nullptr, "links: tail->next is null");

    // // --- out of range ---
    // check(list.get_node_at_index(-1) == nullptr, "range: index -1 is null");
    // check(list.get_node_at_index(3) == nullptr, "range: index == size is null");
    // check(list.get_node_at_index(100) == nullptr, "range: large index is null");

    // // --- set_index ---
    // list.set_index(0, 1);
    // list.set_index(1, 2);
    // list.set_index(2, 3);
    // check(list.get_node_at_index(0)->item == 1, "set: first");
    // check(list.get_node_at_index(1)->item == 2, "set: middle");
    // check(list.get_node_at_index(2)->item == 3, "set: last");
    // list.set_index(-1, 777);
    // list.set_index(3, 777);
    // check(list.get_node_at_index(0)->item == 1 && list.tail->item == 3 && list.size == 3,
    //       "set: out-of-range indexes change nothing");

    // // --- other types (proves it's generic) ---
    // LinkedList<string> words;
    // words.append("hello");
    // words.append("world");
    // words.set_index(1, "there");
    // check(words.get_node_at_index(0)->item == "hello", "string: get index 0");
    // check(words.get_node_at_index(1)->item == "there", "string: set then get index 1");

    // LinkedList<double> nums;
    // nums.append(1.5);
    // nums.append(2.5);
    // check(nums.get_node_at_index(1)->item == 2.5, "double: get index 1");

    // // --- display ---
    // cout << "Linked List: ";
    // list.display();

    // cout << tests_run - tests_failed << "/" << tests_run << " tests passed" << endl;
    // return tests_failed == 0 ? 0 : 1;

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