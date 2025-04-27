 
#include <stdio.h> 
#include <stdlib.h> 
struct Interval { 
    int start; 
    int end; 
}; 
int compare(const void *a, const void *b) { 
    struct Interval *intervalA = (struct Interval *)a; 
    struct Interval *intervalB = (struct Interval *)b; 
    return intervalA->end - intervalB->end; 
} 
 
void intervalScheduling(struct Interval intervals[], int n) { 
    qsort(intervals, n, sizeof(struct Interval), compare); 
    int count = 0; 
    int lastSelectedIndex = -1; 
    printf("Selected intervals:\n"); 
    for (int i = 0; i < n; i++) {   
        if (lastSelectedIndex == -1 || intervals[i].start >= intervals[lastSelectedIndex].end) { 
            printf("Interval %d: [%d, %d]\n", count + 1, intervals[i].start, intervals[i].end); 
            lastSelectedIndex = i; 
            count++; 
        } 
    } 
    printf("Total number of intervals selected: %d\n", count); 
} 
 
int main() { 
    int n; 
    printf("Enter the number of intervals: "); 
    scanf("%d", &n); 
    struct Interval intervals[n]; 
    printf("Enter the intervals (start time and end time) for each interval:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("Interval %d - Start: ", i + 1); 
        scanf("%d", &intervals[i].start); 
        printf("Interval %d - End: ", i + 1); 
        scanf("%d", &intervals[i].end); 
    } 
    intervalScheduling(intervals, n); 
    return 0; 
} 
 