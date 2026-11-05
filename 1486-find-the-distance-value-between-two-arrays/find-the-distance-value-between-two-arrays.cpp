class Solution {
public:
     bool isValid(vector<int>& arr2,int target,int d){
        int low=0;
        int high = arr2.size()-1;
        
        while(low<=high){
            int mid = (low+high)/2;

            if(abs(arr2[mid]-target) <= d){
                return false;
            }
            else if(arr2[mid]<target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return true;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count=0;
        sort(arr2.begin(),arr2.end());

        for(auto val:arr1){
            if(isValid(arr2,val,d)){
                count++;
            }
        }
        return count;

    }
};