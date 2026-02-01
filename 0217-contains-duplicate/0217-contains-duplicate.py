class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        student = {}

        for i in nums:
            student[i] = student.get(i , 0) + 1
        

        for value in student.values():
            if(value > 1):
                return True
            
        return False
