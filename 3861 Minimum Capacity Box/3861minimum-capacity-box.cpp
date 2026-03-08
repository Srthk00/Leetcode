class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int result=0;
        int mincap=1e9,idx=-1;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]==itemSize){return i;}
            else if(capacity[i]>itemSize){
                if(mincap>capacity[i]){
                    result=capacity[i];
                    mincap=capacity[i];
                    idx=i;
                }
            }
        }
        return mincap==1e9?-1:idx;
    }
};