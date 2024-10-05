#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void add_node_front(Node *&, float);
void add_node_tail(Node *&, float);
void delete_node(Node *&, int);
void insert_node(Node *&, int, float);
void delete_linked_list(Node *&);

int main() {
    srand(time(0));
    Node *head = nullptr;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        add_node_front(head, tmp_val);
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    if (entry < 1 || entry > SIZE) { 
        cout << "Invalid node number. Please enter a valid number." << endl;
    } else {
        delete_node(head, entry);
        output(head);
        SIZE--;
    }

    cout << "Enter position: ";
    cin >> entry;

if (entry < 1 || entry > SIZE + 1) { 
        cout << "Invalid position." << endl;
    } else {
        insert_node(head, entry, 10000);
        output(head);
        SIZE++;
    }
    
    delete_linked_list(head);
    output(head);

    return 0;
}
//displays stuff of nodes from list
void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}
//add new node in front of list
void add_node_front(Node *&head, float value){
    Node *new_node = new Node;
    new_node->value = value;
    new_node->next = head;
    head = new_node;
}
//add new node in end of list
void add_node_tail(Node *&head, float value){
    Node *new_node = new Node;
    new_node->value = value;
    new_node->next = nullptr;
    if (!head) {
        head = new_node;
    } else {
        Node *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
}
//delete node from list
void delete_node(Node *&head, int position){
    if (!head || position < 1) return;
    Node *current = head;
    Node *prev = nullptr;
    if (position == 1) {
        head = current->next;
        delete current;
        return;
    }
    for (int i = 1; current && i < position; i++) {
        prev = current;
        current = current->next;
    }
    if (current) {
        prev->next = current->next;
        delete current;
    }
}
//inesert node in list
void insert_node(Node *&head, int position, float value){
    if (position < 1) return;
    Node *new_node = new Node;
    new_node->value = value;
    Node *current = head;
    if (position == 1) {
        new_node->next = head;
        head = new_node;
        return;
    }
    for (int i = 1; current && i < position; i++) {
        current = current->next;
    }
    if (current) {
        new_node->next = current->next;
        current->next = new_node;
    } else {
        delete new_node;
    }
}

//delete entire list
void delete_linked_list(Node *&head){
    Node *current = head;
    while (current){
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}