class MedianFinder {
public:
    vector<int> heap_min, heap_max;
    int pre = -1;
    // Adds a number into the data structure.
    void insert_max(int num) {
        int i = heap_max.size();
        heap_max.push_back(num);
        if(!i) return;
        while(true) {
            int k = (i / 2) - !(i % 2);
            if(heap_max[k] < heap_max[i]) {
                swap(heap_max[k], heap_max[i]); i = k;
            } else break;
            if(i == 0) break;
        }
    }
    void insert_min(int num) {
        int i = heap_min.size();
        heap_min.push_back(num);
        if(!i) return;
        while(true) {
            int k = (i / 2) - !(i % 2);
            if(heap_min[k] > heap_min[i]) {
                swap(heap_min[k], heap_min[i]); i = k;
            } else break;
            if(i == 0) break;
        }
    }
    void addNum(int num) {
        if(heap_min.size() + heap_max.size() < 2) {
            if(heap_min.size() + heap_max.size() == 0) {
                heap_min.push_back(num);
            }
            else {
                if(num > pre) {
                    heap_min.pop_back();
                    heap_min.push_back(num);
                    heap_max.push_back(pre);
                }
                else {
                    heap_max.push_back(num);
                }
            }
        }
        else {
            if(num < heap_max[0]) {
                insert_max(num);
            }
            else {
                insert_min(num);
            }
        }
        
        //balance
        int s = heap_max.size();
        int x = heap_min.size();
        if(abs(s-x) > 1) {
            if(heap_max.size() > heap_min.size()) {
                insert_min(heap_max[0]);
                swap(heap_max[0], heap_max[heap_max.size()-1]);
                heap_max.pop_back();
                int i = 0;
                while(true) {
                    int left = i*2 + 1, right = i*2 + 2;
                    int maxn = heap_max[i], index = -1;
                    if(left < heap_max.size() && heap_max[left] > maxn) maxn = heap_max[left], index = left;
                    if(right < heap_max.size() && heap_max[right] > maxn) maxn = heap_max[right], index = right;
                    if(maxn == heap_max[i]) break;
                    swap(heap_max[index], heap_max[i]);
                    i = index;
                }
            }
            else {
                insert_max(heap_min[0]);
                swap(heap_min[0], heap_min[heap_min.size()-1]);
                heap_min.pop_back();
                int i = 0;
                while(true) {
                    int left = i*2 + 1, right = i*2 + 2;
                    int minn = heap_min[i], index = -1;
                    if(left < heap_min.size() && heap_min[left] < minn) minn = heap_min[left], index = left;
                    if(right < heap_min.size() && heap_min[right] < minn) minn = heap_min[right], index = right;
                    if(minn == heap_min[i]) break;
                    swap(heap_min[index], heap_min[i]);
                    i = index;
                }
            }
        }
        
        pre = num;
    }

    // Returns the median of current data stream
    double findMedian() {
        if(heap_min.size() == heap_max.size()) return (double)(heap_min[0]+heap_max[0])/2.0;
        else {
            return (heap_min.size() > heap_max.size() ? heap_min[0] : heap_max[0]);
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();