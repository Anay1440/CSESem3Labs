typedef struct node {
    int val;
    struct node * left;
    struct node * right;
} Node ;

typedef struct {
    Node * nodes[100];
    int tos;
} Stack;

typedef struct node Node;

Node * createNode(int );
void inOrder(Node *);
void postOrder(Node *);
void preOrder(Node *);
void insertBST(Node **,int);
void push(Stack * , Node * );
Node * pop(Stack * );
Node * peek(Stack * );