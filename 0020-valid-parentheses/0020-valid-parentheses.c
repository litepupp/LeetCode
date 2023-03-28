typedef struct Node {
    char item;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct LinkedList {
    struct Node* head;
    struct Node* tail;
    int length;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* tempList = (LinkedList*)malloc(sizeof(LinkedList));
    tempList -> head = NULL;
    tempList -> tail = NULL;
    tempList -> length = 0;
    
    return tempList;
}

void pushLinkedList(LinkedList* list, char newItem) {
    Node* tempNode = (Node*)malloc(sizeof(Node));
    tempNode -> item = newItem;
    tempNode -> next = NULL;
    tempNode -> prev = NULL;
    
    if (list -> head == NULL || list -> tail == NULL) {
        list -> head = tempNode;
        list -> tail = tempNode;
        list -> length++;
        
        return;
    }
    
    Node* prevTail = list -> tail;
    list -> tail = tempNode;
    prevTail -> next = tempNode;
    tempNode -> prev = prevTail;
    list -> length++;
    
    return;
}

char popLinkedList(LinkedList* list) {
    if (list -> head == NULL || list -> tail == NULL) {
        return '\0';
    }
    
    char tailItem = list -> tail -> item;
    Node* oldTail = list -> tail;
    Node* newTail = list -> tail -> prev;
    
    if (newTail == NULL) {
        list -> head = NULL;
        list -> tail = NULL;
        
        free(oldTail);
        list -> length--;
        return tailItem;
    }
    
    newTail -> next = NULL;
    list -> tail = newTail;
    free(oldTail);
    list -> length--;
    
    return tailItem;
}

void freeLinkedList(LinkedList* list) {
    Node* currNode = list -> head;
    Node* nextNode = NULL;
    
    while (currNode != NULL) {
        nextNode = currNode -> next;
        free(currNode);
        currNode = nextNode;
    }
    
    free(list);
    return;
}

bool isMatchingBrackets(char open, char close) {
    if (open == '(' && close == ')') return true;
    else if (open == '{' && close == '}') return true;
    else if (open == '[' && close == ']') return true;
    else return false;
}

bool isValid(char* s) {
    LinkedList* stack = createLinkedList();
    int stringLen = strlen(s);
    int finalLen;
    
    for (int i = 0; i < stringLen; i++) {
        if (stack -> head != NULL) {
            if (isMatchingBrackets(stack -> tail -> item, s[i])) {
                popLinkedList(stack);
                continue;
            } 
        }

        pushLinkedList(stack, s[i]);
    }
    
    finalLen = stack -> length;
    freeLinkedList(stack);
    
    return finalLen == 0;
}