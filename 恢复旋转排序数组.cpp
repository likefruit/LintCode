题目

给定一个旋转排序数组，在原地恢复其排序。

样例

什么是旋转数组？

比如，原始数组为[1,2,3,4], 则其旋转数组可以是[1,2,3,4], [2,3,4,1], [3,4,1,2], [4,1,2,3]

[4, 5, 1, 2, 3] -> [1, 2, 3, 4, 5]

class Solution {
public:


    void Reverse(vector<int> &nums,int l,int h)
    {
        int temp=0;
        while(l<h)
        {
            temp=nums[l];
            nums[l]=nums[h];
            nums[h]=temp;
            l++;
            h--;
        }

    }
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        if(nums.empty()||nums.size()==1) return;
        int i=0;

        //找到分界点
        while(i<nums.size()-1)
        {
            if(nums[i]<=nums[i+1])
                i++;
            else
                break;
        }

        //反转
        if(i<nums.size()-1)
        {
            Reverse(nums,0,i);
            Reverse(nums,i+1,nums.size()-1);
            Reverse(nums,0,nums.size()-1);
        }

    }
};


STL拓展

C++的STL提供了reverse,可以用于反转数组。

reverse(参数1，参数2);

参数1：要反转数组第一个元素的迭代器； 
参数2：要反转数组的最后一个元素的下一个位置。

上题代码可改写成

class Solution {
public:

    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        if(nums.empty()||nums.size()==1) return;
        int i=0;

        //找到分界点
        while(i<nums.size()-1)
        {
            if(nums[i]<=nums[i+1])
                i++;
            else
                break;
        }

        //反转
        if(i<nums.size()-1)
        {
            //STL::reverse
            reverse(nums.begin(),nums.begin()+i+1);
            reverse(nums.begin()+i+1,nums.end());
            reverse(nums.begin(),nums.end());
        }

    }
};
