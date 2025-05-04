#include <stdio.h>
#include <stdlib.h>

#define MAX_ANIMAIS 10

typedef struct {
    char tipoAnimal[50];
    int quantidadeAnimais;
    float custoEstimado;
} Animais;

int main(void) {
    Animais animais[MAX_ANIMAIS];
    int n, i;

    printf("\nQuanto animais voce quer cadastrar?");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {

        printf("\n***Cadastro do animal %d***", i + 1);

        printf("\nTipo de animais: ");
        scanf("%s", &animais[i].tipoAnimal);

        printf("Quantidade de %s: ", animais[i].tipoAnimal);
        scanf("%d", &animais[i].quantidadeAnimais);

        printf("Custo estimado de comida dos %s: ", animais[i].tipoAnimal);
        scanf("%f", &animais[i].custoEstimado);
    }

    for (i = 0; i < n; i++) {
        float totalComidaPorAnimal = animais[i].custoEstimado / animais[i].quantidadeAnimais;
        float totalComidaMes = animais[i].custoEstimado * 30;
        float custo = totalComidaMes * 10;

        printf("\nAnimal %s:\n", animais[i].tipoAnimal);
        printf("- Tipo do animal: %s\n", animais[i].tipoAnimal);
        printf("- Quantidade de animais: %d\n", animais[i].quantidadeAnimais);
        printf("- Quantidade por kilo por animal: %.2f kg\n", totalComidaPorAnimal);
        printf("- Quantidade por dia (total): %.2f kg\n", animais[i].custoEstimado);
        printf("- Por mes: %.2f kg\n", totalComidaMes);
        printf("- Custo estimado por mes: R$ %.2f\n", custo);
    }

    system("\npause");
    return 0;

}
