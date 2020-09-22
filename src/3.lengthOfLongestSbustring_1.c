#include <stdio.h>


#define N 100


int lengthOfLongestSubstring(char *s);


int main(int argc, char *argv[]) {
    char str[N];
    scanf("%s", str);


    printf(" 长度 : %d\n",lengthOfLongestSubstring(str));

    return 0;
}








// 无重复字符的最长子串
int lengthOfLongestSubstring(char *s) {
    char *ptr = s;
    int flag = 0; 

    int numOfChar = 0; //记录长度
    int tmpNumOfChar = 0;


    //遍历字符串
    while(ptr[flag] != '\0') {

        if(ptr[flag] != ptr[flag + 1]) {
            numOfChar++;

            //如果第二次长度大于第一次
            if(numOfChar > tmpNumOfChar){
                tmpNumOfChar=numOfChar;
            }
            
        // 如果出现相同的字符
        } else {
            numOfChar = 0;
        }


        //遍历
        flag++;
    }


    //返回最长的长度
    return tmpNumOfChar;
}
