class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> map={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int result=0;
        int n=s.size();
        int i=0;
        while(i<n-1){
            if(map[s[i]]>=map[s[i+1]]){
                result+=map[s[i]];
                i++;
            }
            else{
                result+=map[s[i+1]]-map[s[i]];
                i+=2;
            }
        }
        if(i<n){
            result+=map[s[i]];
        }
        return result;
    }
};