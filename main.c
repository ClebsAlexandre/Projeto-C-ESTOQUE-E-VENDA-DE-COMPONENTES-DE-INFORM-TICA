// Projeto Final
// Professor: Mayrton
// Grupo: Clebson  Alexandre, Sergio Roberto
// Tema: Ecommerce voltado para componentes de informática

#include <stdio.h>
#include <string.h>

// registro para armazenar dados dos produtos //
typedef struct produto{
    int cod;
    char nome[20];
    char descr[100];
    char unidade[5];
    char validade;
    char preco_venda;   
} prod;

int cont_prod = -1;

int menu();
void cad_prod(prod *);
void att_estoque(prod *);
void listar_prod(prod *);
void vender(prod *);
//limpeza de buffer//
void lb();

int main(int argc, char **argv){
    int opc;

    //vetor para os produtos cadastrados
    prod p[5];

    do{
        opc = menu();
        switch (opc) {
        case 1:
            cad_prod(p);
            break;
        case 2:
            listar_prod(p);
            break;
        case 3:
            estoque(p);
            break;
        case 4:
            vender(p);
            break;
        case 5:
            printf("Saindo\n");
            break;
            default:
            printf("Escolha outra opcao\n");
            break;

        
        }             
    }

    while(opc != 5);
        return 0;
}

int menu(){
    int opc;
    printf("--------------- MENU ---------------\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Listar Produtos\n");
    printf("3 - Atualizar Estoque\n");
    printf("4 - Ir para venda\n");
    printf("5 - SAIR\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opc);
    setbuf(stdin, NULL);
    printf("\n");

    return(opc);
}

void cad_prod(prod *p) {
    int i;

    cont_prod++;

    for(i-0; i<=cont_prod; i++);

    p[cont_prod].cod = p[i-1].cod + 1;

    printf("\nNome do produto: ");
    fgets(p[cont_prod].nome, strlen(p[cont_prod].nome), stdin);
    lb();
    printf("\ncad_prod Nome: %s", p[cont_prod].nome);

    printf("\nDescricao: ");
    fgets(p[cont_prod].descr, strlen(p[cont_prod].descr), stdin);
    lb();
    printf("\ncad_prod Descr: %s", p[cont_prod].descr);
    
    printf("\nUnidade: ");
    fgets(p[cont_prod].unidade, strlen(p[cont_prod].unidade), stdin);
    lb();
    printf("\nValidade: ");
    fgets(p[cont_prod].validade, strlen(p[cont_prod].validade), stdin);
    lb();
    printf("\nPreco de venda: ");
    scanf(p[cont_prod].preco_venda, strlen(p[cont_prod].preco_venda), stdin);
}

void lb(){
    char p;
    while((p = getchar()) != '\n' && p != EOF)
    printf("\n Pressione ENTER\n");
    
}

void listar_prod(prod *p) {
    int i;
    printf("\ncont_prod: %d\n", cont_prod);
    printf("\n");
    for(i=0; i<=cont_prod; i++)
    //interface da lista//
    printf("Codigo: %d", p[i].cod);
    printf("Nome: %d", p[i].nome);
    printf("Descricao: %d", p[i].descr);
    printf("Unidades: %d", p[i].unidade);
    printf("Validade: %d", p[i].validade);
    printf("Preco: %d", p[i].preco_venda);
    
}

void att_estoque(prod *p){
    //aumentar estoque de produto ou remover produto.//
}

void vender(prod *p){
    //a parte de vendas, onde a pessoa escolherá os produtos, ver preco, descricao, validade e quantidade disponível do produto//
    //depois veremos quantos e quais produtos foram vendidos e o total da compra.//
}