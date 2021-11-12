// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

/*
There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points 
where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. 
You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. 
A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. 
There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
*/


class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2) { 
        return v1[1] < v2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 0) return 0;
        
        // sort in ascending order of end x-coordinate
        sort(points.begin(), points.end(), compare);
        
        int end = points[0][1];
        // count = max no. of non overlaping intervals
        int count = 1;
        
        for (int i = 1; i < n; i++) {
            // points[i].start >= end
            if (points[i][0] > end) {
                // end = points[i].end
                end = points[i][1];
                count++;
            }
        }
        return count;
    }
};
