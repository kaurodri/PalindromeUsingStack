#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
typedef struct {
    char array[MAX];
    int topo;
} Stack;

void init(Stack *s) {
    s->topo = -1;
}

//adicionar.
int isFull(Stack *s) {
    return s->topo == (MAX - 1);
}
void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->array[++(s->topo)] = c;
    }
}

//remover.
int isEmpty(Stack *s) {
    return s->topo == -1;
}
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->array[(s->topo)--];
    }
    return '\0'; //retorna um caractere nulo se a pilha estiver vazia.
}

//função.
int isPalindrome(char *str) {
    Stack s;
    init(&s);

    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) { //ignorar caracteres não alfabéticos.
            push(&s, tolower(str[i])); //empilha a letra em minúsculo.
        }
    }

    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) {
            if (tolower(str[i]) != pop(&s)) { //comparar com o caractere desempilhado.
                return 0; //não é um palíndromo.
            }
        }
    }

    return 1; //é um palíndromo.
}

int main() {
    char palavra[MAX];
    printf("Digite uma palavra: ");
    fgets(palavra, sizeof(palavra), stdin); //lê o terminal.

    //remove o caractere extra.
    palavra[strcspn(palavra, "\n")] = '\0';

    if (isPalindrome(palavra)) {
        printf("\"%s\" e um palindromo.\n", palavra);
    } else {
        printf("\"%s\" nao e um palindromo.\n", palavra);
    }

    return 0;
}