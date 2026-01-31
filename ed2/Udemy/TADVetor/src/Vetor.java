public class Vetor {
    private int tamanho;
    private int vaga; //se refere ao dado de uma posição com espaço vago; 
    private int repete;
    private int minimo, maximo;
    private int[] dados;

    public Vetor(int tamanho, int minimo, int maximo, int vaga, int repete) {
        this.tamanho = tamanho;
        this.minimo = minimo;
        this.maximo = maximo;
        this.vaga = vaga;
        this.repete = repete;

        this.dados = new int[this.tamanho];
        if (this.vaga != 0) {
            for (int i = 0; i < this.tamanho; i++) {
                this.dados[i] = this.vaga;
            }
        }
    }

    public int atribuir(int valor, int posicao) {
        if (!valorValido(valor)) {
            return 1;
        }

        if (!posicaoValida(posicao)) {
            return 2;
        }

        if (!podeRepetir() && localizar(valor) != null) {
            return 4;
        }

        if (this.dados[posicao] == this.vaga) {
            this.dados[posicao] = valor;
            return 0;
        }
        return 3;
    }

    public int alterar(int valor, int posicao) {
        if (!valorValido(valor)) {
            return 1;
        }

        if (!posicaoValida(posicao)) {
            return 2;
        }

        if (this.dados[posicao] == this.vaga) {
            return 3;
        }

        this.dados[posicao] = valor;
        return 0;
    }

    public int remover(int posicao) {
        if (!posicaoValida(posicao)) {
            return 2;
        }
        this.dados[posicao] = this.vaga;
        return 0;
    }

    public int ler(int posicao) {
        if (!posicaoValida(posicao)) {
            return 2;
        }

        System.out.println("Posicao " + posicao + " contem o valor: " + this.dados[posicao]);
        return 0;
    }

    public int inserirNaPrimeira(int valor) {

        if (!valorValido(valor)) {
            return 1;
        }

        int first = -1;
        for (int i = 0; i < this.tamanho; i++) {
            if (this.dados[i] == this.vaga) {
                first = i;
                break;
            }
        }

        if (first == -1) {
             System.out.println("Nao há posicoes vagas no vetor");
             return 3; 
        } else if (!podeRepetir()) {
            return 4;
        } else {
            this.dados[first] = valor;
            System.out.println("Valor inserido na primeira posicao vaga");
            return 0;
        }
    }
    
    public void removerDaUltima() {
        int last = -1;
        for (int i = 0; i < this.tamanho; i++) {
            if (this.dados[i] != this.vaga) {
                last = i;
            }
        }

        if (last == -1) {
             System.out.println("Nao há posicoes ocupadas no vetor");
        } else {
            this.dados[last] = this.vaga;
            System.out.println("Valor removido da ultima posicao ocupada");
        }
    }


    public int[] localizar(int valor) {
        int[] positions;
        int j;
        if (!podeRepetir()) {
            positions = new int[1];
            for (int i = 0; i < this.tamanho; i++) {
                if (this.dados[i] == valor) {
                    positions[0] = i;
                    break;
                }
            }
            return positions;
        }
        else {
            positions = new int[this.tamanho];
            j = 0;
            for (int i = 0; i < this.tamanho; i++) {
                if (this.dados[i] == valor) {
                    positions[j] = i;
                    j++;
                }
            }
            return positions;
        }
    }

    public void limparVetor() {
        for (int i = 0; i < this.tamanho; i++) {
            this.dados[i] = this.vaga;
        }
    }

    public boolean valorValido(int valor) {
        return valor >= this.minimo && valor <= this.maximo;
    }

    public boolean posicaoValida(int posicao) {
        return posicao >= 0 && posicao <= this.tamanho;
    }

    public boolean podeRepetir() {
        return this.repete == 1;
    }

    public int getTamanho() {
        return this.tamanho;
    }
} 
