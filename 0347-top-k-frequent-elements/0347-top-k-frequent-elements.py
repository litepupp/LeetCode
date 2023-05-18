class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        unique_counts = {}
        
        for num in nums:
            if str(num) in unique_counts:
                unique_counts[str(num)] += 1
            else:
                unique_counts[str(num)] = 1
        
        sorted_counts = sorted(unique_counts.items(), key=lambda x: x[1], reverse=True)
        most_frequent = []
        
        for i in range(k):
            most_frequent.append(int(sorted_counts[i][0]))
            
        return most_frequent
