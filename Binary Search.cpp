class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low+1<high) {
            int mid = low+(high-low)/2;
            if(nums[mid]<target) low=mid;
            else high=mid;
        }
        return (nums[low]==target)?low:(nums[high]==target)?high:-1;
    }
};
