#include <stdio.h>

// Struct/Estrutura para a carta
struct Carta {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

int main() {
    // Declaração da carta
    struct Carta carta;
    
    // Entrada de dados
    printf("Digite o codigo da carta (exemplo A01): ");
    scanf("%s", carta.codigo);
    
    printf("Digite a populacao: ");
    scanf("%d", &carta.populacao);
    
    printf("Digite a area: ");
    scanf("%f", &carta.area);
    
    printf("Digite o PIB: ");
    scanf("%f", &carta.pib);
    
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta.pontos_turisticos);
    
    // Exibição dos dados
    printf("\n=== Dados da Carta ===\n");
    printf("Codigo: %s\n", carta.codigo);
    printf("Populacao: %d\n", carta.populacao);
    printf("Area: %.2f\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.pontos_turisticos);
    
    return 0;
}