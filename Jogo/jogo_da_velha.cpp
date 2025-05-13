#include <iostream>
#include <vector>
#include <string>

using namespace std;

class JogoDaVelha {
private:
    vector<vector<char>> tabuleiro;
    char jogadorAtual;
    bool jogoTerminado;

    void inicializarTabuleiro() {
        tabuleiro = vector<vector<char>>(3, vector<char>(3, ' '));
    }

    void alternarJogador() {
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }

    bool movimentoValido(int linha, int coluna) {
        return (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ');
    }

    bool verificarVitoria() {
        // Verificar linhas
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) {
                return true;
            }
        }

        // Verificar colunas
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[0][j] != ' ' && tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j]) {
                return true;
            }
        }

        // Verificar diagonais
        if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
            return true;
        }
        if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
            return true;
        }

        return false;
    }

    bool verificarEmpate() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tabuleiro[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

public:
    JogoDaVelha() {
        inicializarTabuleiro();
        jogadorAtual = 'X';
        jogoTerminado = false;
    }

    void imprimirTabuleiro() {
        cout << "\n  0   1   2\n";
        cout << "0 " << tabuleiro[0][0] << " | " << tabuleiro[0][1] << " | " << tabuleiro[0][2] << "\n";
        cout << " ---+---+---\n";
        cout << "1 " << tabuleiro[1][0] << " | " << tabuleiro[1][1] << " | " << tabuleiro[1][2] << "\n";
        cout << " ---+---+---\n";
        cout << "2 " << tabuleiro[2][0] << " | " << tabuleiro[2][1] << " | " << tabuleiro[2][2] << "\n\n";
    }

    void fazerJogada() {
        int linha, coluna;
        cout << "Jogador " << jogadorAtual << ", digite linha e coluna (0-2): ";
        cin >> linha >> coluna;

        if (movimentoValido(linha, coluna)) {
            tabuleiro[linha][coluna] = jogadorAtual;

            if (verificarVitoria()) {
                imprimirTabuleiro();
                cout << "Jogador " << jogadorAtual << " venceu!\n";
                jogoTerminado = true;
            } else if (verificarEmpate()) {
                imprimirTabuleiro();
                cout << "Empate!\n";
                jogoTerminado = true;
            } else {
                alternarJogador();
            }
        } else {
            cout << "Movimento inválido! Tente novamente.\n";
        }
    }

    bool getJogoTerminado() {
        return jogoTerminado;
    }

    void reiniciarJogo() {
        inicializarTabuleiro();
        jogadorAtual = 'X';
        jogoTerminado = false;
        cout << "Jogo reiniciado!\n";
    }
};

int main() {
    JogoDaVelha jogo;
    char opcao;

    cout << "Bem-vindo ao Jogo da Velha!\n";

    do {
        while (!jogo.getJogoTerminado()) {
            jogo.imprimirTabuleiro();
            jogo.fazerJogada();
        }

        cout << "Deseja jogar novamente? (s/n): ";
        cin >> opcao;

        if (tolower(opcao) == 's') {
            jogo.reiniciarJogo();
        }

    } while (tolower(opcao) == 's');

    cout << "Obrigado por jogar!\n";
    return 0;
}