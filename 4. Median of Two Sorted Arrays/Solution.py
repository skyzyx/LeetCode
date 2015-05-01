class Solution:
    # @param {integer[]} nums1
    # @param {integer[]} nums2
    # @return {float}
    def findMedianSortedArrays(self, nums1, nums2):
        a = len(nums1)
        b = len(nums2)
        if (a + b) % 2 == 0:
            return (self.search(nums1, nums2, (a+b)/2) + self.search(nums1, nums2, (a+b)/2 + 1)) / 2.0
        else:
            return self.search(nums1, nums2, (a+b)/2 + 1)
            
    def search(self, nums1, nums2, k):
        if len(nums1) > len(nums2):
            return self.search(nums2, nums1, k)
        else:    
            if len(nums1) == 0:
                return nums2[k-1]
                
            if k == 1:
                return min(nums1[0], nums2[0])
            
            pa = min(k/2, len(nums1))
            pb = k - pa
        
            if nums1[pa-1] <= nums2[pb-1]:
                return self.search(nums1[pa::], nums2, k-pa)
            else:
                return self.search(nums1, nums2[pb::], k-pb)