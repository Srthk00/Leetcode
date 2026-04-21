class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto cmp=[&x](int a,int b){
            int m=abs(a-x);
            int n=abs(b-x);
            if(m==n)
                return a<b;
            return m<n;
        };

        priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);
        for(int i:arr){
            pq.push(i);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        sort(result.begin(),result.end());
        return result;
    }
};