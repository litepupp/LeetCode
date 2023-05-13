class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        merged = []
        intervals = sorted(intervals)
        prev = intervals[0]
        
        i = 1
        while i < len(intervals):
            a = prev
            b = intervals[i]
            
            if b[1] < a[0] or b[0] > a[1]:
                merged.append(a)
                prev = b
            else:
                if b[1] > a[1]:
                    prev = [a[0], b[1]]
                    
            i += 1
        
        merged.append(prev)
        return merged
            
            
        