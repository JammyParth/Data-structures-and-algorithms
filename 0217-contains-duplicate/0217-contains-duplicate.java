class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> hashmap = new HashSet<>();

        for(int val : nums){
            if(hashmap.contains(val)){
                return true;
            }

            hashmap.add(val);
        }

    return false;
    }
}