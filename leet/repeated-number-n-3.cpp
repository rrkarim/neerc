int Solution::repeatedNumber(const vector<int> &A) {
    vector <pair<int,int>> vi;
    for(int i = 0; i < A.size(); ++i) {
        int f = 0;
        for(int j = 0; j < vi.size(); ++j) {
            if(A[i] == vi[j].first) {
                vi[j].second += 1;
                f = 1;
                break;
            }
        }
        if(f == 1) continue;
        if(vi.size() < 2) {
            vi.push_back({A[i], 1});
        }
        else {
            for(int j = 0; j < vi.size(); ++j) {
                vi[j].second -= 1;
            }
            for(int j = 0; j < vi.size(); ++j) {
                if(vi[j].second == 0)
                    vi.erase(vi.begin()+j);
            }
        }
    }
    
    for(int i = 0; i < vi.size(); ++i) {
        int x = 0;
        for(int j = 0; j < A.size(); ++j) {
            if(A[j] == vi[i].first) x += 1;
        }
        if(x > A.size() / 3) return vi[i].first;
    }
    return -1;
}
