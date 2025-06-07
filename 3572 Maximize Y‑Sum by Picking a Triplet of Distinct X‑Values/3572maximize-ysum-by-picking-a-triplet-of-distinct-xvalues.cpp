class Solution {
public:    
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        vector<pair<int,int>> group;
        for(int i=0;i<x.size();i++){
            group.push_back({x[i],y[i]});
        }
        sort(group.begin(),group.end(),[](pair<int,int> &a,pair<int,int> &b){
            return a.second>b.second;
        });
        int sum=0;
        int count=3;
        int last1=group[0].first;
        int last2=group[0].first;
        count--;
        sum+=group[0].second;
        int i=1;
        while(i<group.size() && count>0){
            if(group[i].first!=last1 && group[i].first!=last2){
                sum+=group[i].second;
                last2=group[i].first;
                count--;
            }
            i++;
        }
        if(count>0){
            return -1;
        }
        return sum;
    }
};