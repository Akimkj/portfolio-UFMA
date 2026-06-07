public class Tabela_Hash<G> {
    private static class hashNode<G> {
        int codigo;
        char livre; // L = livre, O = ocupado, R = removido
        G dados;

        hashNode() {
            this.livre = 'L';
        }

        hashNode(int codigo, G dados) {
            this.dados = dados;
            this.livre = 'O';
            this.codigo = codigo;
        }
    }
    private int T; //Tamanho da tabela
    private hashNode<G>[] tabela; // Tabela com os Hashs
    private int n; //Quantidade atual de elementos na tabela;
    private final double A = 0.6180339887;

    @SuppressWarnings("unchecked")
    public Tabela_Hash() {
        this.T = 997;
        this.n = 0;
        this.tabela = (hashNode<G>[]) new hashNode[this.T];

        for (int i = 0; i < this.T; i++) {
            tabela[i] = new hashNode<>();
        }
    }

    @SuppressWarnings("unchecked")
    public Tabela_Hash(int tamBase) {
        this.T = tamBase;
        this.n = 0;
        this.tabela = (hashNode<G>[]) new hashNode[this.T];

        for (int i = 0; i < this.T; i++) {
            tabela[i] = new hashNode<>();
        }
    }
    
    /*
    * Método de redimensionamento, responsável por realocar memória em caso do fator de carga estiver igual ou acima de 70%
    */
    @SuppressWarnings("unchecked")
    private void resize() {
        hashNode<G>[] tabelaAntiga = this.tabela;
        int lastT = this.T;
        this.T *= 3;
        this.tabela = (hashNode<G>[]) new hashNode[this.T];
        this.n = 0;

        for (int i = 0; i < this.T; i++) {
            this.tabela[i] = new hashNode<>();
        }

        for (int j = 0; j < lastT; j++) {
            hashNode<G> elem = tabelaAntiga[j];
            if (elem.livre == 'O') {
                insert(elem.codigo, elem.dados);
            }
        }
    }

    /*Método hash pela estratégia da multiplicação que recebe um inteiro como chave*/
    private int hash(int k) {
        if (k < 0) {
            k *= -1;
        }
        double code = this.T * ((k * this.A) % 1);
        return (int) code;
    }

    /*Método de busca que recebe uma chave e retorna os dados do hash encontrado (colisão tratada por sondagem quadrática)*/
    public G search(int key) {
        int i = 1;
        int h = hash(key);

        while (tabela[h].codigo != key && tabela[h].livre != 'L') {
            if (i >= this.T) {
                return null;
            }
            h = (hash(key) + (i * i)) % this.T;
            i++;
        }

        if (tabela[h].codigo == key && tabela[h].livre == 'O') {
            return tabela[h].dados;
        }
        return null;
    }

    /*Método de inserção que recebe uma chave e um dado Generic e retorna um booleano indicando o sucesso ou a falha da inserção (colisão tratada por sondagem quadratica)*/
    public boolean insert(int key, G data) {
        int i = 1;
        int h = hash(key);
        hashNode<G> newnode = new hashNode<>(key,data);
        
        while (tabela[h].livre == 'O' && i < this.T) {
            if (tabela[h].codigo == key) {
                return false;
            }
            h = (hash(key) + (i * i)) % this.T;
            i++;
        }

        if (i < this.T && tabela[h].livre != 'O') {
            tabela[h] = newnode;
            this.n++;
            double fatorCarga = (double) this.n / this.T;
            if (fatorCarga >= 0.7) {
                resize();
            }

            return true;
        }
        return false;
    }

    /*Método de remoção que recebe uma chave e remove o elemento da tabela, retorna os dados do hash encontrado (colisão tratada por sondagem quadrática)*/
    public G remove(int key) {
        int h = hash(key);
        int i = 1;

        while (tabela[h].codigo != key && tabela[h].livre != 'L') {
            if (i >= this.T) {
                return null;
            }
            h = (hash(key) + (i * i)) % this.T;
            i++;
        }
        
        if (tabela[h].codigo == key && tabela[h].livre == 'O') {
            this.n--;
            tabela[h].livre = 'R';
            return tabela[h].dados;
        }
        return null;
    }

    /*Método que retorna um array com todas as chaves registradas na tabela Hash*/
    public int[] entrySet() {
        int[] chaves = new int[this.n];
        int j = 0;
        for (int i = 0; i < this.T; i++) {
            if (this.tabela[i].livre == 'O') {
                chaves[j] = tabela[i].codigo;
                j++;
            }
        }
        return chaves;
    }
}
