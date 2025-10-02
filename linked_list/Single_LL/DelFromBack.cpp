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
    while (head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "END" << endl;
}


ListNode *Brute(ListNode *head, int N) {
    ListNode *temp = head;
    int count = 0;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    if (count == N) {
        ListNode *newHead = head->next;
        delete head;
        return newHead;
    }

    temp = head;
    int resultant = (count - N);
    while (temp != nullptr) {
        resultant--;

        if (resultant == 0) break;

        temp = temp->next;
    }

    ListNode *DelNode = temp->next;
    temp->next = DelNode->next;
    delete DelNode;

    return head;
}

ListNode *FastNSlow(ListNode *head, int N) {
    ListNode *Fast = head; ListNode *Slow = head;

    for (int i = 0; i <= N; i++) {
        Fast = Fast->next;
    }

    while (Fast != nullptr) {
        Fast = Fast->next;
        Slow = Slow->next;
    }
    ListNode *DelNode = Slow->next;
    Slow->next = DelNode->next;
    delete DelNode;

    return head;
}

int main() {
    vector<int> arr = {1,5,3,8,7,2};

    ListNode *head = Arr2LL(arr);

    head = FastNSlow(head,2);

    print(head);

    return 0;
};