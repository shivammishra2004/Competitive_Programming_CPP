class SGTree{
    vector<int> seg;
    SGTree(int n){
        seg.resize(4*n+1);
    }
    void build(int idx ,int low,int high,vector<int>& arr){
        if(low == high){
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid,high,arr);
        seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
    }

    int query(int idx,int low,int high,int l,int r,vector<int>& arr){
        if(l <= low && high <= r) return seg[idx];
        else if(high < l || r < low) return INT_MAX;
        int mid = (low + high)/2;
        int left = query(2*idx+1,low,mid+1,l,r,arr);
        int right = query(2*idx+2,mid+1,high,l,r,arr);
        return min(left,right);
    }

    int update(int idx,int low,int high,int i, int val){
        if(low == high){
            seg[idx] = val;
            return;
        }
        int mid = (low + high)/2;
        if(i <= mid) update(2*idx+1,low,high,i,val);
        else update(2*idx+2,low,high,i,val);
        seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
    }
};
