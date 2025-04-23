class Solution {
public:
    int sumofdigit(int n){
        int sum=0;
        while(n!=0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int,int> map;
        int maximum=0;
        for(int i=1;i<=n;i++){
            int sum=sumofdigit(i);
            map[sum]++;
            maximum=max(maximum,map[sum]);
        }
        int count=0;
        for(auto &i:map){
            if(i.second==maximum){
                count++;
            }
        }
        return count;
    }
};