#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define MAX 50

typedef struct {
    int matricula;
    char nome[100];
    int idade;
    int turma;
} Aluno;

int main(){
    // ==== AJUSTANDO ACENTOS ====
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // ==== DECLARANDO VARIÁVEIS ====
    Aluno cadastro[MAX];
    int total = 0;
    int opcao, busca, posicao, i, existe;

    // ==== EXECUÇÃO =====
    do {
        printf("\n===== SISTEMA DE CADASTRO =====\n");
        printf("1 - Cadastrar\n2 - Consultar\n3 - Listar\n4 - Alterar\n5 - Excluir\n0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                if(total >= MAX){
                    printf("==== LIMITE MÁXIMO DE CADASTROS ATINGIDOS ====\n"); 
                    break;
                } 

                printf("Digite sua matrícula: ");
                scanf("%d", &busca);

                posicao = -1;
                for(i = 0; i < total; i++) {
                    if(cadastro[i].matricula == busca) posicao = i;
                }
                if(posicao != -1){
                    printf("==== JÁ EXISTE UM CADASTRO COM ESSA MATRÍCULA ====\n");
                    break;
                }

                cadastro[total].matricula = busca;

                printf("Digite seu nome: ");
                scanf(" %99[^\n]", cadastro[total].nome);

                printf("Digite sua idade: ");
                scanf("%d", &cadastro[total].idade);

                printf("Digite o número da sua turma: ");
                scanf("%d", &cadastro[total].turma);
                total++;
                printf("==== CADASTRO REALIZADO COM SUCESSO! ====\n");
                break;

            case 2:
                if(total == 0) {
                    printf("==== NÃO HÁ NENHUM CADASTRO FEITO, NÃO HÁ O QUE SER CONSULTADO. ====\n");
                    break;
                }

                printf("Digite sua matrícula: ");
                scanf("%d", &busca);

                posicao = -1;
                for(i = 0; i < total; i++) {
                    if(cadastro[i].matricula == busca) posicao = i;
                }
                if(posicao == -1){
                    printf("==== REGISTRO NÃO ENCONTRADO ====\n");
                } 
                else {
                    printf("\n==== MOSTRANDO DADOS ====\n");
                    printf("Matrícula: %d\nNome: %s\nIdade: %d\nTurma: %d\n",
                        cadastro[posicao].matricula, cadastro[posicao].nome,
                        cadastro[posicao].idade, cadastro[posicao].turma);
                }
                break;
            
            case 3:
                if(total == 0) {
                    printf("==== NENHUM REGISTRO CADASTRADO ====\n");
                    break;
                }

                printf("==== LISTANDO CADASTROS ===\n");
                for(i = 0; i < total; i++){
                    printf("\nMatrícula: %d\nNome: %s\nIdade: %d\nTurma: %d\n",
                            cadastro[i].matricula, cadastro[i].nome,
                            cadastro[i].idade, cadastro[i].turma);
                }
                break;

            case 4:
                int escolha;
                if(total == 0){
                    printf("==== NENHUM REGISTRO CADASTRADO ====\n");
                    break;
                }

                printf("Digite sua matrícula: ");
                scanf("%d", &busca);

                posicao = -1;
                for(i = 0; i < total; i++){
                    if(cadastro[i].matricula == busca) posicao = i;
                }
                if(posicao == -1){
                    printf("==== REGISTRO NÃO ENCONTRADO. ====\n");
                    break;
                }

                printf("Escolha o que deseja alterar:\n1 - Matrícula\n2 - Nome\n3 - Idade\n4 - Turma\n5 - Sair\n");
                printf("Digite sua escolha: ");
                scanf("%d", &escolha);

                switch (escolha) {
                case 1:
                    printf("Digite sua nova matrícula: ");
                    scanf("%d", &busca);

                    existe = 0;

                    for(i = 0; i < total; i++) {
                        if(cadastro[i].matricula == busca){
                            existe = 1;
                            break;
                        }
                    }

                    if(existe) {
                        printf("==== ERRO: ESSA MATRÍCULA JÁ EXISTE. ====\n");
                    }
                    else {
                        cadastro[posicao].matricula = busca;
                        printf("==== MATRÍCULA ALTERADA COM SUCESSO ====\n");
                    }
                    
                    break;

                case 2:
                    printf("Digite seu novo nome: ");
                    scanf(" %99[^\n]", cadastro[posicao].nome);
                    printf("==== NOME ALTERADO COM SUCESSO ====\n");
                    break;

                case 3: 
                    printf("Digite sua nova idade: ");
                    scanf("%d", &cadastro[posicao].idade);
                    printf("==== IDADE ALTERADA COM SUCESSO ====\n");
                    break;

                case 4:
                    printf("Digite sua nova turma: ");
                    scanf("%d", &cadastro[posicao].turma);
                    printf("==== TURMA ALTERADA COM SUCESSO ====\n");
                    break;

                case 5:
                    printf("Saindo do programa...");
                    break;

                default:
                    printf("==== ERRO: SELECIONE APENAS ALGUMA DAS OPÇÕES. ====\n");
                    break;
                }
                break;

            case 5:
                if(total == 0){
                    printf("==== NÃO HÁ CADASTROS A SEREM EXCLUÍDOS. ====\n");
                    break;
                }
            
                printf("Digite a matrícula do cadastro a excluir: ");
                scanf("%d", &busca);

                posicao = -1;
                for(i = 0; i < total; i++){
                    if(cadastro[i].matricula == busca) posicao = i;
                }
                if(posicao == -1){
                    printf("==== NÃO FOI POSSÍVEL EXCLUIR. ====\n");
                    break;
                }

                // ===== AJUSTANDO O ARRAY DE CADASTROS ====
                for(i = posicao; i < total - 1; i++){
                    cadastro[i] = cadastro[i + 1];
                }
                total--;
                printf("==== CADASTRO EXCLUÍDO COM SUCESSO! ====\n");
                break;

            case 0:
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("==== OPÇÃO INVÁLIDA. ====\n");
                break;
        }

    } while(opcao != 0);

    return 0;
}