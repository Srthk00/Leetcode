class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int> map;
        for(int i:digits){
            map[i]++;
        }
        vector<int> result;
        for(int i=100;i<1000;i+=2){
            int a=i%10;
            int b=(i/10)%10;
            int c=(i/100)%10;
            vector<int> freq(10,0);
            freq[a]++;
            freq[b]++;
            freq[c]++;
            if(map[a]>=freq[a] && map[b]>=freq[b] && map[c]>=freq[c]){
                result.push_back(i);
            }
        }
        return result;
    }
};