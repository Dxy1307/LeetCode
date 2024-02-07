// Add Two Numbers
// Linked List | Math | Recursion
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        int surplus = 0;
        while (l1 != nullptr || l2 != nullptr || surplus) {
            int sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += surplus;
            surplus = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = temp->next;
        }
        return ans->next;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    ListNode* l1 = new ListNode(2);
    ListNode* newNode = new ListNode(4);
    l1->next = newNode;
    ListNode* secondNode = new ListNode(3);
    newNode->next = secondNode;

    ListNode* l2 = new ListNode(5);
    ListNode* newNode1 = new ListNode(6);
    l2->next = newNode1;
    ListNode* secondNode1 = new ListNode(4);
    newNode1->next = secondNode1;

    Solution so;
    ListNode* res = so.addTwoNumbers(l1, l2);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
// Dxy