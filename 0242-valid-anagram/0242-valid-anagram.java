class Solution {
    public boolean isAnagram(String s, String t) {

        if(s.length() != t.length()){
            return false;
        }

        int[] arr = new int[26];

        int n = s.length();
        for(int i = 0; i < n; i++){
            arr[s.charAt(i) - 'a'] += 1;
        }

        int m = t.length();

        for(int i = 0; i<m; i++){

            if(arr[t.charAt(i) - 'a'] == 0){
                return false;
            }

            arr[t.charAt(i) - 'a'] -= 1;

        }

        return true;
    }
}