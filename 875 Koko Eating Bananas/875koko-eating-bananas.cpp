class Solution {
public:
    int check(vector<int> &piles,int b){
        int count=0;
        for(int i=0;i<piles.size();i++){
            count+=piles[i]/b;
            if(piles[i]%b!=0)
                count++;
        }
        return count;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        while(low<high){
            int mid=low+(high-low)/2;
            if(check(piles,mid)<=h){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};