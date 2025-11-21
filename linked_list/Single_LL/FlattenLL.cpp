#include<iostream>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode *next;
    ListNode *child;

    public:
    ListNode(int data1, ListNode *next1, ListNode *child1) {
        data = data1;
        next = next1;
        child = child1;
    }

    ListNode(int data1) {
        data = data1;
        next = nullptr;
        child = nullptr;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->data << "->";
        head = head->child;
    }
    cout << "END" << endl;
}

ListNode *Merge(ListNode *head1, ListNode *head2) {
        ListNode *DummyNode = new ListNode(-1);
        ListNode *res = DummyNode;
        ListNode *t1 = head1; ListNode *t2 = head2;

        while (t1 != nullptr && t2 != nullptr) {
            if (t1->data < t2->data) {
                res->child = t1;
                res = t1;
                t1 = t1->child;
            }
            else {
                res->child = t2;
                res = t2;
                t2 = t2->child;
            }

            res->next = nullptr;
        }

        if (t1) res->child = t1;
        else res->child = t2;
        if (DummyNode->child) DummyNode->child->next = nullptr;

        return DummyNode->child;
    }

    ListNode* flattenLinkedList(ListNode* &head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *MergedHead = flattenLinkedList(head->next);

        return Merge(head, MergedHead);
    }

int main() {

ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);

    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);

    ListNode* n7 = new ListNode(7);
    ListNode* n8 = new ListNode(8);

    ListNode* n9 = new ListNode(9);
    ListNode* n12 = new ListNode(12);

    ListNode* n20 = new ListNode(20);

    // Horizontal links (next)
    n1->next = n4;
    n4->next = n7;
    n7->next = n9;
    n9->next = n20;

    // Vertical links (child)
    n1->child = n2; n2->child = n3;

    n4->child = n5; n5->child = n6;

    n7->child = n8;

    n9->child = n12;

    // Now n20 has no child

    // Flatten and print as required
    ListNode* flat = flattenLinkedList(n1);
    printList(flat);

    // Clean-up code (delete allocated memory) can be added as needed
    return 0;

}

// hello