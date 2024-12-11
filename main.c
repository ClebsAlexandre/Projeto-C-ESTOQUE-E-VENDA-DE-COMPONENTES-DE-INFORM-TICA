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
    char unidade[3];
    char validade[2];
    char preco_venda[4];   
} prod;


int menu();

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
            att_estoque(p);
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
    printf("3 - Atualizar Estoque (INDISPONÍVEL)\n");
    printf("4 - Ir para venda (INDISPONÍVEL)\n");
    printf("5 - SAIR\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opc);
    setbuf(stdin, NULL);
    printf("\n");

    return(opc);
}

void cad_prod(prod *p) {
//refazer cadastro//
}

void listar_prod(prod *p) {
//refazer lista de produtos//
    
}

void att_estoque(prod *p){
    //aumentar estoque de produto ou remover produto.//
}

void vender(prod *p){
    //a parte de vendas, onde a pessoa escolherá os produtos, ver preco, descricao, validade e quantidade disponível do produto//
    //depois veremos quantos e quais produtos foram vendidos e o total da compra.//
}