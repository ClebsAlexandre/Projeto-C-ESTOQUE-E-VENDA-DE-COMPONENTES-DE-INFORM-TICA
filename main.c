// Projeto Final 
// Professor: Mayrton
// Grupo: Clebson  Alexandre, Sergio Roberto
// Tema: Sistema de Estoque e Venda para Componentes de Informática

#include <stdio.h>
#include <string.h>

// Define uma estrutura para armazenar as informações de cada componente
struct Comp {
    char nome[50];      // Nome do componente
    char marca[30];     // Marca do componente 
    int codigo;         // Código do componente
    int garantia;        // Garantia do componente em meses
    float preco;        // Preço do componente
    char descricao[100]; // Descrição do componente
    char tipo[20];      // Tipo do componente
    char notaFiscal[20]; // Número da nota fiscal
    int quantidade;     // Quantidade em estoque do componente
    int qtdVendida;    // Quantidade do componente já vendida
};

// Protótipos das funções
int menu();
void cad_comp(struct Comp *);
void listar_comp(struct Comp *);
void att_estoque(struct Comp *);
void remover_comp(struct Comp *);
void buscar_comp(struct Comp *);
void vender(struct Comp *);
void gerar_relatorio_vendas(struct Comp *);
void salvar_dados(struct Comp *);
void carregar_dados(struct Comp *);

int cont_comp = -1; // Variável que controla quantos componentes foram cadastrados

// Função principal do programa
int main() {
    int opc;                // Variável para armazenar a opção escolhida pelo usuário no menu
    struct Comp comp[5];  // Cria um vetor chamado "comp" para armazenar até 5 componentes

    carregar_dados(comp); // Carrega os dados dos componentes do arquivo (se existir)

    // Loop principal do programa, repete até que o usuário escolha a opção "SAIR" (8)
    do {
        opc = menu(); // Chama a função "menu" para exibir as opções e ler a escolha do usuário

        // Estrutura switch para executar a opção escolhida pelo usuário
        switch (opc) {
            case 1:
                cad_comp(&comp[cont_comp + 1]); // Cadastra um novo componente
                break;
            case 2:
                listar_comp(comp);            // Lista os componentes cadastrados
                break;
            case 3:
                att_estoque(comp);           // Atualiza a quantidade em estoque de um componente
                break;
            case 4:
                remover_comp(comp);          // Remove um componente
                break; 
            case 5:
                buscar_comp(comp);           // Busca um componente pelo código
                break; 
            case 6:
                vender(comp);                // Vende um componente
                break; 
            case 7: 
                gerar_relatorio_vendas(comp); // Gera um relatório de vendas
                break; 
            case 8:
                salvar_dados(comp);           // Salva os dados dos componentes em um arquivo
                printf("Saindo...\n");          // Exibe a mensagem "Saindo..."
                break; 
            default:
                printf("Escolha uma Opcao valida!\n"); // Exibe uma mensagem de erro caso a opção seja inválida
        }
    } while (opc != 8); // Repete o loop enquanto a opção for diferente de 8 (SAIR)

    return 0; 
}

// Função que exibe o menu de opções na tela
int menu() {
    int opc; // Variável para armazenar a opção escolhida pelo usuário
    printf("--------------- MENU DE GERENCIAMENTO E VENDA DE COMPONENTES ---------------\n"
           "1 - Cadastrar componente\n"
           "2 - Listar Componentes\n"
           "3 - Atualizar Estoque\n"
           "4 - Remover Componente\n"
           "5 - Buscar Componente\n"
           "6 - Ir para Venda\n"
           "7 - Gerar Relatorio de Vendas\n"
           "8 - SAIR\n\n"
           "Escolha uma Opcao: ");
    scanf("%d", &opc); // Lê a opção digitada pelo usuário
    return opc; // Retorna a opção escolhida
}


