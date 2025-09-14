#include<iostream>
using namespace std;

class ListNode {
  public:
  int data;
  ListNode *next;
  
  public:
  ListNode(int data1, ListNode* next1) {
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

ListNode *removeHead(ListNode *head) {
    if (head == NULL) return head;

    ListNode *temp = head;
    head = head->next;
    delete temp;
    return head;
}

void print(ListNode *head) {
    ListNode *temp = head;

    while (temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    vector<int> arr = {5,7,9,11,13};

    ListNode *head = Arr2LL(arr);

    head  = removeHead(head);

    
    print(head);
}