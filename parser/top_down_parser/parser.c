#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "parse_table.h"
#include "parser.h"

int get_terminal_index(char *t){
    for(int i=0;i<T;i++){
        if(strcmp(t,terminals[i])==0)
            return i;
    }
    return -1;
}

int get_nonterminal_index(char *nt){
    for(int i=0;i<NT;i++){
        if(strcmp(nt,nonterminals[i])==0)
            return i;
    }
    return -1;
}

void predictive_parse(char input[]){

    Stack stack;
    stack.top=-1;

    push(&stack,"$");
    push(&stack,"E");

    int ip=0;

    printf("\nSTACK\t\tINPUT\t\tACTION\n");

    while(!is_empty(&stack)){

        if(input[ip]=='\0'){
            printf("Unexpected end of input\n");
            break;
        }

        char *X=peek(&stack);

        char a[10];
        a[0]=input[ip];
        a[1]='\0';

        if(a[0]=='i')
            strcpy(a,"id");

        print_stack(&stack);
        printf("\t\t%c\t\t",input[ip]);

        if(strcmp(X,a)==0){
            printf("Match %s\n",a);
            pop(&stack);
            ip++;
        }

        else if(strcmp(X,"$")==0){
            break;
        }

        else{

            int row=get_nonterminal_index(X);
            int col=get_terminal_index(a);

            if(row==-1 || col==-1){
                printf("Error: skipping input symbol\n");
                ip++;
                continue;
            }

            char *entry=table[row][col];

            if(strcmp(entry,"")==0){
                printf("Error: discard input\n");
                ip++;
            }

            else if(strcmp(entry,"synch")==0){
                printf("Error recovery using SYNCH\n");
                pop(&stack);
            }

            else if(strcmp(entry,"ε")==0){
                printf("%s -> ε\n",X);
                pop(&stack);
            }

            else{

                printf("%s -> %s\n",X,entry);

                pop(&stack);

                char temp[50];
                strcpy(temp,entry);

                char *token=strtok(temp," ");

                char symbols[10][10];
                int count=0;

                while(token!=NULL){
                    strcpy(symbols[count++],token);
                    token=strtok(NULL," ");
                }

                for(int i=count-1;i>=0;i--){
                    push(&stack,symbols[i]);
                }
            }
        }

        if(input[ip]=='$' && strcmp(peek(&stack),"$")==0)
            break;
    }

    printf("\nParsing completed\n");
}