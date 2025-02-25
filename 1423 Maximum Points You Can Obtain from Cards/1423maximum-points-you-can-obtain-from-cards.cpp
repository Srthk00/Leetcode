class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lsum=0,rsum=0;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        int m=lsum;
        for(int i=0;i<k;i++){
            lsum-=cardPoints[k-1-i];
            rsum+=cardPoints[n-1-i];
            m=max(m,lsum+rsum);
        }
        return m;
    }
};