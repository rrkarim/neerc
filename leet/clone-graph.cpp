/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
 
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if(node == NULL) {
        UndirectedGraphNode *clone = NULL;
        return clone;
    }
    UndirectedGraphNode *clone = new UndirectedGraphNode(0), *curr;
    curr = clone;
    map <int, int> M;
    map <int, UndirectedGraphNode*> MS;
    queue<UndirectedGraphNode*> q, qs;
    q.push(node);
    qs.push(curr);

    M[node->label] = 1;
    MS[node->label] = curr;

    while(!q.empty()) {
        UndirectedGraphNode *v = q.front();
        q.pop();
        curr = qs.front();
        qs.pop();
        curr->label = (v->label);
        for(int i = 0; i < v->neighbors.size(); ++i) {

            int lab = v->neighbors[i]->label;
            if(!M[lab]) {

                UndirectedGraphNode *temp = new UndirectedGraphNode(0);
                curr->neighbors.push_back(temp);

                q.push(v->neighbors[i]);
                qs.push(curr->neighbors[i]);
                MS[v->neighbors[i]->label] = curr->neighbors[i];
                M[lab] = 1;
            }
            else {
                //cout << lab << endl;
                curr->neighbors.push_back(MS[lab]);
            }
        }

    }

    return clone;

}
};