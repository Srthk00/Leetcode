class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> result;
        string num=to_string(n);
        int s=num.size();
        for(int i=0;i<num.size();i++){
            int digit=(num[i]-'0')*(int)pow(10,(s--)-1);
            if(digit!=0){
                result.push_back(digit);
            }
        }
        return result;
    }
};