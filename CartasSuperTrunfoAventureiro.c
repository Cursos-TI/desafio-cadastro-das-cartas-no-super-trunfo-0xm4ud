#include <stdio.h>

//Struct para carta
// Struct aqui facilita a leitura e organizacao do codigo e tb adiciona sentido ao dado no contexto do program IMHO.
struct Carta {
    // Propriedades básicas
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;

    //propriedades calculadas
    float densidade_populacional;
    float pib_per_capita;
};

// Funçao para calcular as propriedades

void calcular_propriedades(struct Carta *carta) {
    //Calcula densidade populacional (hab/km**2)
    carta->densidade_populacional = carta->populacao / carta->area;

    // calcula PIB per capita
    carta->pib_per_capita = carta->pib / carta->populacao;
}

int main() {

    struct Carta carta;

    printf("$$$ Cadastro de Carta $$$\n");
    printf("Digite o codigo da carta (exemplo A01): ");
    scanf("%s", carta.codigo);

    printf("Digite a populacao: ");
    scanf("%d", &carta.populacao);

    printf("Digite a area (km**2): ");
    scanf("%f", &carta.area);

    printf("Digite o PIB: ");
    scanf("%f", &carta.pib);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta.pontos_turisticos);

    // faz o calculo das propriedades adicionais
    calcular_propriedades(&carta);

    // Ouput de dados
    printf("\n$$$ Dados da Carta $$$\n");
    printf("Codigo: %s\n", carta.codigo);
    printf("Propriedades Basicas:\n");
    printf("- Populacao: %d habitantes\n", carta.populacao);
    printf("- Area: %.2f km2\n", carta.area); // dois decimais de format specifier deve bastar tanto em Area quanto PIB
    printf("- PIB: R$ %.2f\n", carta.pib);
    printf("- Pontos Turisticos: %d\n", carta.pontos_turisticos);
    
    printf("\nPropriedades Calculadas:\n");
    printf("- Densidade Populacional: %.2f hab/km2\n", carta.densidade_populacional);
    printf("- PIB per Capita: R$ %.2f\n", carta.pib_per_capita);
    
    return 0;
}