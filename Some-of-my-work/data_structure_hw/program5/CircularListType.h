//CircularList type

typedef struct node {
    int item; 
    struct node *link; 
} ListNode;

typedef struct {
    ListNode *cursor;
} CircularList;