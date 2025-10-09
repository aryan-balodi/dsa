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

int Hashing(ListNode *head) {
    ListNode *temp = head; int time = 1;

    unordered_map<ListNode *, int> mpp;

    while (temp != nullptr) {
        if (mpp.find(temp) != mpp.end()) {
            int ans = time - mpp[temp];
            return ans;
        }
        mpp[temp] = time;

        time++;

        temp = temp->next;
    }
    return 0;
}

int LengthOfLoop(ListNode *slow, ListNode *fast) {
    int counter = 1; fast = fast->next;

    while (slow != fast) {
        counter++;
        fast = fast->next;
    }
    
    return counter;
}

int SlownFast(ListNode *head) {
    ListNode *fast = head; ListNode *slow = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return LengthOfLoop(slow,fast);
    }
    return 0;
}

int main() {
    vector<int> arr = {2,4,6,8,10,12};

    ListNode *head = Arr2LL(arr);

    ListNode *temp = head; ListNode *cyclepoint = nullptr;
    int pos = 2;

    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }
    cyclepoint = temp;

    ListNode *last = head;
    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = cyclepoint;

    cout << SlownFast(head) << endl;
}