#include <bits/stdc++.h>
#define MAX_CHAR 256
/**
    #126 - Word Ladder II
*/
#define MAXN 100005
using namespace std;

typedef long long ll;
unordered_set<string>::iterator it;
unordered_map <int, string> mp;
vector <int> d, p;
vector <vector <int>> g;

bool check(string a, string b) {
    int c = 0;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] != b[i]) c += 1;
    }
    return (c <= 1);
}

void __traverse(vector<string>& v, int n) {
    if(n == -1) return;
    v.push_back(mp[n]);
    __traverse(v, p[n]);
}

vector <vector <string>> bfs(int s, int n) {

    vector<vector<string>> ret;

    queue <int> q; q.push(s);
    vector <bool> used(n);
    d.resize(n + 1), p.resize(n + 1);
    used[s] = 1;
    p[s] = -1;
    d[s] = 0;

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        used[v] = 2;
        //  cout << v << endl;
        for(int i = 0; i < g[v].size(); ++i) {
            int to = g[v][i];
            if(used[to] != 2 && to != p[v]) {

                if(used[to] == 0) {
                    used[to] = 1;
                    q.push(to);
                    d[to] = d[v] + 1;
                    p[to] = v;

                    if(to == n - 1) {
                        vector <string> d; __traverse(d, to);
                        reverse(d.begin(), d.end());
                        ret.push_back(d);
                    }

                }
                else {
                    if(d[v] + 1 == d[to]) {
                        q.push(to);
                        p[to] = v;
                        if(to == n - 1) {
                            vector <string> d; __traverse(d, to);
                            reverse(d.begin(), d.end());
                            ret.push_back(d);
                        }
                    }
                    else if(d[v] + 1 < d[to]) {
                        q.push(to);
                        p[to] = v;

                        if(to == n - 1) {
                            ret.clear();
                            vector <string> d; __traverse(d, to);
                            reverse(d.begin(), d.end());
                            ret.push_back(d);
                        }
                    }
                }

            }
        }

    }

    return ret;

}

vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        int len = 0;
        mp[len++] = beginWord;

        for(it = wordList.begin(); it != wordList.end(); ++it) {
            //cout << *it << endl;
            mp[len++] = *it;
        }
        mp[len++] = endWord;
        g.resize(len + 1);

        for(int i = 0; i < len; ++i) {
            for(int j = i + 1; j < len; ++j) {
                if(check(mp[i], mp[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        vector<vector<string>> ret = bfs(0, len);
        return ret;
}


int main() {
    string a = "hit";
    string b = "cog";
    unordered_set <string> st;

    st.insert("hot");
    st.insert("dot");
    st.insert("dog");
    st.insert("lot");
    st.insert("lot");
    st.insert("log");

    vector<vector<string>> res = findLadders(a, b, st);

    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < res[i].size(); ++j) cout << res[i][j] << " ";
        cout << endl;
    }
}
