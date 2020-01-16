#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <list>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

void FreeList(ListNode *l) {
    while (l) {
        ListNode *l_next = l->next;
        delete l;
        l = l_next;
    }
}


class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        ListNode *r = new ListNode((l1->val + l2->val) % 10);
        if (l1->val + l2->val > 9) {
            carry = 1;
        }
        l1 = l1->next;
        l2 = l2->next;
        ListNode *p = r;
        while (l1 && l2) {
            ListNode *t = new ListNode((l1->val + l2->val + carry) % 10);
            carry = l1->val + l2->val + carry > 9 ? 1 : 0;
            l1 = l1->next;
            l2 = l2->next;
            p->next = t;
            p = p->next;
        }
        while (l1) {
            ListNode *t = new ListNode((l1->val + carry) % 10);
            carry = l1->val + carry > 9 ? 1 : 0;
            l1 = l1->next;
            p->next = t;
            p = p->next;
        }
        while (l2) {
            ListNode *t = new ListNode((l2->val + carry) % 10);
            carry = l2->val + carry > 9 ? 1 : 0;
            l2 = l2->next;
            p->next = t;
            p = p->next;
        }
        if (carry > 0) {
            p->next = new ListNode(1);
        }
        return r;
    }
};

int main() {
    int len1, len2, temp;
    cin >> len1 >> len2 >> temp;
    ListNode *L1 = new ListNode(temp);
    ListNode *Lp = L1;
    for (int i = 0; i < len1 - 1; ++i) {
        cin >> temp;
        ListNode *t = new ListNode(temp);
        Lp->next = t;
        Lp = Lp->next;
    }
    cin >> temp;
    ListNode *L2 = new ListNode(temp);
    Lp = L2;
    for (int i = 0; i < len2 - 1; ++i) {
        cin >> temp;
        ListNode *t = new ListNode(temp);
        Lp->next = t;
        Lp = Lp->next;
    }

    Solution solution;
    ListNode *r = solution.addTwoNumbers(L1, L2);
    cout << "question is:" << endl;
    while (r) {
        cout << r->val << ' ';
        r = r->next;
    }
    FreeList(L1);
    FreeList(L2);
    FreeList(r);

    return 0;
}