typedef struct node {
    int val;
    struct node *next;
} node ;

typedef struct node Node;
void insertNode(Node *,int);
void display(Node *);
void input(Node *, int);