/*
=========================================================
MERGE OVERLAPPING INTERVALS - BRUTE FORCE
=========================================================

Idea:
1. Sort intervals by start time.
2. For every interval:
   - Merge all overlapping intervals ahead.
3. Mark merged intervals as visited.

Time  : O(N²)
Space : O(N)
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Interval structure
struct Interval
{
    int start;
    int end;
};

// Sort by starting time
bool compare(Interval a, Interval b)
{
    return a.start < b.start;
}

int main()
{
    int n;

    cout << "Enter number of intervals: ";
    cin >> n;

    Interval arr[100];
    bool visited[100] = {false};

    cout << "Enter intervals (start end):\n";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].start >> arr[i].end;
    }

    // Step 1: Sort intervals
    sort(arr, arr + n, compare);

    cout << "\nMerged Intervals:\n";

    // Step 2: Pick each interval
    for(int i = 0; i < n; i++)
    {
        // Skip already merged intervals
        if(visited[i])
            continue;

        int start = arr[i].start;
        int end = arr[i].end;

        // Step 3: Check all next intervals
        for(int j = i + 1; j < n; j++)
        {
            // Overlap condition
            if(arr[j].start <= end)
            {
                // Extend end if needed
                end = max(end, arr[j].end);

                // Mark as merged
                visited[j] = true;
            }
        }

        cout << start << " " << end << endl;
    }

    return 0;
}