// Função para cadastrar um novo componente
void cad_comp(struct Comp *comp) {
    // Verifica se o limite de componentes foi atingido
    if (cont_comp >= 4) { 
        printf("Limite de componentes atingido.\n");
        return; 
    }

    cont_comp++; // Incrementa o contador de componentes

    // Lê o código do componente
    printf("Codigo do Componente: ");
    scanf("%d", &comp->codigo);

    // Lê o nome do componente
    printf("Nome do Componente: ");
    scanf(" %[^\n]", comp->nome); 

    // Lê a marca do componente
    printf("Marca: ");
    scanf(" %[^\n]", comp->marca);

    // Lê a garantia do componente
    printf("Garantia (em meses): ");
    scanf("%d", &comp->garantia);

    // Lê o preço do componente
    printf("Preco: ");
    scanf("%f", &comp->preco);

    // Lê a descrição do componente
    printf("Descricao: ");
    scanf(" %[^\n]", comp->descricao);

    // Lê o tipo do componente
    printf("Tipo: ");
    scanf(" %[^\n]", comp->tipo);

    // Lê a quantidade em estoque do componente
    printf("Quantidade em estoque: ");
    scanf("%d", &comp->quantidade);

     comp->qtdVendida = 0; // Inicializa a quantidade vendida do componente como 0
}

// Função para listar os componentes cadastrados
void listar_comp(struct Comp *comp) {
    // Verifica se há componentes cadastrados no sistema
    if (cont_comp < 0) {
        printf("Nenhum componente cadastrado.\n");
        return;
    }

    // Percorre o vetor de componentes e exibe os dados de cada um
    for (int i = 0; i <= cont_comp; i++) {
        // Obtém o componente atual do vetor
        struct Comp componente_atual = comp[i]; 

        // Exibe os dados do componente
        printf("\n--- Componente %d ---\n", i + 1);
        printf("Codigo: %d\n", componente_atual.codigo);
        printf("Nome: %s\n", componente_atual.nome);
        printf("Marca: %s\n", componente_atual.marca);
        printf("Garantia: %d meses\n", componente_atual.garantia);
        printf("Preco: R$ %.2f\n", componente_atual.preco);
        printf("Descricao: %s\n", componente_atual.descricao);
        printf("Tipo: %s\n", componente_atual.tipo);
        printf("Quantidade disponivel: %d\n", componente_atual.quantidade);
    }
}

// Função para atualizar a quantidade em estoque de um componente
void att_estoque(struct Comp *comp) {
    // Verifica se há componentes cadastrados
    if (cont_comp < 0) {
        printf("Nenhum componente cadastrado.\n");
        return;
    }

    int codigo, qtd; // Variáveis para armazenar o código do componente e a quantidade a ser adicionada
    printf("Digite o codigo do componente para atualizar o estoque: ");
    scanf("%d", &codigo); 

    // Loop para percorrer o vetor de componentes e encontrar o componente com o código digitado
    for (int i = 0; i <= cont_comp; i++) {
        // Obtém o componente atual do vetor
        struct Comp componente_atual = comp[i]; 

        if (componente_atual.codigo == codigo) { // Se encontrar o componente
            printf("Quantidade atual: %d\n", componente_atual.quantidade); // Exibe a quantidade atual em estoque
            printf("Digite a quantidade para adicionar ao estoque: ");
            scanf("%d", &qtd);              // Lê a quantidade a ser adicionada
            componente_atual.quantidade += qtd;      // Adiciona a quantidade ao estoque

            // Exibe a nova quantidade em estoque
            printf("Estoque atualizado. Nova quantidade: %d\n", componente_atual.quantidade); 
            comp[i].quantidade = componente_atual.quantidade; // Atualiza a quantidade no vetor original
            return; 
        }
    }
    printf("Componente nao encontrado.\n"); // Se o componente não for encontrado, exibe uma mensagem
}

