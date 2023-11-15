// Function to calculate maximum pairs
int max_pairs(int *freq, int size) {
    int sum = 0;
    for (int i = 0; i < size - 1; i++) {
        // Add pairs from current weight
        sum += freq[i] / 2;

        // Check if there's a remaining weight and if the next weight is also odd
        int remaining = freq[i] % 2;
        if (remaining && (freq[i + 1] % 2)) {
            // If so, pair them and add pairs from next weight
            sum++;
            sum += freq[i + 1] / 2;

            // Skip next weight since it's already considered
            i++;
        }
    }
    return sum;
}


