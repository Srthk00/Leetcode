class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string str=to_string(n);
        unordered_map<int,int> map;
        for(int i=0;i<str.size();i++){
            map[str[i]-'0']++;
        }
        int minfreq=INT_MAX;
        int minnum=10;
        for(auto &[num,f]:map){
            if(f<minfreq){
                minfreq=f;
                minnum=num;
            }
            else if(f==minfreq){
                minnum=min(minnum,num);
            }
        }
        return minnum;
    }
};