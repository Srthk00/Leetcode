class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            int comp=n-i;
            string a=to_string(i);
            string b=to_string(comp);
            if(a.find('0')==string::npos && b.find('0')==string::npos && i+comp==n){
                return {i,comp};
            }
        }
        return {};
    }
};