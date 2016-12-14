class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        auto i=nums.begin();
        int size=nums.size();
        while(i!=nums.end()-1)
        {
            if(*i!=*(i+1))
                i++;
            else
            {
                i=nums.erase(i);
                size--;
            }       
        }
        return size;
    }
};
