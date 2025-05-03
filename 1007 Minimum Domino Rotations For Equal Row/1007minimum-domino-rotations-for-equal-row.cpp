class Solution {
public:
    int check(int x,vector<int> &nums1,vector<int> &nums2){
        int result=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]==x){
                continue;
            }
            else if(nums2[i]==x){
                result++;
            }
            else{
                return INT_MAX;
            }
        }
        return result;
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int top1=check(tops[0],tops,bottoms);
        int bottom1=check(bottoms[0],bottoms,tops);
        int top2=check(bottoms[0],tops,bottoms);
        int bottom2=check(tops[0],bottoms,tops);
        int result=min({top1,top2,bottom1,bottom2});
        return (result==INT_MAX)?-1:result;
    }
};