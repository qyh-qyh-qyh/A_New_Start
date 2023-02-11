//力扣777题
//关键问题一。找等价：本题的是否能问题只需要相对位置（先）和下标满足大小关系 （后） 
bool canTransform(char * start, char * end) {
    int n = strlen(start);
    int i = 0, j = 0;
    while (i < n || j < n) {
        while (i < n && start[i] == 'X') i++;
        while (j < n && end[j] == 'X') j++;//问题二。如何找出字母R和L的下标 
        if (i == n || j == n) return i == j;//到末尾了，如果都到末尾说明元素个数一样可以换到最后
        if (start[i] != end[j]) return false;//问题三。如何先判断相对位置，看两个的是不是同时相同 
        if (start[i] == 'L' && i < j) return false;//问题四，判断是否满足能移动的位置关系 
        if (start[i] == 'R' && i > j) return false;
        i++; j++;
    }
    return i == j;
}


//作者：xun-ge-v
//链接：https://leetcode.cn/problems/swap-adjacent-in-lr-string/solution/-by-xun-ge-v-w3b9/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
