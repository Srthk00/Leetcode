class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int result=0;
        for(int i=0;i<colors.size();i++){
            int j=i,m=0,sum=0;
            while(j<colors.size() && colors[j]==colors[i]){
                sum+=neededTime[j];
                m=max(m,neededTime[j]);j++;
            }
            i=j-1;
            result+=(sum-m);
        }
        return result;
    }
};