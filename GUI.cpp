#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSIZE 100

char stack[MAXSIZE];
int top = -1;

char peek() {
   return stack[top];
}

int isEmpty() {
   return top == -1;
}

int isFull() {
   return top == MAXSIZE - 1;
}

void push(char elem) {
   if (isFull()) {
       printf("Stack Overflow\n");
       exit(1);
   }
   stack[++top] = elem;
}

char pop() {
   if (isEmpty()) {
       printf("Stack Underflow\n");
       exit(1);
   }
   return stack[top--];
}

int precedence(char op) {
   switch (op) {
       case '+':
       case '-':
           return 1;
       case '*':
       case '/':
       case '%':
           return 2;
       default:
           return 0;
   }
}

void infixToPostfix(char *infix, char *postfix) {
   int i, j;
   char ch, popped;

   push('(');
   strcat(infix, ")");

   i = 0;
   j = 0;
   ch = infix[i];

   while (ch != '\0') {
       if (ch == '(') {
           push(ch);
       } else if (isalnum(ch)) {
           postfix[j++] = ch;
       } else if (isOperator(ch)) {
           while (precedence(peek()) >= precedence(ch)) {
               popped = pop();
               postfix[j++] = popped;
           }
           push(ch);
       } else if (ch == ')') {
           popped = pop();
           while (popped != '(') {
               postfix[j++] = popped;
               popped = pop();
           }
       } else {
           printf("Invalid infix Expression.\n");
           exit(1);
       }
       i++;
       ch = infix[i];
   }

   postfix[j] = '\0';
}

int main() {
   char infix[MAXSIZE], postfix[MAXSIZE];

   printf("Enter the infix expression: ");
   fgets(infix, MAXSIZE, stdin);  // Use fgets for safer input

   infixToPostfix(infix, postfix);

   printf("Postfix expression: %s", postfix);

   return 0;
}
