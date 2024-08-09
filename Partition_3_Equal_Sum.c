// Time: O(n)
// Space: O(1)

bool canThreePartsEqualSum(int* arr, int arrSize) {
    int sum = 0;
    for (int i = 0; i < arrSize; i++) {
        sum += arr[i];
    }
    int partition = 0;
    int count = 0;

    if (sum % 3 == 0) {
        for (int i = 0; i < arrSize; i++) {
            partition += arr[i];
            
            if (partition == sum / 3) {
                count++;
                partition = 0;
            }
        }
    }
    return count >= 3;
}