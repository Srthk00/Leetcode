class Solution {
public:
    bool balanced(int n){
        vector<int> freq(10,0);
        string str=to_string(n);
        for(int i=0;i<str.size();i++){
            freq[str[i]-'0']++;
        }
        for(int i=0;i<10;i++){
            if(freq[i] && i!=freq[i]){return false;}
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for(int i=n+1;i<1224444;i++){
            if(balanced(i)){
                return i;
            }
        }
        return 1224444;
    }
};