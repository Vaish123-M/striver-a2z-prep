/*
===============================================================================
                    MERGE OVERLAPPING INTERVALS (BRUTE FORCE)
===============================================================================

PROBLEM:
Merge all overlapping intervals.

Example:
[1,3] [2,6] [8,10] [15,18]
Answer:
[1,6] [8,10] [15,18]

-------------------------------------------------------------------------------
IDEA:

For every interval,
check all intervals after it.

If they overlap:
    merge them.

Mark merged intervals as visited.

-------------------------------------------------------------------------------
WHY BRUTE?

Simple and intuitive.
Good starting point during interviews.

-------------------------------------------------------------------------------
OVERLAP CONDITION:

next.start <= current.end

-------------------------------------------------------------------------------
TIME:
Sorting : O(N log N)
Nested loops : O(N²)

Overall : O(N²)

SPACE:
Visited array + answer = O(N)

-------------------------------------------------------------------------------
INTERVIEW FLOW:

Brute -> O(N²)
Can optimize because after sorting,
merged intervals appear together.

===============================================================================
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<bool> vis(n, false);
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++)
    {
        if(vis[i]) continue;

        int start = arr[i][0];
        int end = arr[i][1];

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
                vis[j] = true;
            }
        }

        ans.push_back({start, end});
    }

    return ans;
}