#include <stdio.h>
#include <stdlib.h>
#include "../1/c/stackadt.h"

const char par_closMiss[] = "Parenteses fechado faltando na linha";
const char par_openMiss[] = "Parenteses aberto faltando na linha";
const char col_closMiss[] = "Colchete fechado faltando na linha";
const char col_openMiss[] = "Colchete aberto faltando na linha";
const char cha_closMiss[] = "Chave fechada faltando na linha";
const char cha_openMiss[] = "Chave aberta faltando na linha";
const char cor_erro[] = "Erro de correspondencia na linha"; 
const char sucesso[] = "não há nenhum erro no arquivo!";

int main (void)
{
    int check_token,lineCount = 1;
    char token,topo,fileID[25],valor_saida;
    FILE* fpIn;
    void* dataoutptr = malloc(sizeof(char));
    STACK* stack = create_stack();
    printf("Entre com o arquivo que deseja ler\n");
    scanf("%s",fileID);
    fpIn = fopen(fileID, "r");
    if (fpIn == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }
    while ((check_token = fgetc(fpIn)) != EOF)
    {
        token = (char)check_token;
        if (token == '\n') lineCount++;
        else if (token == '(' || token == '[' || token == '{')
        {
            push_stack(stack,&token,sizeof(char));
        }
        else if (token == ')' || token == ']' || token == '}')
        {
            if(empty_stack(stack))
            {
                switch (token)
                {
                case ')':
                    printf("%s %d\n", par_openMiss, lineCount);
                    break;
                case ']':
                    printf("%s %d\n", col_openMiss, lineCount);
                    break;
                case '}':
                    printf("%s %d\n", cha_openMiss, lineCount);
                    break;
                }
                destroy_stack(stack);
                return 1;
            }
            pop_stack(stack,dataoutptr);
            topo = *(char*)dataoutptr;
            
            if 
            (
                (topo == '(' && token != ')')  
                || 
                ( topo == '[' && token != ']' )
                ||
                (topo == '{' && token != '}')
            )
            {
                printf("%s %d\n",cor_erro,lineCount);
                destroy_stack(stack);
                return 1;
            }

        }
    }
    if(!empty_stack(stack))
    {
        pop_stack(stack,dataoutptr);
        topo = *(char*)dataoutptr;
        switch(topo)
        {
            case '(':
                printf("%s %d\n", par_closMiss, lineCount);
                break;
            case '[':
                printf("%s %d\n", col_closMiss, lineCount);
                break;
            case '{':
                printf("%s %d\n", cha_closMiss, lineCount);
                break;
        }
        destroy_stack(stack);
        return 1;
    }
    fclose(fpIn);
    destroy_stack(stack);
    free(dataoutptr);
    printf("%s\n", sucesso);
    return 0;
}