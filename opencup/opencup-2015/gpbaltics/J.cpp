/**
    Rasul Kerimov (CoderINusE)
*/
#include <bits/stdc++.h>
#define MAXN 1000005
#define INF 2e18
#define _INF -20000000
#define RANDOM_INIT()   srand(time(NULL))
#define RANDOM(L, R)    (L + rand() % ((R) - (L) + 1)) // gen a random integer in [L, R]

typedef long long ll;
using namespace std;

ll mod = 1000000007;
int max_deap = 0, maxs_d[MAXN];

char x[11];
struct node {
    ll value;
    int length, width_number, beginp = 0;
    node *left, *right;
    node() {}
};
node *root;

void add_value(node *leaf, const ll &value) {
    if(value < leaf->value) {
        if(leaf->left == NULL) {
            ll temp_value = value;
            leaf->left = new node;
            leaf->left->value = value;
            leaf->left->width_number = 0;
            leaf->left->left = leaf->left->right = NULL;
            if(temp_value == 0) {
                leaf->left->width_number = 1;
            }
            else {
                while(temp_value) {
                    leaf->left->width_number += 1;
                    temp_value /= 10;
                }
            }
        }
        else
            add_value(leaf->left, value);
    }
    else {
        if(leaf->right == NULL) {
            ll temp_value = value;
            leaf->right = new node;
            leaf->right->value = value;
            leaf->right->width_number = 0;
            leaf->right->left = leaf->right->right = NULL;
            if(temp_value == 0) {
                leaf->right->width_number = 1;
            }
            else {
                while(temp_value) {
                    leaf->right->width_number += 1;
                    temp_value /= 10;
                }
            }
        }
        else
            add_value(leaf->right, value);
    }
}

void traverse(node *leaf) {
    if(leaf == NULL) return;

    if(leaf->left == NULL && leaf->right == NULL) {
        leaf->length = leaf->width_number;
        return;
    }
    traverse(leaf->left);
    traverse(leaf->right);

    leaf->length = (leaf->left == NULL ? 0 : leaf->left->length )
     +(leaf->right == NULL ? 0 : leaf->right->length) + leaf->width_number;
}

void traverse_begin(node *leaf, int deap) {
    max_deap = max(max_deap, deap);
    if(leaf == NULL) return;

    if(leaf->right) {
        leaf->right->beginp = leaf->width_number + leaf->beginp;
        if(leaf->left) {
            leaf->right->beginp += leaf->left->length;
        }
    }
    if(leaf->left) {
        leaf->left->beginp = leaf->beginp;
    }
    int d = leaf->width_number + leaf->beginp;
    if(leaf->left) d += leaf->left->length;

    if(d > maxs_d[deap]) maxs_d[deap] = d;
    traverse_begin(leaf->left, deap + 1);
    traverse_begin(leaf->right, deap + 1);
    return;
}

void print_result(node *leaf, int deap, char **result) {
    if(leaf == NULL) return;
    int begin_p = leaf->beginp;
    if(leaf->left) begin_p += leaf->left->length;
    ll value_temp = leaf->value;
    int len = 0;
    if(value_temp != 0) {
        while(value_temp) {
            x[len++] = (char)((value_temp % 10) + '0');
            value_temp /= 10;
        }
    }
    else {
        len = 1;
        x[0] = '0';
    }
    reverse(x, x + len);

    for(int i = 0; i < len; ++i) {
        result[deap][begin_p++] = x[i];
    }
    print_result(leaf->left, deap + 1, result);
    print_result(leaf->right, deap + 1, result);
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll value = 0, k = 0, z = 0, prev;
    while(scanf("%lld", &value) == 1) {
        if(k == 0) {
            root = new node;
            root->value = value;
            root->width_number = 0;
            root->left = root->right = NULL;
            if(value == 0)
                root->width_number = 1;
            else {
                while(value) {
                    root->width_number += 1;
                    value /= 10;
                }
            }
            k |= 1; continue;
        }
        add_value(root, value);
    }
    traverse(root);
    traverse_begin(root, 0);
    
    char **result = new char*[max_deap + 1];
    for(int i = 0; i < max_deap + 1; ++i) {
        result[i] = new char[maxs_d[i] + 1];
    }
    for(int i = 0; i < max_deap; ++i)
        for(int j = 0; j < maxs_d[i]; ++j) result[i][j] = ' ';

    print_result(root, 0, result);

    for(int j = 0; j < max_deap; ++j) {
        for(int i = 0; i < maxs_d[j]; ++i)
            printf("%c", result[j][i]);
        putchar('\n');
    }

}
