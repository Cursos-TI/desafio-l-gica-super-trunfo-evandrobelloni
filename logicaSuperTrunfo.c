#include <stdio.h>
#include <string.h> 

int main() {
    // --- DADOS DA CARTA 1 ---
    char estado1[3];          // Alterado para string para acomodar a sigla (ex: "SP")
    char codigo1[4];
    char nome_cidade1[30];
    int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;
    float densidade1;
    float pib_per_capita1;

    // --- DADOS DA CARTA 2 ---
    char estado2[3];
    char codigo2[4];
    char nome_cidade2[30];
    int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;
    float densidade2;
    float pib_per_capita2;

    //==============================================================
    // CADASTRO DAS CARTAS
    //==============================================================

    // --- Leitura da primeira carta ---
    printf("--- Cadastro da Primeira Carta ---\n");
    printf("Estado (sigla, ex: SP): ");
    scanf(" %2s", estado1);
    printf("Codigo da carta (ex: A01): ");
    scanf(" %3s", codigo1);
    printf("Nome da cidade: ");
    scanf(" %29s", nome_cidade1); 
    printf("Populacao total: ");
    scanf("%d", &populacao1);
    printf("Area em Km²: ");
    scanf("%f", &area1);
    printf("PIB (em bilhoes, ex: 15.75): ");
    scanf("%f", &pib1);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontos_turisticos1);
    printf("\n");

    // --- Leitura da segunda carta ---
    printf("--- Cadastro da Segunda Carta ---\n");
    printf("Estado (sigla, ex: RJ): ");
    scanf(" %2s", estado2);
    printf("Codigo da carta (ex: B03): ");
    scanf(" %3s", codigo2);
    printf("Nome da cidade: ");
    scanf(" %29s", nome_cidade2);
    printf("Populacao total: ");
    scanf("%d", &populacao2);
    printf("Area em Km²: ");
    scanf("%f", &area2);
    printf("PIB (em bilhoes, ex: 10.5): ");
    scanf("%f", &pib2);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontos_turisticos2);
    printf("\n");

    //==============================================================
    // CÁLCULOS DOS ATRIBUTOS
    //==============================================================

    // Cálculo para a Carta 1
    if (area1 > 0) {
        densidade1 = populacao1 / area1;
    } else {
        densidade1 = 0; 
    }
    if (populacao1 > 0) {
        pib_per_capita1 = (pib1 * 1000000000) / populacao1; // Converte PIB de bilhões para reais
    } else {
        pib_per_capita1 = 0; 
    }

    // Cálculo para a Carta 2
    if (area2 > 0) {
        densidade2 = populacao2 / area2;
    } else {
        densidade2 = 0;
    }
    if (populacao2 > 0) {
        pib_per_capita2 = (pib2 * 1000000000) / populacao2; // Converte PIB de bilhões para reais
    } else {
        pib_per_capita2 = 0;
    }


    //==============================================================
    // EXIBIÇÃO DAS CARTAS
    //==============================================================
    printf("===========================================\n");
    printf("           CARTAS CADASTRADAS\n");
    printf("===========================================\n\n");

    // --- Resultado da primeira carta ---
    printf("--- Carta 1: %s (%s) ---\n", nome_cidade1, estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Populacao: %d habitantes\n", populacao1);
    printf("Area: %.2f Km²\n", area1);
    printf("PIB: R$ %.2f bilhoes\n", pib1);
    printf("Pontos Turisticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/Km²\n", densidade1);
    printf("PIB per capita: R$ %.2f\n\n", pib_per_capita1);

    // --- Resultado da segunda carta ---
    printf("--- Carta 2: %s (%s) ---\n", nome_cidade2, estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Populacao: %d habitantes\n", populacao2);
    printf("Area: %.2f Km²\n", area2);
    printf("PIB: R$ %.2f bilhoes\n", pib2);
    printf("Pontos Turisticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/Km²\n", densidade2);
    printf("PIB per capita: R$ %.2f\n\n", pib_per_capita2);


    //==============================================================
    // COMPARAÇÃO DAS CARTAS
    //==============================================================
    printf("===========================================\n");
    printf("             HORA DO DUELO!\n");
    printf("===========================================\n\n");

    const char* atributo_escolhido = "PIB"; 

    printf("Comparacao de cartas (Atributo: %s):\n\n", atributo_escolhido);

    
    // Neste exemplo, vamos comparar pelo PIB. O maior vence.
    if (strcmp(atributo_escolhido, "PIB") == 0) {
        printf("Carta 1 - %s (%s): %.2f bilhoes\n", nome_cidade1, estado1, pib1);
        printf("Carta 2 - %s (%s): %.2f bilhoes\n", nome_cidade2, estado2, pib2);
        printf("\nResultado: ");

        if (pib1 > pib2) {
            printf("Carta 1 (%s) venceu!\n", nome_cidade1);
        } else if (pib2 > pib1) {
            printf("Carta 2 (%s) venceu!\n", nome_cidade2);
        } else {
            printf("Empate!\n");
        }
    }
    
    else if (strcmp(atributo_escolhido, "Populacao") == 0) {
        printf("Carta 1 - %s (%s): %d habitantes\n", nome_cidade1, estado1, populacao1);
        printf("Carta 2 - %s (%s): %d habitantes\n", nome_cidade2, estado2, populacao2);
        printf("\nResultado: ");

        if (populacao1 > populacao2) {
            printf("Carta 1 (%s) venceu!\n", nome_cidade1);
        } else if (populacao2 > populacao1) {
            printf("Carta 2 (%s) venceu!\n", nome_cidade2);
        } else {
            printf("Empate!\n");
        }
    }
    
    else if (strcmp(atributo_escolhido, "Densidade Populacional") == 0) {
        printf("Carta 1 - %s (%s): %.2f hab/Km²\n", nome_cidade1, estado1, densidade1);
        printf("Carta 2 - %s (%s): %.2f hab/Km²\n", nome_cidade2, estado2, densidade2);
        printf("\nResultado: ");

        if (densidade1 < densidade2) {
            printf("Carta 1 (%s) venceu! (Menor densidade)\n", nome_cidade1);
        } else if (densidade2 < densidade1) {
            printf("Carta 2 (%s) venceu! (Menor densidade)\n", nome_cidade2);
        } else {
            printf("Empate!\n");
        }
    } else {
        printf("Atributo escolhido para comparacao nao e valido.\n");
    }

    printf("\n");

    return 0;
}
