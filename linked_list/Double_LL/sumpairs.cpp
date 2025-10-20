#include<iostream>
using namespace std;

class DListNode {
    public:
    int data;
    DListNode *next;
    DListNode *prev;

    public:
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

vector<pair<int, int>> Brute(DListNode *head, int target) {
    vector<pair<int, int>> res;
    DListNode *temp1 = head;

    while (temp1 != nullptr) {
        DListNode *temp2 = temp1->next;

        while (temp2 != nullptr && temp1->data + temp2->data <= target) {
            if (temp1->data + temp2->data == target) {
                res.push_back({temp1->data, temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return res;
}

vector<pair<int, int>> TwoPointer(DListNode *head, int target) {
    vector<pair<int,int>> res;

    if (!head) return res;

    DListNode *left = head;
    DListNode *right = head;

    while (right->next != nullptr) {
        right = right->next;
    }

    while (left != right && right->next != left) {
        int sum = left->data + right->data;

        if (sum == target) {
            res.push_back({left->data,right->data});
            left = left-> next;
            right = right->prev;
        }
        else if (sum < target) {
            left = left->next;
        }
        else {
            right = right->prev;
        }
    }
    return res;
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
    cout << "END";
}

int main() {
    vector<int> arr = {2,4,6,8,10};

    DListNode *head = Arr2DLL(arr);

    int target = 10;

    vector<pair<int, int>> res = TwoPointer(head, target);

    cout << "Pairs with sum " << target << " are:\n";
    for (const auto &p : res) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;

}