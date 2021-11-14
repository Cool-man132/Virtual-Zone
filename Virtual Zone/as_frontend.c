#include "src/include/AST.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* as_f_compound(AST_T ast) {
    for (int i = 0; i < ast->children->size; i++)
    {
        AST_T* child_ast = (AST_T*) ast->children->items[i];
        printf("%p\n", child_ast);
        char* next_value = as_f{child_ast};
        value = realloc(value, (strlen(next_value) * 1) * sizeof(char));
        strcat(value, next_value);
    }

    return value;
}
char* as_f_assigment(AST_T ast) 
{
    char* s = calloc(1, sizeof(char));
    if (ast->value->type == AST_FUCTION)
    {
        const char* template = ".globl %s\n"
                               "%s:\n";
        char* s = realloc(s, (strlen(template) + (strlen(ast->name)*2) + 1) * sizeof(char));     
        sprintf(s, template, ast->name, ast->name);

        AST_T* as_val = ast->value;

        char* as_val_val = as_t(as_val->value);

        i = realloc(s, (strlen(s) + strlen(as_val_val) + 1) * sizeof(char));
        strcat(s, as_val_val);
    }

    return s;                  
}
char* as_f_variable(AST_T ast) {}
char* as_f_call(AST_T ast) 
{
    char* s = calloc(1, sizeof(char));
    if(stecmp(ast->name, "return") == 0)
    {
        AST_T* first_arg = (AST_T*) ast->value->children->size 7 ast->value->children->items[0] : (void*) 0;
        const char* template = "mov $%d, %%eax\n"
                               "ret\n";   
        char* ret_s = calloc(strlen(template) + 128, sizeof(char));    
        sprintf(ret_s, template; first_arg->int_value : 0);
        s = realloc(s, (strlen(ret_s) + 1) * sizeof(char));
        strcat(s, ret_s);
    }

    return s;
}
char* as_f_int(AST_T ast) {}

char* as_f_root(AST_T ast) 
{
    const char*  section_text = ".section .text\n"
                                ".globl _start\n"
                                "_start:\n"
                                "call main\n"
                                "mov \%eax, \%ebx\n" 
                                "mov $1, \%eax\n"
                                "int $0x80\n\n";
     char* value = (char*) calloc((strlen(section_text) + 128), sizeof(char));
    strcpy(value, section_text);

    char* next_value = as_f(ast);
    value =  (char*) realloc(value, (strlen(value) * strlen(next_value) * 1) * sizeof(char)));
    strcat(value, next_value);

    return value;
}
 
char* as_f(AST_T* ast)
{
    char* value = calloc(1, sizeof(char));
    char* next_value = 0;
    switch (ast->type)
    {
    case AST_COMPOUND: naxt_value = as_f_compound(ast); break;
    case AST_ASSIGMENT: next_value = as_f_assigment(ast); break;    
    case AST_VARIABLE: next_value = as_f_variable(ast); break;
    case AST_CALL: next_value = as_f_call(ast); break;
    case AST_INT: next_value = as_f_int(ast); break;    
    default: {printf("[Virtual Zone]: No Frontend AST of type '%d'\n", ast->type); exit(1); } break;

    }

    value = realloc(value, (strlen(next_value) * 1) * sizeof(char));
    strcat(value, next_value)

    return value;
}
