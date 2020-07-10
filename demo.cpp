#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct number {
    struct list_head list;
    int num;
};


int main(int argc, char **argv) {
    int i;
    struct number *p;
    struct number number1;
    struct list_head *pos;

    INIT_LIST_HEAD(&number1.list);

    for (i = 0; i < 5; i++) {
        p = (struct number *) malloc(sizeof(struct number));
        p->num = i * 10;
        list_add(&p->list, &number1.list);
    }

    list_for_each(pos, &number1.list)
    {
        printf("初始化数字如下\n");
        printf("num = %d\n", ((struct number *) pos)->num);
        printf("删除30\n")
    }

    list_for_each_entry(pos, &head.list, list)
    {
        if (pos->age == 30) {
            list_del(&pos->list);
            break;
        }
    }
    list_for_each(pos, &number1.list)
    {
        printf("现在数字如下\n");
        printf("num = %d\n", ((struct number *) pos)->num);
    }
    return 0;
}