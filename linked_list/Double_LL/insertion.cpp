#include<iostream>
using namespace std;

class DListNode {
    public:
    int data;
    DListNode *next;
    DListNode *prev;

    public:
    DListNode(int data1, DListNode *next1, DListNode *prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

    DListNode(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

DListNode *Arr2DLL(vector<int> &arr) {
    DListNode *head = new DListNode(arr[0]);
    DListNode *prev = head;

    for (int i = 1; i < arr.size(); i++) {
        DListNode *temp = new DListNode(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp; 
    }
    return head;
}

void print(DListNode *head) {
    while (head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "END" << endl;
}

DListNode *Insert_Before_Head(DListNode *head, int val) {
    DListNode *newHead = new DListNode(val,head,nullptr);
    head->prev = newHead;

    return newHead;
}

DListNode *Insert_Before_Tail(DListNode *head, int val) {
    if (head->next == nullptr) return Insert_Before_Head(head,val);
    
    DListNode *tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    DListNode *back = tail->prev;
    DListNode *newNode = new DListNode(val,tail,back);

    back->next = newNode;
    tail->prev = newNode;

    return head;
}

DListNode *Insert_Before_kth(DListNode *head, int val, int k) {
    if (k == 1) return Insert_Before_Head(head,val);
    
    DListNode *temp = head; int count = 0;

    while (temp != nullptr) {
        count++;
        if (count == k) break;
        temp = temp->next;
    }

    DListNode *back = temp->prev;
    DListNode *newNode = new DListNode(val,temp,back);

    back->next = newNode;
    temp->prev = newNode;

    return head;
}

int main() {
    vector<int> arr = {2,4,6,8,10};

    DListNode *head = Arr2DLL(arr);

    head = Insert_Before_Tail(head,100);

    print(head);

    return 0;
}