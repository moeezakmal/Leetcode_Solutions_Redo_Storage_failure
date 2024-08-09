int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}


int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) {
        return 0;
    }

    int* start = (int*)malloc(intervalsSize * sizeof(int));
    int* end = (int*)malloc(intervalsSize * sizeof(int));

    for (int i = 0; i < intervalsSize; i++) {
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }

    qsort(start, intervalsSize, sizeof(int), compare);
    qsort(end, intervalsSize, sizeof(int), compare);

    int usedRooms = 0, count = 0;
    int s_idx = 0, e_idx = 0;

    while (s_idx < intervalsSize)
    {
        if (start[s_idx] < end[e_idx])
        {
            count++;
            s_idx++;
        }

        else
        {
            count--;
            e_idx++;
        }
        usedRooms = (usedRooms < count) ? count : usedRooms; 
    }


    free(start);
    free(end);

    return usedRooms;
}