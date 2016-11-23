//我的答案
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        //Interval test(0,0);
         sort(intervals.begin(), intervals.end(),
        [](const Interval& a, const Interval& b) {
             return a.start < b.start;               
        });
        if(intervals.empty())
            return intervals;
        vector<Interval> res;
        //res.emplace_back(test);
        res.emplace_back(intervals[0]);
        for(int i=1;i<intervals.size();++i)
        {
            if(intervals[i].start>(*(res.end()-1)).end)
                res.emplace_back(intervals[i]);
            else if(intervals[i].start<=(*(res.end()-1)).end)
                (*(res.end()-1)).end=max(intervals[i].end,(*(res.end()-1)).end);
        }
        return res;
        
    }
};


// Time:  O(nlogn)
// Space: O(1)

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty()) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(),
        [](const Interval& a, const Interval& b) {
             return a.start < b.start;               
        });

        vector<Interval> result = {intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            Interval& prev = result.back();
            if (intervals[i].start <= prev.end) { 
                prev.end = max(prev.end, intervals[i].end);
            } else {
                result.emplace_back(intervals[i]);
            }
        }

        return result;
    }
};
