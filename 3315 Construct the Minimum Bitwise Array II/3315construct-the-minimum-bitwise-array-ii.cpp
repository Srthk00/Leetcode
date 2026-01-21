class Solution {
public:
    string tobinary(int num){
        if(num==0){return "0";}
        string result="";
        while(num>0){
            result+=to_string(num%2);
            num/=2;
        }
        reverse(result.begin(),result.end());
        return result;
    }

    int todecimal(string str){
        int result=0;
        int p=0;
        int i=str.size()-1;
        while(i>=0){
            if(str[i]=='1'){
                result+=(1<<p);
            }
            i--;p++;
        }
        return result;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n,-1);
        for(int i=0;i<n;i++){
            if(nums[i]==2){continue;}
            string bin=tobinary(nums[i]);
            int j=0;
            while(j<bin.size()){
                if(bin[j]=='1'){
                    string temp=bin;
                    temp[j]='0';
                    int curr=todecimal(temp);
                    int next=curr+1;
                    if((curr|next)==nums[i]){
                        result[i]=curr;
                        break;
                    }
                }
                j++;
            }
        }
        return result;
    }
};