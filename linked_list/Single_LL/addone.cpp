#include<iostream>
using namespace std;

class ListNode {
    public:
    int data;
    ListNode* next;

    public:
    ListNode(int data1, ListNode *next1) {
        data = data1;
        next = next1;
    }
    ListNode(int data1) {
        data = data1;
        next = nullptr;
    }

};

ListNode *reverseList(ListNode *head) {
    ListNode *current = head; ListNode *prev = nullptr;

    while (current != nullptr) {
        ListNode *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

ListNode *AddOne(ListNode *head) {
    head = reverseList(head);
    ListNode *temp = head;

    int carry = 1; 

    while (temp != 0) {
        int sum = (temp->data + carry);
        temp->data = sum % 10;
        carry = sum / 10;

        temp = temp->next;
    }

    if (carry != 0) {
        head = reverseList(head);
        ListNode *NewHead = new ListNode(carry,head);
        
        return NewHead;
    }

    head = reverseList(head);
    return head;
    
}

int RecursionHelper(ListNode *node) {
    if (node == nullptr) {
        return 1;
    }

    int carry = RecursionHelper(node->next);

    if (carry == 0) return 0;

    int sum = node->data + carry;
    node->data = sum % 10;
    return sum / 10;
} 

ListNode *AddOneRecursion(ListNode *head) {
    int carry = RecursionHelper(head);

    if (carry) {
        ListNode *NewHead = new ListNode(carry,head);
        head = NewHead;
    }

    return head;
}



ListNode *Arr2LL(vector<int> &arr) {
    ListNode *head = new ListNode(arr[0]);
    ListNode *mover = head;

    for (int i = 1; i < arr.size(); i++) {
        ListNode *temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void print(ListNode *head) {
    while (head != 0) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "END" << endl;
}

int main() {
    vector<int> arr = {9,9,9};

    ListNode *head = Arr2LL(arr);

    head = AddOneRecursion(head);

    print(head);

}