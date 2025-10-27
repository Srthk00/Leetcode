class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int result=0;
        vector<int> ones;
        for(int i=0;i<bank.size();i++){
            int count=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1'){count++;}
            }
            if(count>0){ones.push_back(count);}
        }
        if(ones.size()<2){return 0;}
        for(int i=0;i<ones.size()-1;i++){result+=(ones[i]*ones[i+1]);}
        return result;
    }
};