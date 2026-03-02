class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> zeros;
        for(auto &it:grid){
            int c=0;
            bool flag=false;
            for(int i=it.size()-1;i>=0;i--){
                if(it[i]==0){c++;}
                else{
                    flag=true;
                    zeros.push_back(c);break;
                }
            }
            if(!flag){
                zeros.push_back(n-1);
            }
        }
        vector<int> temp=zeros;
        sort(temp.rbegin(),temp.rend());
        for(int i=0;i<temp.size();i++){
            if(temp[i]<n-i-1){return -1;}
        }
        int result = 0;
        for(int i=0;i<n;i++){
            int need=n-i-1;
            int j=i;
            while(j<n && zeros[j]<need){j++;}
            while(j>i){
                swap(zeros[j],zeros[j-1]);
                result++;
                j--;
            }
        }
        return result;
    }
};