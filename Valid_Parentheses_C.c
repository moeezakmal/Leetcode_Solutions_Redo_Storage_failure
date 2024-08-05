// Time: O(n) -> traverse through string
// Space: O(n) -> stack size


typedef struct {
    char data;
    struct stkNode *next;
} stkNode;

bool match(char ch1, char ch2)
{
    if (ch1 == '(' && ch2 == ')')
        return 1;
    else if (ch1 == '{' && ch2 == '}')
        return 1;
    else if (ch1 == '[' && ch2 == ']')
        return 1;
    else
        return 0;
}

void push(stkNode** top, int _data)
{
    stkNode* new_node = (stkNode*)malloc(sizeof(stkNode));

    new_node->data = _data;
    new_node->next = *top;
    *top = new_node;
}

char pop(stkNode** top)
{
    char res;
    stkNode* temp;

    if (*top == NULL) {
        printf("Stack overflow \n");
        getchar();
        exit(0);
    }
    else {
        temp = *top;
        res = temp->data;
        *top = temp->next;
        free(temp);
        return res;
    }
}

bool isValid(char* s) {
    stkNode *stk = NULL;

    int i = 0;
    while(s[i])
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
            push(&stk, s[i]);
        
        if (s[i] == '}' || s[i] == ')' || s[i] == ']') 
        {
            if (stk == NULL)
                return 0;

            else if (!match(pop(&stk), s[i]))
                return 0;
        }
        i++;
    }

    if (stk == NULL)
        return 1;
    else
        return 0;
}