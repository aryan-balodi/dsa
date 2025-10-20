#include<iostream>
using namespace std;

class DListNode {
    public:
    int data;
    DListNode *next;
    DListNode *prev;

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

DListNode *DelAllOccurances(DListNode *head, int k) {
    DListNode *temp = head;

    while (temp != nullptr) {
        if (temp->data == k) {
            if (temp == head) {
                head = head->next;
            }
            
            DListNode *nextNode = temp->next;
            DListNode *prevNode = temp->prev;

            if (nextNode) nextNode->prev = prevNode;
            if (prevNode) prevNode->next = nextNode;

            delete temp;

            temp = nextNode;
        }
        else {
            temp = temp->next;
        }
    }
    return head;

}

DListNode *Arr2DLL(vector<int> &arr) {
    DListNode *head = new DListNode(arr[0]);
    DListNode *prev = head;

    for (int i = 1; i < arr.size(); i++) {
        DListNode *temp = new DListNode(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(DListNode *head) {
    DListNode *mover = head;

    while (mover != nullptr) {
        cout << mover->data << "->";
        mover = mover->next;
    }
    cout << "END" << endl;
}

int main() {
    vector<int> arr = {2,2,6,2,10};

    DListNode *head = Arr2DLL(arr);

    head = DelAllOccurances(head,2);

    print(head);

    return 0;


}