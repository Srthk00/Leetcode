class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> map;
        for(int i:arr){
            map[i]++;
        }
        sort(arr.begin(),arr.end(),[&map](int a,int b){
            if(map[a]==map[b]){return a<b;}
            return map[a]<map[b];
        });
        unordered_set<int> st(arr.begin()+k,arr.end());
        return st.size();
    }
};