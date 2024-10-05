#include <iostream>
using namespace std;

const int SIZE = 7;  

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
    Node *head = nullptr;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        add_node_front(head, tmp_val);
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    delete_node(head, entry);
    output(head);

    insert_node(head, entry, 10000);
    output(head);
    delete_linked_list(head);
    output(head);

    return 0;
}

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

void add_node_front(){
    Node *new_node = new Node;
    new_node->value = value;
    new_node->next = head;
    head = newnode;
}

void add_node_tail(){
    Node *newnode = new Node;
    new_node->value = value;
    new_node->next = nullptr;
    if (!head) {
        head = newnde;
    } else {
        Node *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void delete_node(){
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

void insert_node(){
    if (position < 1) return; // Invalid position
    Node *new_node = new Node
    new_node->value = value;
    Node *current = head;
    for (int i = 1; current && i < position; i++) {
        current = current->next;
    }
    if (current) {
        new_node->next = current->next;
        current->next = newNode;
    }
}

void delete_linked_list(){
    node *current = head;
    while (current){
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}