#include <stdio.h>

struct Carta {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
};

void calcular_propriedades(struct Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;

    // abaixo calculamos o "Poder" (somando todas a propriedades)
    carta->super_poder = carta->populacao +
                        carta->area +
                        carta->pib +
                        carta->pontos_turisticos +
                        carta->densidade_populacional +
                        carta->pib_per_capita;
}

void lendo_carta(struct Carta *carta) {
    printf("\n$$$ cadastro de Carta $$$\n");
    printf("Digite o codigo da carta (exemplo A01): ");
        scanf("%s", carta->codigo);
    
    printf("Digite a populacao: ");
    scanf("%d", &carta->populacao);
    
    printf("Digite a area (km2): ");
    scanf("%f", &carta->area);
    
    printf("Digite o PIB: ");
    scanf("%f", &carta->pib);
    
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta->pontos_turisticos);
    
    calcular_propriedades(carta);
}

void output_carta(struct Carta carta) {
    printf("\n=== Carta %s ===\n", carta.codigo);
    printf("Propriedades Basicas:\n");
    printf("- Populacao: %d habitantes\n", carta.populacao);
    printf("- Area: %.2f km2\n", carta.area);
    printf("- PIB: R$ %.2f\n", carta.pib);
    printf("- Pontos Turisticos: %d\n", carta.pontos_turisticos);
    
    printf("\nPropriedades Calculadas:\n");
    printf("- Densidade Populacional: %.2f hab/km2\n", carta.densidade_populacional);
    printf("- PIB per Capita: R$ %.2f\n", carta.pib_per_capita);
    printf("- Super Poder: %.2f\n", carta.super_poder);
}

void comparar_cartas(struct Carta carta1, struct Carta carta2) {
    printf("\n$$$ Comparacao de Cartas $$$\n");
    
    // População
    printf("\nPopulacao:\n");
    printf("%s: %d vs %s: %d\n", carta1.codigo, carta1.populacao, 
                                 carta2.codigo, carta2.populacao);
    printf("Vencedor: %s\n", 
           carta1.populacao > carta2.populacao ? carta1.codigo : carta2.codigo);
    
    // Área
    printf("\nArea:\n");
    printf("%s: %.2f vs %s: %.2f\n", carta1.codigo, carta1.area, 
                                     carta2.codigo, carta2.area);
    printf("Vencedor: %s\n", 
           carta1.area > carta2.area ? carta1.codigo : carta2.codigo);
    
    // PIB
    printf("\nPIB:\n");
    printf("%s: %.2f vs %s: %.2f\n", carta1.codigo, carta1.pib, 
                                     carta2.codigo, carta2.pib);
    printf("Vencedor: %s\n", 
           carta1.pib > carta2.pib ? carta1.codigo : carta2.codigo);
    
    // Pontos Turísticos
    printf("\nPontos Turisticos:\n");
    printf("%s: %d vs %s: %d\n", carta1.codigo, carta1.pontos_turisticos, 
                                 carta2.codigo, carta2.pontos_turisticos);
    printf("Vencedor: %s\n", 
           carta1.pontos_turisticos > carta2.pontos_turisticos ? carta1.codigo : carta2.codigo);
    
    // Densidade Populacional (menor vence)
    printf("\nDensidade Populacional (menor vence):\n");
    printf("%s: %.2f vs %s: %.2f\n", carta1.codigo, carta1.densidade_populacional, 
                                     carta2.codigo, carta2.densidade_populacional);
    printf("Vencedor: %s\n", 
           carta1.densidade_populacional < carta2.densidade_populacional ? carta1.codigo : carta2.codigo);
    
    // PIB per Capita
    printf("\nPIB per Capita:\n");
    printf("%s: %.2f vs %s: %.2f\n", carta1.codigo, carta1.pib_per_capita, 
                                     carta2.codigo, carta2.pib_per_capita);
    printf("Vencedor: %s\n", 
           carta1.pib_per_capita > carta2.pib_per_capita ? carta1.codigo : carta2.codigo);
    
    // Super Poder
    printf("\nSuper Poder:\n");
    printf("%s: %.2f vs %s: %.2f\n", carta1.codigo, carta1.super_poder, 
                                     carta2.codigo, carta2.super_poder);
    printf("Vencedor: %s\n", 
           carta1.super_poder > carta2.super_poder ? carta1.codigo : carta2.codigo);
}

int main() {
    struct Carta carta1, carta2;
    
    printf("Cadastro da primeira carta:\n");
    lendo_carta(&carta1);
    
    printf("\nCadastro da segunda carta:\n");
    lendo_carta(&carta2);
    
    // Exibe os dados das duas cartas
    output_carta(carta1);
    output_carta(carta2);
    
    // Compara as cartas
    comparar_cartas(carta1, carta2);
    
    return 0;
}