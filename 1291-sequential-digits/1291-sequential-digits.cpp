class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str="123456789";
        vector<int> result;
        int len=2;
        while(len<=9){
            int i=0,j=len-1;
            while(j<9){
                int num=stoi(str.substr(i,j-i+1));
                if(num>=low && num<=high){
                    result.push_back(num);
                }
                i++;j++;
            }
            len++;
        }
        return result;
    }
};