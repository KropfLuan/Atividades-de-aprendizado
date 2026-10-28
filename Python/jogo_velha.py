import tkinter as tk

TAMANHO = 3
VAZIO = ""
JOGADORES = ["X", "O"]
CORES = {"X": "#d62728", "O": "#1f77b4"}
COR_DESTAQUE = "#b7e4c7"


def todas_as_linhas():
    """Lista todas as sequências que dão vitória, como listas de (linha, coluna)."""
    ultimo = TAMANHO - 1
    linhas = [[(l, c) for c in range(TAMANHO)] for l in range(TAMANHO)]
    colunas = [[(l, c) for l in range(TAMANHO)] for c in range(TAMANHO)]
    diag_principal = [[(i, i) for i in range(TAMANHO)]]
    diag_secundaria = [[(i, ultimo - i) for i in range(TAMANHO)]]
    return linhas + colunas + diag_principal + diag_secundaria


def linha_vencedora(tabuleiro, peca):
    """Retorna as casas da sequência vencedora de 'peca', ou None se não houver."""
    for sequencia in todas_as_linhas():
        if all(tabuleiro[l][c] == peca for l, c in sequencia):
            return sequencia
    return None


def deu_velha(tabuleiro):
    return all(c != VAZIO for fileira in tabuleiro for c in fileira)


class JogoDaVelha:
    def __init__(self, janela):
        self.janela = janela
        janela.title("Jogo da Velha")
        janela.resizable(False, False)

        self.status = tk.Label(janela, font=("Helvetica", 16), pady=10)
        self.status.pack()

        moldura = tk.Frame(janela, padx=10)
        moldura.pack()

        self.botoes = []
        for l in range(TAMANHO):
            fileira = []
            for c in range(TAMANHO):
                botao = tk.Button(
                    moldura,
                    text=VAZIO,
                    width=4,
                    height=2,
                    font=("Helvetica", 32, "bold"),
                    command=lambda l=l, c=c: self.jogar(l, c),
                )
                botao.grid(row=l, column=c, padx=2, pady=2)
                fileira.append(botao)
            self.botoes.append(fileira)

        # Cor de fundo padrão do sistema (varia entre Windows, macOS e Linux)
        self.cor_padrao = self.botoes[0][0].cget("bg")

        tk.Button(
            janela, text="Reiniciar", font=("Helvetica", 14), command=self.reiniciar
        ).pack(pady=10)

        self.reiniciar()

    def reiniciar(self):
        self.tabuleiro = [[VAZIO] * TAMANHO for _ in range(TAMANHO)]
        self.turno = 0
        self.fim = False
        for fileira in self.botoes:
            for botao in fileira:
                botao.config(text=VAZIO, state="normal", bg=self.cor_padrao)
        self.atualizar_status()

    def atualizar_status(self):
        self.status.config(text=f"Vez de {JOGADORES[self.turno % 2]}")

    def jogar(self, l, c):
        if self.fim or self.tabuleiro[l][c] != VAZIO:
            return

        jogador = JOGADORES[self.turno % 2]
        self.tabuleiro[l][c] = jogador
        self.botoes[l][c].config(text=jogador, fg=CORES[jogador], state="disabled",
                                 disabledforeground=CORES[jogador])

        sequencia = linha_vencedora(self.tabuleiro, jogador)
        if sequencia:
            for sl, sc in sequencia:
                self.botoes[sl][sc].config(bg=COR_DESTAQUE)
            self.encerrar(f"O jogador {jogador} venceu!")
        elif deu_velha(self.tabuleiro):
            self.encerrar("Deu velha! Empate.")
        else:
            self.turno += 1
            self.atualizar_status()

    def encerrar(self, mensagem):
        self.fim = True
        self.status.config(text=mensagem)
        for fileira in self.botoes:
            for botao in fileira:
                botao.config(state="disabled")


if __name__ == "__main__":
    janela = tk.Tk()
    JogoDaVelha(janela)
    janela.mainloop()