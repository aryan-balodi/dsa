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

void print(ListNode *head) {
    while (head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "END" << endl; 
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

ListNode *HeadAfterGrouping(ListNode *head) {
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = head->next;

    if (head == nullptr || head->next == nullptr) return head;
    
    while (even != nullptr && even->next != nullptr  ) {
        odd->next = even->next;
        odd = even->next;
        
        even->next = odd->next;
        even = odd->next;
    }
    odd->next = evenHead;

    return head;
}


int main() {
    vector<int> arr = {2,3,1,4,5,6};

    ListNode *head = Arr2LL(arr);

    print(HeadAfterGrouping(head));
}