//����777��
//�ؼ�����һ���ҵȼۣ�������Ƿ�������ֻ��Ҫ���λ�ã��ȣ����±������С��ϵ ���� 
bool canTransform(char * start, char * end) {
    int n = strlen(start);
    int i = 0, j = 0;
    while (i < n || j < n) {
        while (i < n && start[i] == 'X') i++;
        while (j < n && end[j] == 'X') j++;//�����������ҳ���ĸR��L���±� 
        if (i == n || j == n) return i == j;//��ĩβ�ˣ��������ĩβ˵��Ԫ�ظ���һ�����Ի������
        if (start[i] != end[j]) return false;//��������������ж����λ�ã����������ǲ���ͬʱ��ͬ 
        if (start[i] == 'L' && i < j) return false;//�����ģ��ж��Ƿ��������ƶ���λ�ù�ϵ 
        if (start[i] == 'R' && i > j) return false;
        i++; j++;
    }
    return i == j;
}


//���ߣ�xun-ge-v
//���ӣ�https://leetcode.cn/problems/swap-adjacent-in-lr-string/solution/-by-xun-ge-v-w3b9/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
