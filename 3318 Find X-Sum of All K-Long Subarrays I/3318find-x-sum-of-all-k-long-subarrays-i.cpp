class Solution {
public:

    int xsum(vector<int> &nums,int i,int j, int x){
        unordered_map<int,int> mp;
        for(int a=i;a<=j;a++){
            mp[nums[a]]++;
        }
        auto cmp=[&mp](int a,int b){
            if(mp[a]==mp[b])return a<b;
            return mp[a]<mp[b];
        };
        priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);
        for(auto &p:mp){
            pq.push(p.first);
        }
        if(mp.size()<x){return accumulate(nums.begin()+i,nums.begin()+j+1,0);}
        int sum=0;
        while(x-->0 && !pq.empty()){
            int top=pq.top();
            pq.pop();
            sum+=mp[top]*top;
        }
        return sum;
    };

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> result;
        int i=0,j=k-1;
        while(j<nums.size()){
            result.push_back(xsum(nums,i,j,x));
            i++;j++;
        }
        return result;
    }
};