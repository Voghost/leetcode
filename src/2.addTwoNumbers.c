#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


// 数字某一位的节点
struct ListNode {
    int val;
    struct ListNode *next;
};



//将数字转化为链表,并返回一个链表地址
struct ListNode * numToList(int num) {
    int tmp = num;


    struct ListNode *list = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *tmpList = list;
    list->val = tmp % 10;
    list->next = NULL;
    tmp = tmp / 10;

    while(tmp != 0) {
        // 申请一个节点
        tmpList->next = (struct ListNode *)malloc(sizeof(struct ListNode));


        //节点赋初值
        tmpList->next->val = tmp % 10;
        tmpList->next->next = NULL;


        //转到下一个节点
        tmpList = tmpList->next;
        tmp = tmp / 10;
    }
    return list;
}



//打印节点
int printList(struct ListNode *list) {
    while(list != NULL) {
        printf("%4d", list->val);
        list = list->next;
    }
    printf("\n");
    return 1;
}



//两数相加
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *tmp_1 = l1;
    struct ListNode *tmp_2 = l2;

    int tmpValue;
    short isCarry = 0; //是否进位

    while((tmp_1 != NULL) && (tmp_2 != NULL)) {

        tmpValue = tmp_1->val + tmp_2->val + isCarry;

        if(tmpValue >= 10) {
            tmpValue = tmpValue - 10;
            tmp_1->val = tmpValue;
            tmp_2->val = tmpValue;
            isCarry = 1;
        } else {
            tmp_1->val = tmpValue;
            tmp_2->val = tmpValue;
            isCarry = 0;
        }


        tmp_1 = tmp_1->next;
        tmp_2 = tmp_2->next;
    }

    if(tmp_1 == NULL && tmp_2 != NULL) {
        tmpValue = tmp_2->val + isCarry;

        while(1) {
            tmpValue = tmp_2->val + isCarry;
            if(tmpValue >= 10) {
                tmpValue = tmpValue - 10;
                tmp_2->val = tmpValue;
                isCarry = 1;
            } else {
                tmp_2->val = tmpValue;
                isCarry = 0;
            }

            if(tmp_2->next == NULL) {
                if(isCarry == 1) {
                    tmp_2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
                    tmp_2->next->next = NULL;
                    tmp_2->next->val = 1;
                }
                break;
            }

            tmp_2 = tmp_2->next;
        }
        return l2;
    }


    else if(tmp_2 == NULL && tmp_1 != NULL) {
        tmpValue = tmp_1->val + isCarry;

        while(1) {
            tmpValue = tmp_1->val + isCarry;
            if(tmpValue >= 10) {
                tmpValue = tmpValue - 10;
                tmp_1->val = tmpValue;
                isCarry = 1;
            } else {
                tmp_1->val = tmpValue;
                isCarry = 0;
            }

            if(tmp_1->next == NULL) {
                if(isCarry == 1) {
                    tmp_1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
                    tmp_1->next->next = NULL;
                    tmp_1->next->val = 1;
                }
                break;
            }
            tmp_1 = tmp_1->next;
        }
        return l1;
    }


    else  if((tmp_2 == NULL) && (tmp_1 == NULL)&& isCarry==1) {
        printf("test\n"); //test====================
        struct ListNode *tmp = l1;
        while(1) {
            if(tmp->next == NULL) {
                break;
            }
            tmp = tmp->next;
        }
        tmp->next = (struct  ListNode*)malloc(sizeof(struct ListNode ));

        tmp->next->val = 1;
        tmp->next->next = NULL;
        return l1;
    }

    return l1;

}





int main(int argc, char *argv[]) {

    int n1, n2;
    scanf("%d %d", &n1, &n2);
    struct ListNode *l1,  *l2;
    l1 = numToList(n1);
    l2 = numToList(n2);


    printList(l1);
    printList(l2);


    struct ListNode *out = addTwoNumbers(l1, l2);

    printList(out);




    return 0;
}
