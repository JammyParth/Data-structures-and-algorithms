class Solution {
    public int[] sortByBits(int[] arr) {
        List<int[]> res = new ArrayList<>();

        for(int val : arr){
            int bits = Integer.bitCount(val);
            res.add(new int[]{bits , val});
        }


        Collections.sort(res , (a , b) -> {
            if(a[0] != b[0]){
                return a[0] - b[0];    //sort on basis of bits
            }

            return a[1] - b[1];    //sort on basis of number.
        });

        for(int i = 0; i < arr.length; i++){
            arr[i] = res.get(i)[1];
        }

        return arr;
    }
}