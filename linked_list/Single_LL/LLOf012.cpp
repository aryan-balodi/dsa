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

ListNode *SortWCount(ListNode *head) {
    ListNode *temp = head;
    int count0 = 0; int count1 = 0; int count2 = 0;

    while(temp != nullptr) {
        if (temp->data == 0) count0++;
        else if (temp->data == 1) count1++;
        else count2++;
        temp = temp->next;
    }
    
    temp = head;
    while(temp != nullptr) {
        if (count0) {
            temp->data = 0;
            count0--;
        }
        else if (count1) {
            temp->data = 1;
            count1--;
        }
        else {
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }
    return head;
}

ListNode *SortonePass(ListNode *head) {
    ListNode *DummyZero = new ListNode(-1); ListNode *moverZero = DummyZero;
    ListNode *DummyOne = new ListNode(-1); ListNode *moverOne = DummyOne;
    ListNode *DummyTwo = new ListNode(-1); ListNode *moverTwo = DummyTwo;

    ListNode *temp = head;

    while (temp != nullptr) {
        if (temp->data == 0) {
            ListNode *newNode = new ListNode(temp->data);
            moverZero->next = newNode;
            moverZero = newNode;
        }
        else if (temp->data == 1) {
            ListNode *newNode = new ListNode(temp->data);
            moverOne->next = newNode;
            moverOne = newNode;
        }
        else {
            ListNode *newNode = new ListNode(temp->data);
            moverTwo->next = newNode;
            moverTwo = newNode;
        }
        temp = temp->next;
    }

    moverZero->next = DummyOne;
    moverOne->next = DummyTwo;

    return DummyZero->next;
}


void print(ListNode *head) {
    while (head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "END" << endl;
}


int main() {
    vector<int> arr = {1,0,1,2,0,2,1};

    ListNode *head = Arr2LL(arr);

    head = SortWCount(head);

    print(head);

    return 0;
}