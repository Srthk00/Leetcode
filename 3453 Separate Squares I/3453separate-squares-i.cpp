class Solution {
public:
    int check(vector<vector<int>> &nums,double mid){
        double top=0.00,bottom=0.00;
        for(int i=0;i<nums.size();i++){
            if(nums[i][1]>=mid){
                top+=((double)nums[i][2]*(double)nums[i][2]);
            }
            else if((nums[i][1]+nums[i][2])<=mid){
                bottom+=((double)nums[i][2]*(double)nums[i][2]);
            }
            else{
                double inbottom=double(mid-nums[i][1]);
                double intop=double(nums[i][2]-inbottom);
                top+=(intop*intop);bottom+=(inbottom*inbottom);
            }
        }
        return fabs(top-bottom)<1e-9?0:(top<bottom?1:2);
    }

    double separateSquares(vector<vector<int>>& nums) {
        double low=nums[0][1],high=nums[0][1]+nums[0][2];
        for(int i=0;i<nums.size();i++){low=min(low,((double)nums[i][1]));high=max(high,((double)nums[i][1]+(double)nums[i][2]));}
        while(fabs(high-low)>1e-6){
            double mid=low+(high-low)/2.00;
            // 0=equal(move towards bottom), 1=top is smaller(move towards bottom), 2=bottom is smaller(move towards top)
            int flag=check(nums,mid);
            if(!flag || flag==1){high=mid;}
            else{low=mid;}
        }
        return (low+high)/2.00;
    }
};