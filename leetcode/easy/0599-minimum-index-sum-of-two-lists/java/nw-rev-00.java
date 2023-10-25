//8ms
//43.5MB
class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        LinkedHashMap<String, Integer> map = new LinkedHashMap<String, Integer>();
        List<String> arr = new ArrayList<String>();
        for(int i = 0; i < list1.length; i++){
            map.put(list1[i], i);
        }
        int sum = Integer.MAX_VALUE;
        for(int i = 0; i < list2.length; i++){
            Integer x = map.get(list2[i]);
            if(x != null){
                if(i + x <= sum){
                    if(i + x < sum){
                        sum = i + x;
                        arr = new ArrayList<String>();
                    }
                arr.add(list2[i]);
                }
            }
        }
        return arr.toArray(new String[arr.size()]);
    }
}
