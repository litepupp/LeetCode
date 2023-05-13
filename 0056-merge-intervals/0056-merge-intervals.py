class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        merged = []
        intervals = sorted(intervals)
        prev = intervals[0]
        
        i = 0
        while i < len(intervals):
            a = prev
            b = intervals[i]
            
            if b[1] < a[0] or b[0] > a[1]:
                merged.append(a)
                prev = b
            elif b[0] < a[0]:
                if b[1] <= a[1]:
                    prev = [b[0], a[1]]
                else:
                    prev = [b[0], b[1]]
            else:
                if b[1] > a[1]:
                    prev = [a[0], b[1]]
                    
            i += 1
        
        merged.append(prev)
        return merged
            
            
        