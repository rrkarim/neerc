#include <bits/stdc++.h>
#include <math.h>
#define INF 100000000000005
#define INFI 1073741824
#define MAXN 305

using namespace std;
#define fir first
#define sec second
#define pb push_back
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi ;

const ll mod = 1e9 + 7ll;
//
const int size_ = 2;
struct node {
    int is_leaf, size_, in_;
    node *left_, *right_;
    node() {
        left_ = right_ = NULL;
        is_leaf = size_ = in_ = 0;
    }
};

vector <int> convert_to_bin(int n) {
    vector <int> vi;
    while(n) {
        vi.push_back(n & 1);
        n /= 2;
    }
    vi.resize(size_, 0); reverse(vi.begin(), vi.end());
    return vi;
}

class Trie {
public:
    node *root;
    map<node*, node*> mp;

    Trie() {
        root = new node();
    }

    void add(const int& n) {
        vector <int> vi = convert_to_bin(n);
        add_(root, vi, 0);
    }

    void add_(node *curr, vector <int>& vi, int index) {
        if(index == vi.size()) {
            curr->is_leaf = 1;
            return;
        }

        if(vi[index]) {
            if(curr->right_ == NULL)
                curr->right_ = new node();
            add_(curr->right_, vi, index+1);
        } else {
            if(curr->left_ == NULL)
                curr->left_ = new node();
            add_(curr->left_, vi, index+1);
        }
    }

    int get(const int& c) {
        vector <int> vi = convert_to_bin(c), res; res.resize(size_, 0);
        res.resize(size_, 0);
        get_(root, c, vi, res, 0);

        int ans = 0;

        for(int i = vi.size() - 1; i >= 0; --i)
            ans += vi[i] * (1 << i);
        return ans;
    }

    void get_(node *curr, const int& c, vector <int>& vi, vector<int>& res, int index) {

        curr->in_ += 1;
        if(curr->in_ == 2) {
            vi[index - 1] = !vi[index - 1];
            get_(mp[curr], c, vi, res, index - 1);
            return;
        }

        if(vi[index]) {
            if(curr->right_ == NULL) {
                res[index] = vi[index];
                return;
            }
            else {
                if(curr->right_->size_ == (1 << (size_ - index)) - 1) {
                    if(curr->left_ == NULL) return;
                    else if(curr->left_->size_ == (1 << (size_ - index)) - 1) {
                        vi[index - 1] = !vi[index - 1];
                        get_(curr, c, vi, res, index - 1);
                    }
                    else {
                        res[index] = !vi[index];
                        get_(curr->left_, c, vi, res, index + 1);
                    }
                }
                else get_(curr->right_, c, vi, res, index + 1);
            }
        } else {
            if(curr->left_ == NULL) {
                res[index] = vi[index];
                return;
            }
            else {
               if(curr->left_->size_ == (1 << (size_ - index)) - 1) {
                    if(curr->right_ == NULL) {
                        res[index] = !vi[index];
                        return;
                    }
                    else if(curr->right_->size_ == (1 << (size_ - index)) - 1) {
                        vi[index - 1] = !vi[index - 1];
                        get_(curr, c, vi, res, index - 1);
                    }
                    else {
                        res[index] = !vi[index];
                        get_(curr->right_, c, vi, res, index + 1);
                    }
               }
               else get_(curr->left_, c, vi, res, index + 1);
            }
        }
    }

    int get_size(node* n, node* pre=NULL) {
        mp[n] = pre;
        if(n->is_leaf) return n->size_ = 1;
        int sum = 0;
        if(n->left_) sum += get_size(n->left_, n);
        if(n->right_) sum += get_size(n->right_, n);
        return n->size_ = sum + 1;
    }
};

Trie* trie_;

int main() {
    trie_ = new Trie();
    int n, m, x, c = 0; scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        trie_->add(x);
    }

    trie_->get_size(trie_->root);

    for(int i = 0; i < m; ++i) {
        scanf("%d", &x);
        c += x;
        printf("%d\n", trie_->get(c));
    }
}

