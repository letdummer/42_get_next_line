#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Supondo que a função ft_strjoin esteja definida em "get_next_line.h"
#include "get_next_line.h"

// Função para comparar strings e imprimir resultados
void test_strjoin( char *s1,  char *s2,  char *expected) {
    char *result = ft_strjoin(s1, s2);
    
    if (result == NULL && expected == NULL) {
        printf("Test passed: ft_strjoin(%s, %s) returned NULL as expected.\n", s1, s2);
    } else if (result != NULL && expected != NULL && strcmp(result, expected) == 0) {
        printf("Test passed: ft_strjoin(%s, %s) = %s\n", s1, s2, result);
    } else {
        printf("Test failed: ft_strjoin(%s, %s) = %s, expected %s\n", s1, s2, result ? result : "NULL", expected);
    }
    
    free(result); // Libere a memória alocada
}

int main() {
    // Testes normais
    test_strjoin("Hello, ", "world!", "Hello, world!");
    test_strjoin("foo", "bar", "foobar");
    
    // Testes com strings vazias
    test_strjoin("", "world!", "world!");
    test_strjoin("Hello, ", "", "Hello, ");
    test_strjoin("", "", "");
    
    // Testes com NULL
    test_strjoin(NULL, "world!", "world!");
    test_strjoin("Hello, ", NULL, "Hello, ");
    test_strjoin(NULL, NULL, NULL);
    
    return 0;
}