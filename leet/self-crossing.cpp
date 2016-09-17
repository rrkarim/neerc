class Solution {
public:
    struct p {
        int x1, y1, x2, y2;
        p() {}
        p(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {} 
    };
    
    bool inters(const p&a, const p&b) {
        if(a.x1 == a.x2) {
            if(max(a.y1, a.y2) >= b.y1 && min(a.y1, a.y2) <= b.y1 && max(b.x1, b.x2) >= a.x1 && min(b.x1, b.x2) <= a.x1) {
                return true;
            }
            return false;
        }
        else {
            if(max(b.y1, b.y2) >= a.y1 && min(b.y1, b.y2) <= a.y1 && max(a.x1, a.x2) >= b.x1 && min(a.x1, a.x2) <= b.x1) {
                return true;
            }
            return false;
        }
    }
    
    bool isSelfCrossing(vector<int>& x) {
        if(x.size() < 4) return false;
        for(int i=3; i < x.size(); i++){
            if(x[i-3] >= x[i-1] && x[i-2]<=x[i]){
                return true;
            }
     
            if(i>=4 && x[i-4]+x[i]>=x[i-2] && x[i-3]==x[i-1])   {
                return true;
            }
     
            if(i>=5 && x[i-5]<=x[i-3] && x[i]<=x[i-2]&& x[i-1]<=x[i-3] && x[i-4]<=x[i-2] && x[i-1]>=x[i-3]-x[i-5] && x[i]>=x[i-2]-x[i-4]){
                return true;
            }
        }
     
        return false;
    }
};