// Função para remover um componente do vetor
void remover_comp(struct Comp *comp) {
    if (cont_comp < 0) { // Verifica se há componentes cadastrados
        printf("Nenhum componente para remover.\n");
        return;
    }

    int codigo, i, j; // Variáveis para armazenar o código do componente e os índices do loop
    printf("Digite o codigo do componente a ser removido: ");
    scanf("%d", &codigo); 

    // Loop para percorrer o vetor de componentes e encontrar o componente com o código digitado
    for (i = 0; i <= cont_comp; i++) {
        if (comp[i].codigo == codigo) { 
            printf("Componente '%s' removido.\n", comp[i].nome); // Exibe uma mensagem informando que o componente foi removido

            // Loop para "deslocar" os componentes seguintes para trás no vetor, sobrescrevendo o componente removido
            for (j = i; j < cont_comp; j++) {
                comp[j] = comp[j + 1]; 
            }
            cont_comp--; // atualiza o contador de componentes
            return;
        }
    }
    printf("Componente nao encontrado.\n"); // Se o componente não for encontrado, exibe uma mensagem
}

// Função para buscar um componente pelo código
void buscar_comp(struct Comp *comp) {
    if (cont_comp < 0) { // Verifica se há componentes cadastrados
        printf("Nenhum componente cadastrado.\n");
        return; 
    }

    int codigo; // Variável para armazenar o código do componente
    printf("Digite o codigo do componente a buscar: ");
    scanf("%d", &codigo);

    // Loop para percorrer o vetor de componentes e encontrar o componente com o código digitado
    for (int i = 0; i <= cont_comp; i++) {
        // Obtém o componente atual do vetor
        struct Comp componente_atual = comp[i]; 

        if (componente_atual.codigo == codigo) { 
            // Exibe as informações do componente
            printf("\n--- Componente Encontrado ---\n"); 
            printf("Codigo: %d\n", componente_atual.codigo);
            printf("Nome: %s\n", componente_atual.nome);
            printf("Marca: %s\n", componente_atual.marca);
            printf("Descricao: %s\n", componente_atual.descricao);
            printf("Preco: R$ %.2f\n", componente_atual.preco);
            printf("Quantidade disponivel: %d\n", componente_atual.quantidade);
            return;
        }
    }
    printf("Componente nao encontrado.\n"); // Se o componente não for encontrado, exibe uma mensagem
}

// Função para registrar a venda de um componente
void vender(struct Comp *comp) {
    if (cont_comp < 0) { // Verifica se há componentes cadastrados
        printf("Nenhum componente disponivel para venda.\n");
        return; 
    }

    int codigo, quantidade_venda; // Variáveis para armazenar o código do componente e a quantidade vendida
    printf("Digite o codigo do componente que deseja vender: ");
    scanf("%d", &codigo); 

    // Loop para percorrer o vetor de componentes e encontrar o componente com o código digitado
    for (int i = 0; i <= cont_comp; i++) {
        // Obtém o componente atual do vetor
        struct Comp componente_atual = comp[i]; 

        if (componente_atual.codigo == codigo) { 
            printf("Quantidade disponivel: %d\n", componente_atual.quantidade); 
            printf("Digite a quantidade para venda: ");
            scanf("%d", &quantidade_venda); // Lê a quantidade a ser vendida

            if (quantidade_venda > componente_atual.quantidade) { // Verifica se há quantidade suficiente em estoque
                printf("Quantidade insuficiente em estoque.\n");
                return; 
            }

            componente_atual.quantidade -= quantidade_venda;  // Atualiza o estoque após a venda
            componente_atual.qtdVendida += quantidade_venda; //  Adiciona a quantidade vendida à quantidade total vendida do componente

            printf("Venda realizada com sucesso!\n");
            printf("Emitindo nota fiscal...\n");

            strcpy(componente_atual.notaFiscal, "NF-0001"); // Exibe o numero da nota fiscal

            // Exibe a nota fiscal
            printf("\n--- Nota Fiscal ---\n");
            printf("Nota Fiscal: %s\n", componente_atual.notaFiscal);
            printf("Componente: %s\n", componente_atual.nome);
            printf("Marca: %s\n", componente_atual.marca);
            printf("Quantidade Vendida: %d\n", quantidade_venda);
            printf("Valor Total: R$ %.2f\n", quantidade_venda * componente_atual.preco);
            printf("--------------------\n");

            // Atualiza o componente no vetor original
            comp[i] = componente_atual; 
            return; 
        }
    }
    printf("Componente nao encontrado.\n"); // Se o componente não for encontrado, exibe uma mensagem
}

