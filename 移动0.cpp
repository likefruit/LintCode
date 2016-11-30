class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        // Write your code here
        int i=0;    //nums[i]==0
        int temp=0;    //nums[temp]!=0
        while(i<nums.size())
        {
            if(nums[i]!=0)
                i++;
            else
            {
                temp=i;
                while(temp<nums.size()&&nums[temp]==0)
                    temp++;
                if(temp<nums.size()&&nums[temp]!=0)
                    swap(nums[i],nums[temp]);
                i++;
            }
        }
        
        
    }
};
