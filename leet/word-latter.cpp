class Solution {
public:
    unordered_set<string>::iterator it;
    unordered_map <int, string> mp;
    unordered_map <string, int> us;
    vector <int> d, p;
    vector <vector <int>> g;
    set <string>::iterator it1;

    struct node {
        int value;
        int step;
        string word;
        node* next;
        node(string s, int step, node *next) : word(s), step(step), next(next) {}
        node() {}
    };

    int zs = 0;

    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> ret;
        queue <node*> q;
        q.push(new node(beginWord, 1, NULL));
        wordList.insert(endWord);
        set <string> vis, unvis;

        for(it = wordList.begin(); it != wordList.end(); ++it)
            unvis.insert(*it);
        unvis.erase(beginWord);

        int preNumSteps = 0, minn = 0;

        while(!q.empty()) {
            node* top = q.front();
            q.pop();
            string w = top->word;
            int curr = top->step;
            //cout << w << endl;
            if(w == endWord) {
                if(minn == 0) minn = top->step;

                if(top->step == minn && minn != 0) {
                    vector <string> t;
                    while(top != NULL) {
                        t.push_back(top->word);
                        top = top->next;
                    }
                    reverse(t.begin(),t.end());
                    ret.push_back(t);
                    continue;
                }
            }

            if(preNumSteps < curr) {
                for(it1 = vis.begin(); it1 != vis.end(); ++it1) {
                    unvis.erase(*it1);
                }
            }
            preNumSteps = curr;
            for(int i = 0; i < w.size(); ++i) {

                for(char c = 'a'; c <= 'z'; ++c) {

                    char temp = w[i];
                    if(w[i] != c) w[i] = c;
                    if(unvis.count(w)) {
                        q.push(new node(w, top->step + 1, top));
                        vis.insert(w);
                    }
                    w[i] = temp;
                }
            }
        }

        return ret;
    }
};