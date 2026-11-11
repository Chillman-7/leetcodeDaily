class Solution {
public:
    typedef long long ll;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        //CASE1 -> if Individually Buying is cheaper
        if(cost1+cost2 <= costBoth){
            return (1LL * need1 * cost1 )+ (1LL * need2 * cost2);
        }
        //Case2 -> If Buying together both of them at once

        int both = min(need1,need2);
        ll total = 1LL * both*costBoth;

        need1 = need1 - both;
        need2 = need2 - both;

        if(need1>0){
            total += 1LL * need1 * min(cost1,costBoth);
        }
        else if(need2>0){
            total += 1LL * need2 * min(cost2,costBoth);
        }
        
        return total;
    }
};