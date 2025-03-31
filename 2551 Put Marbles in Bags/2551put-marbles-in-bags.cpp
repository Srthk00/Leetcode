class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> result;
        for(int i=0;i<weights.size()-1;i++){
            result.push_back(weights[i]+weights[i+1]);
        }
        sort(result.begin(),result.end());
        long long min=0;
        long long max=0;
        for(int i=0;i<k-1;i++){
            min+=result[i];
            max+=result[result.size()-1-i];
        }
        return max-min;
    }
};