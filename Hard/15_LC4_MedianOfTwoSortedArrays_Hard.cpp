
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always perform binary search on the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        int half = (m + n + 1) / 2;

        while (low <= high) {

            int i = low + (high - low) / 2;
            int j = half - i;

            int leftA = (i == 0) ? INT_MIN : nums1[i - 1];
            int rightA = (i == m) ? INT_MAX : nums1[i];

            int leftB = (j == 0) ? INT_MIN : nums2[j - 1];
            int rightB = (j == n) ? INT_MAX : nums2[j];

            if (leftA <= rightB && leftB <= rightA) {

                if ((m + n) % 2 == 1) {
                    return max(leftA, leftB);
                }

                return (double)(
                    max(leftA, leftB) + min(rightA, rightB)
                ) / 2.0;

            } else if (leftA > rightB) {

                high = i-1;

            } else {

                low = i+1;
            }
        }

        return 0.0;
    }
};
