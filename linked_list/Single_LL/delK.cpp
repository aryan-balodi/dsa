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

ListNode *print(ListNode *head) {
    ListNode *temp = head;

    while (temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "END" << endl;

    return head;
}

ListNode *removeK(ListNode *head, int k) {
    if (head == NULL) return head;

    if (k == 1) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int count = 0; ListNode *temp = head; ListNode *prev = NULL;

    while (temp) {
        count++;

        if (count == k) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {2,4,6,8,10};

    ListNode *head = Arr2LL(arr);

    head = removeK(head, 3);
    print(head);


}