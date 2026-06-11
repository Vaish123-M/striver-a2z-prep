/*
===============================================================================
                  MERGE OVERLAPPING INTERVALS (OPTIMAL)
===============================================================================

PATTERN:
Sorting + Greedy

IDEA:

1. Sort intervals according to start time.
2. Take first interval.
3. If current interval overlaps with last merged interval:
      Merge them.
4. Otherwise:
      Add new interval.

OVERLAP CONDITION:

current_start <= last_merged_end

TIME:
O(N log N)

SPACE:
O(N)

INTERVIEW LINE:

"Sort intervals and merge with the last interval whenever overlap occurs."

===============================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "Enter intervals:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    // Step 1: Sort intervals according to start time
    sort(intervals.begin(), intervals.end());

    // Stores final merged intervals
    vector<vector<int>> merged;

    for(int i = 0; i < n; i++)
    {
        // If merged is empty OR no overlap
        if(merged.empty() || intervals[i][0] > merged.back()[1])
        {
            merged.push_back(intervals[i]);
        }
        else
        {
            // Overlap found
            // Update ending point
            merged.back()[1] =
            max(merged.back()[1], intervals[i][1]);
        }
    }

    cout << "\nMerged Intervals:\n";

    for(int i = 0; i < merged.size(); i++)
    {
        cout << merged[i][0]
             << " "
             << merged[i][1]
             << endl;
    }

    return 0;
}