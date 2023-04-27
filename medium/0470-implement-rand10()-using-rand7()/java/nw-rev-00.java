//7ms
//48MB
class Solution extends SolBase {
    public int rand10() {
        int rand = 40;
        while(rand >= 40){
            rand = (rand7() - 1) * 7 + (rand7() - 1);
        }
        return (rand % 10) + 1;
    }
}
