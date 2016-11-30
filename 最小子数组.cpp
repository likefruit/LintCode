//我的答案
class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int nowSum=0;
        int sum=nums[0];
        int i=0;
        while(i<nums.size())
        {
            nowSum+=nums[i++];
            if(nowSum>0&&nowSum<=sum)
            {
                sum=nowSum;
                nowSum=0;
                continue;
            }
            if(nowSum<sum)
                sum=nowSum;
            if(nowSum>0)
                nowSum=0;
        }
        return sum;
    }
};

