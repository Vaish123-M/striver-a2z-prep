/*
===============================================================================
                  MERGE OVERLAPPING INTERVALS (OPTIMAL)
===============================================================================

PATTERN:
Sorting + Greedy

-------------------------------------------------------------------------------
CORE OBSERVATION:

After sorting,
if current interval overlaps,
it can only overlap with the LAST merged interval.

No need to check every previous interval.

-------------------------------------------------------------------------------
OVERLAP CONDITION:

current.start <= merged.end

If overlap:
    merged.end = max(merged.end, current.end)

Else:
    push current interval.

-------------------------------------------------------------------------------
INTUITION:

Sorted:
[1,3] [2,6] [8,10] [15,18]

Take [1,3]

[2,6]
2 <= 3
Merge -> [1,6]

[8,10]
8 > 6
Store previous and start new.

-------------------------------------------------------------------------------
ALGORITHM:

1. Sort intervals.
2. Traverse once.
3. Merge with last interval if possible.

-------------------------------------------------------------------------------
TIME:

Sorting : O(N log N)
Traversal : O(N)

Overall : O(N log N)

SPACE:

Answer vector : O(N)

-------------------------------------------------------------------------------
INTERVIEW ONE LINER:

"Sort by starting time and greedily merge overlapping intervals."

-------------------------------------------------------------------------------
WHEN TO THINK OF THIS PATTERN?

Keywords:
✓ Merge Intervals
✓ Meeting Rooms
✓ Insert Interval
✓ Calendar Booking
✓ Employee Free Time

First thought:
SORT + GREEDY

===============================================================================
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for(auto interval : arr)
    {
        if(ans.empty() || interval[0] > ans.back()[1])
        {
            ans.push_back(interval);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], interval[1]);
        }
    }

    return ans;
}