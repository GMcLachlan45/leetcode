class Solution {
    public boolean isPalindrome(String s) {
        s = s.replaceAll("\\W","").toLowerCase();
        s = s.replaceAll("_", "");
        int endPointer = s.length()-1;
        boolean cont = true;
        int i =0;

    if(s.length() == 0 || s.length() == 1)  
        { 
            return true;  
        }  

        while(cont == true){
            if((endPointer-i) > i){
            String start = s.substring(i, i+1);
            String end = s.substring(endPointer-i,endPointer-i+1 );
                if(start.equals(end)){
                    i+=1;
                }
                else{
                    return false;
                }
            }
            else if((endPointer-i) <= i){     
                    return true;
                }
            else{
                return false; 
            }
        }
         return false;
    }
}