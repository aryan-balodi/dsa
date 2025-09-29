#include<iostream>
using namespace std;

class ListNode {
    public:
    int data;
    ListNode *next;

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

ListNode *sumList(ListNode *head1, ListNode *head2) {
    ListNode *t1 = head1; ListNode *t2 = head2;
    ListNode *dummy = new ListNode(-1); 
    ListNode *mover = dummy;
    int carry = 0;  

    while (t1 != nullptr || t2 != nullptr) {
        int sum = carry;
        if (t1) sum += t1->data;
        if (t2) sum += t2->data;

        ListNode *newNode = new ListNode(sum % 10);
        carry = sum / 10;

        mover->next = newNode;
        mover = mover->next;

        if (t1) t1 = t1->next;
        if (t2) t2 = t2->next;

    }

    if (carry) {
        ListNode *newNode = new ListNode(carry);
        mover->next = newNode;
    }

    return dummy->next;
}


void print(ListNode *head) {
    while (head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "END" << endl;
}


int main() {
    vector<int> arr1 = {3,5};
    vector<int> arr2 = {4,5,9,9};

    ListNode *head1 = Arr2LL(arr1);
    ListNode *head2 = Arr2LL(arr2);

    ListNode *sumListHead = sumList(head1, head2);

    print(sumListHead);
}