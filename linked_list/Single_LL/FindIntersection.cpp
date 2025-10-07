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

// Hashing

// calulate length and move it forward by d

ListNode *IntersectionPoint(ListNode *SHead, ListNode *BHead, int diff) {
    while (diff--) {
        BHead = BHead->next;
    }

    while (SHead != nullptr && BHead != nullptr && SHead != BHead) {
        SHead = SHead->next;
        BHead = BHead->next;
    }

    return SHead;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *tempA = headA; ListNode *tempB = headB;
    int countA = 0; int countB = 0;

    while (tempA != nullptr) {
        countA++;
        tempA = tempA->next;
    }

    while (tempB != nullptr) {
        countB++;
        tempB = tempB->next;
    }

    if (countA > countB) {
        return IntersectionPoint(headB, headA, countA - countB);
    }
    else {
        return IntersectionPoint(headA, headB, countB - countA);
    }
}


// keep traversing

// ListNode *OptimalIntersection


int main() {
    vector<int> arr1 = {4,1,8,4,5};
    vector<int> arr2 = {5,6,1};

    ListNode *headA = Arr2LL(arr1);
    ListNode *headB = Arr2LL(arr2);

    ListNode *tempA = headA;
    while (tempA != nullptr && tempA->data != 8) {
        tempA = tempA->next;
    }

    ListNode *tempB = headB;
    while (tempB->next != nullptr) {
        tempB = tempB->next;
    }

    tempB->next = tempA;

    ListNode *intersection = getIntersectionNode(headA,headB);

    if (intersection) {
        cout << "Intersection is at this address: " << intersection << " and the value in the node is: " << intersection->data << endl;
    }
    else {
        cout << "No Intersection" << endl;
    }
}