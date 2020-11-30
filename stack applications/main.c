#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char x)
{
    if (top == SIZE-1)
    {
        printf("\nStack overflow");
    }
    else
    {
        top = top + 1;
        stack[top]=x;
    }
}

char pop()
{
    char x;
    if (top == -1)
    {
        printf("\nNo element to pop");
        getchar();
        exit(1);
    }
    else
    {
        x = stack[top];
        top = top - 1;
        return(x);
    }
}

int check_operator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char symbol)
{
    if (symbol == '^')
    {
        return(3);
    }
    else if (symbol == '*' || symbol == '/')
    {
        return(2);
    }
    else if (symbol == '+' || symbol == '-')
    {
        return(1);
    }
    else
    {
        return (0);
    }
}

void infix_to_postfix(char infixExp[], char postfixExp[])
{
    int i, j;
    char x, y;

    push('(');
    strcat(infixExp,")");

    i=0;
    j=0;
    x = infixExp[i];

    while (x!='\0')
    {
        if (x=='(')
        {
            push(x);
        }
        else if (isdigit(x) || isalpha(x))
        {
            postfixExp[j]=x;
            j++;
        }
        else if (check_operator(x)==1)
        {
            y=pop();
            while (check_operator(y)==1 && precedence(y)>=precedence(x))
            {
                postfixExp[j]=y;
                j++;
                y=pop();
            }
            push(y);

            push(x);
        }
        else if (x==')')
        {
            y=pop();
            while (y!='(')
            {
                postfixExp[j]=y;
                j++;
                y=pop();
            }
        }
        else
        {
            printf("\nInfix expression is invalid.");
            getchar();
            exit(1);
        }
        i++;

        x=infixExp[i];
    }

    if (top>0)
    {
        printf("\nInfix expression is invalid.");
        getchar();
        exit(1);
    }
    if (top>0)
    {
        printf("\nInfix expression is invalid.");
        getchar();
        exit(1);
    }

    postfixExp[j] = '\0';

}

int eval_postfix(char postfixExp[])
{
    char ch;
    int i=0, op1, op2;
    while ((ch=postfixExp[i++])!=0)
    {
        if (isdigit(ch))
        {
            push(ch-'0');
        }
        else
        {
            op2=pop();
            op1=pop();
            switch(ch)
            {
                case '+' : push(op1+op2);
                break;
                case '-' : push(op1-op2);
                break;
                case '*' : push(op1*op2);
                break;
                case '/' : push(op1/op2);
                break;
            }
        }
    }
    return stack[top];
}

int main()
{
    char infix[SIZE], postfix[SIZE];
    printf("\nEnter infix expression: ");
    gets(infix);

    infix_to_postfix(infix,postfix);
    printf("\nPostfix expression: ");
    puts(postfix);

    top=-1;
    printf("\nEvaluated postfix expression: %d", eval_postfix(postfix));

    return 0;
}
