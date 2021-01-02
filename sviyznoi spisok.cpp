#include <iostream>
#include <string>

using namespace std;

struct Node {
    string value;
    Node *next;
    Node *prev;
};

Node *head;

void AddList(string value, int pos) {
    Node *new_Node = new Node;
    new_Node->value = value;
    if (head == NULL) {
        new_Node->next = new_Node;
        new_Node->prev = new_Node;
        head = new_Node;
    }
    else {
        Node *temp = head;
        for (int i = pos; i > 1; i--) {
            temp = temp->next;
        }
        temp->prev->next = new_Node;
        new_Node->prev = temp->prev;
        new_Node->next = temp;
        temp->prev = new_Node;
    }
}

void DeleteList(int pos) {
    if (head == NULL) {
        cout << "List empty!" << endl;
    }
    if (head == head->next) {
        delete head;
        head = NULL;
    }
    else {
        Node *temp = head;
        for (int i = pos; i > 1; i--) {
            temp = temp->next;
        }
        if (temp == head) {
            head = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}

void PrintNode() {
    Node *temp = head;
    do {
        cout << temp->value << "->";
        temp = temp->next;
    } while (temp != head);
    cout << "NULL";
}

int main() {
    AddList("3", 1);
    AddList("2", 2);
    AddList("1", 3);
    DeleteList(2);
    AddList("4", 2);
    PrintNode();
}