class Solution {
public:
    // if we split any number, the min prodict we can get is n-1, since (1*(n-1))=n-1
    // so at each operation, we can get n-1 of current number and reduce it, this goes from
    // n-1 till 1, so the answer will be sum of natural number till n-1
    int minCost(int n) {
        n--;
        return n*(n+1)/2;
    }
};