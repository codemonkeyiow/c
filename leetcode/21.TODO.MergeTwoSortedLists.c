struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL && list2 == NULL) return NULL;
    if(list1 == NULL) {
        return list2;
    } else if(list2 == NULL) {
        return list1;
    }

    struct ListNode* list = malloc(sizeof(struct ListNode));
    list->next = NULL;
    list->val = 0;

    while(list1->next != NULL) {
        list->val = list1->val;
        while(list2->next != NULL) {
            if(list2->val > list1->val) break;

            struct ListNode* node = malloc(sizeof(struct ListNode));
            node->next = NULL;
            node->val = list2->val;

            list->next = node;
            list = list->next;

            list2 = list2->next;
        }
        list1 = list1->next;
    }

    return list;
}

int main() {
  return 0;
}
