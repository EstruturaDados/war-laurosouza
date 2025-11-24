// ============================================================================
//                  PROJETO WAR ESTRUTURADO – NÍVEL NOVATO
// ============================================================================
//
// OBJETIVOS (Nível Novato):
// - Criar uma struct Territorio.
// - Armazenar 5 territórios em um vetor estático.
// - Ler Nome, Cor do Exército e Número de Tropas.
// - Exibir o estado atual do mapa após o cadastro.
//
// Este arquivo é uma versão do Nível Novato, baseada no template fornecido
// pelo desafio, mas sem funcionalidades dos níveis Aventureiro e Mestre.
//
// ============================================================================

#include <stdio.h>
#include <string.h>

// ---------------------------------------------------------------------------
// Constantes Globais
// ---------------------------------------------------------------------------
#define MAX_TERRITORIOS 5
#define MAX_NOME 30
#define MAX_COR 10

// ---------------------------------------------------------------------------
// Estrutura de Dados
// Representa um território do jogo WAR com nome, cor do exército e tropas.
// ---------------------------------------------------------------------------
typedef struct {
    char nome[MAX_NOME];
    char cor[MAX_COR];
    int tropas;
} Territorio;

// ---------------------------------------------------------------------------
// Protótipos das Funções (Nível Novato)
// ---------------------------------------------------------------------------
void cadastrarTerritorios(Territorio mapa[]);
void exibirMapa(const Territorio mapa[]);
void limparBufferEntrada();

// ============================================================================
// Função Principal (main)
// ============================================================================

int main() {

    Territorio mapa[MAX_TERRITORIOS];   // Vetor estático com 5 territórios

    printf("=====================================================\n");
    printf("         PROJETO WAR – NIVEL NOVATO\n");
    printf("=====================================================\n");

    // 1) Cadastro dos Territórios
    cadastrarTerritorios(mapa);

    // 2) Exibição do Mapa cadastrado
    exibirMapa(mapa);

    printf("\nCadastro concluído! Programa finalizado.\n");
    return 0;
}

// ============================================================================
// Implementação das Funções
// ============================================================================

// ---------------------------------------------------------------------------
// cadastrarTerritorios()
// Lê os dados dos 5 territórios usando scanf e strings.
// Modifica diretamente o vetor passado por referência (Nível Novato).
// ---------------------------------------------------------------------------
void cadastrarTerritorios(Territorio mapa[]) {
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("\n--- Cadastro do Território %d ---\n", i + 1);

        printf("Nome do território: ");
        scanf(" %[^\n]", mapa[i].nome);
        limparBufferEntrada();

        printf("Cor do exército: ");
        scanf(" %[^\n]", mapa[i].cor);
        limparBufferEntrada();

        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
        limparBufferEntrada();
    }
}

// ---------------------------------------------------------------------------
// exibirMapa()
// Exibe todos os territórios cadastrados.
// Usa const para garantir que nenhum dado seja modificado (Nível Novato).
// ---------------------------------------------------------------------------
void exibirMapa(const Territorio mapa[]) {
    printf("\n=====================================================\n");
    printf("                ESTADO ATUAL DO MAPA\n");
    printf("=====================================================\n");

    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("\n--- Território %d ---\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor do Exército: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
    }
}

// ---------------------------------------------------------------------------
// limparBufferEntrada()
// Remove caracteres restantes no buffer stdin para evitar problemas com scanf.
// ---------------------------------------------------------------------------
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
