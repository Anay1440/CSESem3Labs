typedef struct node {
    int val;
    struct node *right;
    struct node *left;
} node ;

typedef struct node Node;
void insertNode(Node *,int);
void insertEnd(Node **,int);
void insertFront(Node **,int);
void display(Node *);
void input(Node *, int);
void deleteNode(Node **,Node *);