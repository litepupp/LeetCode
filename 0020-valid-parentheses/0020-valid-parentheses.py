class Solution:
    def is_matching_brackets(start: str, end: str) -> bool:
        if start == "(" and end == ")": return True
        elif start == "{" and end == "}": return True
        elif start == "[" and end == "]": return True
        else: return False
    
    def isValid(self, s: str) -> bool:
        stack: list = []
        
        for char in s:
            if stack:
                if Solution.is_matching_brackets(stack[-1], char):
                    stack.pop()
                    continue
            stack.append(char)
        
        if len(stack) > 0:
            return False
        else:
            return True
        