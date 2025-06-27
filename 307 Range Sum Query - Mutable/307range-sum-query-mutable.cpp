class NumArray {
public:
    vector<int> nums;
    vector<int> segtree;
    int L,R;
    NumArray(vector<int>& nums) {
        this->nums=nums;
        segtree.resize(4*nums.size());
        L=0;R=nums.size()-1;
        buildtree(0,L,R);
    }
    
    void buildtree(int i,int L,int R){
        if(L==R){
            segtree[i]=nums[L];
        }
        else{
            int mid=L+(R-L)/2;
            buildtree(2*i+1,L,mid);
            buildtree(2*i+2,mid+1,R);
            segtree[i]=segtree[2*i+1]+segtree[2*i+2];
        }
    }

    void update_sum(int i,int L,int R,int idx,int val){
        if(L==R){
            segtree[i]+=val;
            nums[idx]+=val;
        }
        else{
            int mid=(L+R)/2;
            if(idx<=mid){
                update_sum(2*i+1,L,mid,idx,val);
            }
            else{
                update_sum(2*i+2,mid+1,R,idx,val);
            }
            segtree[i]=segtree[2*i+1]+segtree[2*i+2];
        }
    }

    void update(int index, int val) {
        int toset=val-nums[index];
        update_sum(0,L,R,index,toset);
    }
    
    int find_sum(int i,int a,int b,int L,int R){
        if(a>R || b<L){
            return 0;
        }
        if(a<=L && b>=R){
            return segtree[i];
        }
        int mid=(L+R)/2;
        int fromleft=find_sum(2*i+1,a,b,L,mid);
        int fromright=find_sum(2*i+2,a,b,mid+1,R);
        return fromleft+fromright;
    }

    int sumRange(int left, int right) {
        return find_sum(0,left,right,L,R);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */