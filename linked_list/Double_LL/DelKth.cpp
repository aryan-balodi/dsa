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
        DListNode *temp = new DListNode(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

DListNode *DelHead(DListNode *head) {
    if (head == nullptr || head->next == nullptr) return NULL;

    DListNode *prev = head;
    head = head->next;

    prev->next = nullptr;
    head->prev = nullptr;

    delete prev;
    return head;
}

DListNode *DelTail(DListNode *head) {
    if (head == nullptr || head->next == nullptr) return NULL;

    DListNode *tail = head;

    while (tail->next != nullptr) {
        tail = tail->next;
    }
    DListNode *prev = tail->prev;

    tail->prev = nullptr;
    prev->next = nullptr;

    delete tail;
    return head;

}

DListNode *DelKth(DListNode *head, int k) {
    if (head == nullptr) return NULL;

    DListNode *temp = head; int count = 0;

    while (temp != nullptr) {
        count++;
        if (count == k) break;
        temp = temp->next;
    }

    DListNode *back = temp->prev;
    DListNode *front = temp->next;

    if (back == NULL && front == NULL) {
        delete temp;
        return NULL;
    }

    else if (back == nullptr) { 
        return DelHead(head);
    }

    else if (front == nullptr) {
        return DelTail(head);
    }

    back->next = temp->next;
    front->prev = temp->prev;

    temp->next = nullptr;
    temp->prev = nullptr;

    delete temp;
    return head;
}

void print(DListNode *head) {
    while (head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "END" << endl;
}

int main() {
    vector<int> arr = {2,4,6,8,10};

    DListNode *head = Arr2DLL(arr);

    head = DelKth(head,5);

    print(head);
}

