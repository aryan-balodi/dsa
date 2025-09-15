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

ListNode *InAtHead(ListNode *head, int ele) {
    ListNode *temp = new ListNode(ele,head);
    return temp;
}

ListNode *InAtTail(ListNode *head, int ele) {
    if (head == NULL) return new ListNode(ele);

    ListNode *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    ListNode *newNode = new ListNode(ele);
    temp->next = newNode;

    return head;
}

ListNode *InAtpos(ListNode *head, int pos, int ele) {
    if (head == NULL) {
        if (pos == 1) return new ListNode(ele);
        else return NULL;
    }
    if (pos == 1) {
        return new ListNode(ele,head);
    }

    ListNode *temp = head; int count = 0;

    while (temp != NULL) {
        count++;

        if (count == pos - 1) {
            ListNode *newNode = new ListNode(ele,temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return head;

}

ListNode *InBeforeVal(ListNode *head, int val, int ele) {
    if (head == NULL) {
        return NULL;
    }

    if (head->data == val) {
        return new ListNode(ele,head);
    }

    ListNode *temp = head; 
    while (temp->next != NULL) {
        if (temp->next->data == val) {
            ListNode *newNode = new ListNode(ele,temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
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
    ListNode *temp = head;

    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "END" << endl;
}

int main() {
    vector<int> arr = {2,4,6,8,10};

    ListNode *head = Arr2LL(arr);

    head = InBeforeVal(head,8,100);
    print(head);

}