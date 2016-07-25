/**
    Rasul Kerimov (CoderINusE)
    QUE2 - Queue (Pro)
    ~~O(n*logn)
*/
#include <bits/stdc++.h>
#define MAXN 10005
using namespace std;
typedef pair<int,int> p;
pair <int, int> a[MAXN + 2];
struct node {
    int val, num;
    node *left, *right;
    node() {}
    node(int val, int num) {
        this->val = val;
        this->num = num;
    }
};

inline void insert(node *n, p a) {
    if(n == NULL) {
        n = new node(1, a.first);
        return;
    }
    if(a.second < n->val) {
        n->val += 1;
        insert(n->left, a);
    }
    else {
        int tmp = max(0, a.second - n->val);
        insert(n->right, {a.first, tmp});
    }
}

void traverse(node* n) {
    if(n == NULL) return;
    traverse(n->left);
    printf("%d", n->num);
    traverse(n->right);
}

int main() {
    int tx, n; cin >> tx;
    for(int i = 0; i < tx; ++i) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d", &a[i].first);
        for(int i = 0; i < n; ++i) scanf("%d", &a[i].second);
        sort(a, a + n, ::greater<pair<int,int>>());
        node* root = NULL;
        for(int i = 0; i < n; ++i)
            insert(root, a[i]);
        traverse(root);
        printf("\n");

    }
}
