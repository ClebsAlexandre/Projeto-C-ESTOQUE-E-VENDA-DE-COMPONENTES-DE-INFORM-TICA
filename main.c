// Projeto Final 
// Professor: Mayrton
// Grupo: Clebson  Alexandre, Sergio Roberto
// Tema: Sistema de Estoque e Venda para Componentes de Informática

#include <stdio.h>
#include <string.h>

// Registro para armazenar dados dos componentes
typedef struct componente {
    char nome[50];
    char marca[30];
    int codigo;
    int garantia;
    float preco;
    char descricao[100];
    char tipo[20];
    char notaFiscal[20]; 
    int quantidade;
} comp;

int cont_comp = -1;

int menu();
void cad_comp(comp *);
void listar_comp(comp *);
void att_estoque(comp *);
void remover_comp(comp *);
void buscar_comp(comp *);
void vender(comp *);

int main() {
    int opc;
    comp c[5]; // Vetor para os componentes cadastrados

    do {
        opc = menu();
        switch (opc) {
            case 1:
                cad_comp(&c[cont_comp + 1]);
                break;
            case 2:
                listar_comp(c);
                break;
            case 3:
                att_estoque(c);
                break;
            case 4:
                remover_comp(c);
                break;
            case 5:
                buscar_comp(c);
                break;
            case 6:
                vender(c);
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Escolha uma opção válida!\n");
                break;
        }
    } while (opc != 7);

    return 0;
}

int menu() {
    int opc;
    printf("--------------- MENU DE GERENCIAMENTO E VENDA DE COMPONENTES ---------------\n");
    printf("1 - Cadastrar componente\n");
    printf("2 - Listar Componentes\n");
    printf("3 - Atualizar Estoque\n");
    printf("4 - Remover Componente\n");
    printf("5 - Buscar Componente\n");
    printf("6 - Ir para Venda\n");
    printf("7 - SAIR\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opc);
    return opc;
}

void cad_comp(comp *c) {
    if (cont_comp >= 5) { 
        printf("Limite de componentes atingido.\n");
        return;
    }
    cont_comp++;

    c->codigo = cont_comp + 1;

    printf("Nome do Componente: ");
    scanf(" %[^\n]", c->nome); 

    printf("Marca: ");
    scanf(" %[^\n]", c->marca);

    printf("Garantia (em meses): ");
    scanf("%d", &c->garantia);

    printf("Preço: ");
    scanf("%f", &c->preco);

    printf("Descrição: ");
    scanf(" %[^\n]", c->descricao);

    printf("Tipo: ");
    scanf(" %[^\n]", c->tipo);

    printf("Quantidade em estoque: ");
    scanf("%d", &c->quantidade);
}

void listar_comp(comp *c) {
    if (cont_comp < 0) {
        printf("Nenhum componente cadastrado.\n");
        return;
    }

    for (int i = 0; i <= cont_comp; i++) {
        printf("\n--- Componente %d ---\n", i + 1);
        printf("Código: %d\n", (c + i)->codigo);
        printf("Nome: %s\n", (c + i)->nome);
        printf("Marca: %s\n", (c + i)->marca);
        printf("Garantia: %d meses\n", (c + i)->garantia);
        printf("Preço: R$ %.2f\n", (c + i)->preco);
        printf("Descrição: %s\n", (c + i)->descricao);
        printf("Tipo: %s\n", (c + i)->tipo);
        printf("Quantidade disponível: %d\n", (c + i)->quantidade);
    }
}

void att_estoque(comp *c) {
    if (cont_comp < 0) {
        printf("Nenhum componente cadastrado.\n");
        return;
    }

    int codigo, qtd;
    printf("Digite o código do componente para atualizar o estoque: ");
    scanf("%d", &codigo);

    for (int i = 0; i <= cont_comp; i++) {
        if ((c + i)->codigo == codigo) {
            printf("Quantidade atual: %d\n", (c + i)->quantidade);
            printf("Digite a quantidade para adicionar ao estoque: "); 
            scanf("%d", &qtd);
            (c + i)->quantidade += qtd; 
            printf("Estoque atualizado. Nova quantidade: %d\n", (c + i)->quantidade);
            return;
        }
    }
    printf("Componente não encontrado.\n");
}

void remover_comp(comp *c) {
    if (cont_comp < 0) {
        printf("Nenhum componente para remover.\n");
        return;
    }

    int codigo, i, j;
    printf("Digite o código do componente a ser removido: ");
    scanf("%d", &codigo);

    for (i = 0; i <= cont_comp; i++) {
        if ((c + i)->codigo == codigo) {
            printf("Componente '%s' removido.\n", (c + i)->nome);
            for (j = i; j < cont_comp; j++) {
                *(c + j) = *(c + j + 1);
            }
            cont_comp--;
            return;
        }
    }
    printf("Componente não encontrado.\n");
}

void buscar_comp(comp *c) {
    if (cont_comp < 0) {
        printf("Nenhum componente cadastrado.\n");
        return;
    }

    int codigo;
    printf("Digite o código do componente a buscar: ");
    scanf("%d", &codigo);

    for (int i = 0; i <= cont_comp; i++) {
        if ((c + i)->codigo == codigo) {
            printf("\n--- Componente Encontrado ---\n");
            printf("Código: %d\n", (c + i)->codigo);
            printf("Nome: %s\n", (c + i)->nome);
            printf("Marca: %s\n", (c + i)->marca);
            printf("Descrição: %s\n", (c + i)->descricao);
            printf("Preço: R$ %.2f\n", (c + i)->preco);
            printf("Quantidade disponível: %d\n", (c + i)->quantidade);
            return;
        }
    }
    printf("Componente não encontrado.\n");
}

void vender(comp *c) {
    if (cont_comp < 0) {
        printf("Nenhum componente disponível para venda.\n");
        return;
    }

    int codigo, quantidade_venda;
    printf("Digite o código do componente que deseja vender: ");
    scanf("%d", &codigo);

    for (int i = 0; i <= cont_comp; i++) {
        if ((c + i)->codigo == codigo) {
            printf("Quantidade disponível: %d\n", (c + i)->quantidade);
            printf("Digite a quantidade para venda: ");
            scanf("%d", &quantidade_venda);

            if (quantidade_venda > (c + i)->quantidade) {
                printf("Quantidade insuficiente em estoque.\n");
                return;
            }

            (c + i)->quantidade -= quantidade_venda;
            printf("Venda realizada com sucesso!\n");
            printf("Emitindo nota fiscal...\n");

            
            strcpy((c + i)->notaFiscal, "NF-0001"); 

            printf("\n--- Nota Fiscal ---\n");
            printf("%s\n", (c + i)->notaFiscal);
            printf("Componente: %s\n", (c + i)->nome);
            printf("Marca: %s\n", (c + i)->marca);
            printf("Quantidade Vendida: %d\n", quantidade_venda);
            printf("Valor Total: R$ %.2f\n", quantidade_venda * (c + i)->preco);
            printf("--------------------\n");
            return;
        }
    }
    printf("Componente não encontrado.\n");
}
