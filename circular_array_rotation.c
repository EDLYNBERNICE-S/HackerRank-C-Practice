/*
Problem: Circular Array Rotation

Given an array, rotate it to the right k times and answer queries
about which element appears at specific indices after rotation.
Time Complexity: O(q)
Space Complexity: O(q)
*/

int* circularArrayRotation(int a_count, int* a, int k,
                           int queries_count, int* queries,
                           int* result_count)
{
    // The result array size equals the number of queries
    *result_count = queries_count;

    // Allocate memory for result
    int* result = (int*)malloc(sizeof(int) * queries_count);

    // Effective rotations (avoids unnecessary full cycles)
    int shift = k % a_count;

    for (int i = 0; i < queries_count; i++)
    {
        int queryIndex = queries[i];

        // Calculate original index before rotation
        int originalIndex = (queryIndex - shift + a_count) % a_count;

        // Store answer
        result[i] = a[originalIndex];
    }

    return result;
}
