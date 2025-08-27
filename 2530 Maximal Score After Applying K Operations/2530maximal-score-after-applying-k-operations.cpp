class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score=0;
        priority_queue<int,vector<int>> pq;
        for(int i:nums){
            pq.push(i);
        }
        while(k-->0){
            double attop=pq.top();
            pq.pop();
            score+=attop;
            pq.push(ceil(attop/3.00));
        }
        return score;
    }
};