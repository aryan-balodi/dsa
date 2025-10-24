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

void print(ListNode *head) {
    ListNode *mover = head;

    while (mover != nullptr) {
        cout << mover->data << "->";
        mover = mover->next;
    }
    cout << "END" << endl;
}

ListNode *Merge2SortedLL(ListNode *head1, ListNode *head2) {
    ListNode *mover1 = head1; ListNode *mover2 = head2;

    vector<int> container;

    while (mover1 != nullptr) {
        container.push_back(mover1->data);
        mover1 = mover1->next;
    }

    while (mover2 != nullptr) {
        container.push_back(mover2->data);
        mover2 = mover2->next;
    }

    sort(container.begin(), container.end());

    ListNode *newhead = Arr2LL(container);

    return newhead;

}




int main() {
    vector<int> arr1 = {2,4,6,8};
    vector<int> arr2 = {3,5,7,9};

    ListNode *head1 = Arr2LL(arr1);
    ListNode *head2 = Arr2LL(arr2);

    ListNode *mergedhead = Merge2SortedLL(head1, head2);

    print(mergedhead);

    return 0;
}