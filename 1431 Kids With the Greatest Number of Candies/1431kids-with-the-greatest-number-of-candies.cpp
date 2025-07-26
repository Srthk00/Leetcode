class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m=*max_element(candies.begin(),candies.end());
        int n=candies.size();
        vector<bool> result;
        for(int i:candies){
            if(i+extraCandies>=m){
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        }
        return result;
    }
};