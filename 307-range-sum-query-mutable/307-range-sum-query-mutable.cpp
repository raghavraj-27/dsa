class SGTree {
    public:vector<int> seg;
public:
    // SGTree() {}
    SGTree(int len) {
        seg.resize(len);
    }
    
    void build(int ind, int low, int high, vector<int>& arr) {
        if(low == high) {
            seg[ind] = arr[low];
            return;
        }
        
        int mid = (low + high) >> 1;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
    
    void update(int ind, int low, int high, int i, int val, vector<int>& arr) {
        if(low == high) {
            seg[ind] = val;
            arr[i] = val;
            return;
        }
        
        int mid = (low + high) >> 1;
        if(i <= mid) 
            update(2*ind+1, low, mid, i, val, arr);
        else
            update(2*ind+2, mid+1, high, i, val, arr);
        
        seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
    }
    
    int query(int ind, int low, int high, int l, int r, vector<int>& arr) {
        // no overlap, l..r..low..high, low..high..l..r
        if(r<low or high<l) return 0;
        
        // complete overlap, l..low..high..r
        if(l<=low and high<=r) return seg[ind];
        
        // partial overlap
        int mid = (low + high) >> 1;
        int left = query(2*ind+1, low, mid, l, r, arr);
        int right = query(2*ind+2, mid+1, high, l, r, arr);
        return left + right;
    }
};

class NumArray {
public:
    SGTree *sg = new SGTree(120001);
    int low, high;
    vector<int> arr;
    NumArray(vector<int>& nums) {
        // sg = new SGTree(4*nums.size()+1);
        low = 0;
        high = nums.size()-1;
        arr = nums;
        sg->build(0, low, high, arr);
        cout<<sg->seg[0]<<endl;
    }
    
    void update(int index, int val) {
        sg->update(0, low, high, index, val, arr);
    }
    
    int sumRange(int left, int right) {
        return sg->query(0, low, high, left, right, arr);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */