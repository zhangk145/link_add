#include <stdio.h>

struct node {
    int value;
    struct node *next;
};

struct node *link_init(int arr[], int size) {
    int i = 0;
    struct node *pp = NULL;
    struct node * p = NULL;
    struct node *head = NULL;
    for (i = 0; i < size; i++) {
        p = (struct node *)malloc(sizeof(struct node));
        p->value = arr[i];
        p->next = NULL;
        if (head == NULL) {
            head = p;
            pp = head;
        }
        else {
            pp->next = p;
            pp = pp->next;
        }
        printf("value:%d\n", p->value);
    }
    printf("=====link_init=====\n");
    return head;
}

struct node *add(struct node *l1, struct node *l2) {
    
    struct node *p1 = l1;
    struct node *p2 = l2;
    struct node *head = NULL;
    struct node *p = NULL;
    struct node *ll = NULL;
    int carry = 0;
    int bit = 0;
    while (p1 || p2) {
        int v1 = 0;
        int v2 = 0;
        int sum = 0;
        if (p1) {
            v1 = p1->value;
            p1 = p1->next;
        }
        if (p2) {
            v2 = p2->value;
            p2 = p2->next;
        }
        sum = v1 + v2 + carry;
        // printf("[%s:%d]v1:%d v2:%d sum:%d\n", __FUNCTION__, __LINE__, v1, v2, sum);
        carry = sum / 10;
        bit = sum % 10;
        // printf("[%s:%d]carry:%d bit:%d\n", __FUNCTION__, __LINE__, carry, bit);
        ll = (struct node *)malloc(sizeof(struct node));
        ll->value = bit;
        ll->next = NULL;
        if (head == NULL) {
            head = ll;
            p = head;
        }
        else {
            p->next = ll;
            p = p->next;
        }
    }
    if (carry > 0) {
        struct node * pp = (struct node *)malloc(sizeof(struct node));
        pp->value = bit;
        pp->next = NULL;
        ll->next = pp;
    }
    return head;
}

void print_result(struct node *p) {
    printf("p:%p num is : ", p);
    while (p) {
        printf("%d", p->value);
        p = p->next;
    }
    printf(" \n");
}

int main(int argc, char *argv[]) {
    int arr1[] = {0, 5, 3};
    int arr2[] = {4, 1, 2, 7, 1};
    int num1 = sizeof(arr1) / sizeof(arr1[0]);
    int num2 = sizeof(arr2) / sizeof(arr2[0]);
    struct node *l1 = link_init(arr1, num1);
    struct node *l2 = link_init(arr2, num2);
    struct node *p = add(l1, l2);
    print_result(p);
    free((void *)p);
    return 0;
}