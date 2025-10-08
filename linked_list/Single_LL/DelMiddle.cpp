#include<iostream>
using namespace std;

class ListNode {
    public:
    int data;
    ListNode *next;

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

void print(ListNode *head) {
    while (head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "END" << endl;
}

int ReturnLen(ListNode *head) {
    ListNode *temp = head;  
    int length = 0;
    
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}

ListNode *NaiveApproach(ListNode *head) {
    int Length = ReturnLen(head);

    int middle = (Length / 2);

    if (head == NULL || head->next == nullptr) return NULL;

    ListNode *temp = head;
    ListNode *prev = nullptr;

    for (int i = 0; i < middle; i++) {
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = temp->next;
    delete temp;

    return head;

}

ListNode *OptimalApproach(ListNode *head) {
    ListNode *fast = head; ListNode *slow = head;
    ListNode *prev = head;

    if (head == NULL || head->next == nullptr) return NULL;
    
    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode *temp = slow;
    prev->next = slow->next;
    delete temp;

    return head;

}

int main() {
    vector<int> arr = {2,4,6,8,10,12};

    ListNode *head = Arr2LL(arr);

    head = OptimalApproach(head);

    print(head);
}