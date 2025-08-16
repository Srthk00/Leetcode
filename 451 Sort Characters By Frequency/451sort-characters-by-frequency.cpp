class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(256,0);
        for(char ch:s){
            freq[ch]++;
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>> pq;
        for(int i=0;i<freq.size();i++){
            if(freq[i]>0){
                pq.push({freq[i],(char)i});
            }
        }
        string result="";
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            result+=string(it.first,it.second);
        }
        return result;
    }
};