// Função para gerar um relatório de vendas
void gerar_relatorio_vendas(struct Comp *comp) {
    if (cont_comp < 0) { // Verifica se há componentes cadastrados
        printf("Nenhum componente cadastrado.\n");
        return; 
    }

    printf("\n--- Relatorio de Vendas ---\n");

    // Loop para percorrer o vetor de componentes e exibir o relatório de vendas dos componentes vendidos
    for (int i = 0; i <= cont_comp; i++) {
        // Obtém o componente atual do vetor
        struct Comp componente_atual = comp[i]; 

        if (componente_atual.qtdVendida > 0) { 
            printf("Componente: %s\n", componente_atual.nome);          
            printf("Marca: %s\n", componente_atual.marca);            
            printf("Quantidade Vendida: %d\n", componente_atual.qtdVendida); 
            printf("Valor Total: R$ %.2f\n", componente_atual.qtdVendida * componente_atual.preco); 
            printf("--------------------\n");
        }
    }
}

// Função para salvar os dados dos componentes em um arquivo
void salvar_dados(struct Comp *comp) {
    FILE *arquivo = fopen("componentes.txt", "w"); // Abre o arquivo "componentes.txt" em modo de escrita
    if (arquivo == NULL) {                         // Verifica se o arquivo foi aberto corretamente
        printf("Erro ao abrir o arquivo.\n");      
        return; 
    }

    // Loop para percorrer o vetor de componentes e salvar os dados de cada um no arquivo
   for (int i = 0; i <= cont_comp; i++) {
        fprintf(arquivo, "%d,%s,%s,%d,%.2f,%s,%s,%d,%d\n", // Escreve os dados no arquivo, separados por vírgula
                comp[i].codigo, 
                comp[i].nome, 
                comp[i].marca, 
                comp[i].garantia,
                comp[i].preco, 
                comp[i].descricao, 
                comp[i].tipo, 
                comp[i].quantidade,
                comp[i].qtdVendida);
    }

    fclose(arquivo); // Fecha o arquivo          
    printf("Dados salvos com sucesso!\n"); // Exibe uma mensagem de sucesso
}

// Função para carregar os dados dos componentes de um arquivo
void carregar_dados(struct Comp *comp) {
    FILE *arquivo = fopen("componentes.txt", "r"); // Abre o arquivo "componentes.txt" em modo de leitura 
    if (arquivo == NULL) {                         // Verifica se o arquivo foi aberto corretamente
        printf("Erro ao abrir o arquivo ou arquivo nao existe.\n"); 
        return; 
    }

    // Loop para ler os dados do arquivo e armazená-los no vetor de componentes
    for (cont_comp = -1; 
         fscanf(arquivo, "%d,%[^,],%[^,],%d,%f,%[^,],%[^,],%d,%d\n", 
                &comp[cont_comp + 1].codigo, 
                comp[cont_comp + 1].nome, 
                comp[cont_comp + 1].marca, 
                &comp[cont_comp + 1].garantia,
                &comp[cont_comp + 1].preco, 
                comp[cont_comp + 1].descricao, 
                comp[cont_comp + 1].tipo, 
                &comp[cont_comp + 1].quantidade,
                &comp[cont_comp + 1].qtdVendida) == 9 
         && cont_comp < 4; 
         cont_comp++); 

    fclose(arquivo); // Fecha o arquivo
    printf("Dados carregados com sucesso!\n"); // Exibe uma mensagem de sucesso
}
