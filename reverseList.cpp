#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x) : val(x),next(nullptr){};
};

Node* Reverse_recursive(Node*& head)

{
    stack<Node*> st;
    Node* tmp = head;
    while(tmp != nullptr){
        st.push(tmp);
        tmp = tmp->next;
    }
    
    head = st.top();
    // st.pop();
    // tmp = head;
    while(!st.empty()){
        tmp = st.top();
        st.pop();
        tmp = tmp->next;
    }
    tmp->next = nullptr;
    return head;
} 
Node* arrayToLinkedList(int arr[], int size) {
    if (size == 0) {
        return nullptr;
    }

    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < size; ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* linkedList = arrayToLinkedList(arr, size);
    printLinkedList(linkedList);

    Node* reverseList = Reverse_recursive(linkedList);
    printLinkedList(reverseList);

    // 释放链表的内存
    Node* current = linkedList;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}