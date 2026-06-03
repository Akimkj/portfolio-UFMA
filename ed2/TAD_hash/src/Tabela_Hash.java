/*
*TAD da Tabela Hash
*A estrutura foi baseada conforme os slides da aulas 9 e 10, além do uso do livro: 
*"estruturas de dados, algoritmos, análise da complexidade e implementações em JAVA e C/C++" de Ana Ascencia e Graziela Araújo.
**/

public class Tabela_Hash<T> {
    public static class hashNode<T> {
        int codigo;
        char livre; // L = livre, O = ocupado, R = removido
        T dados;

        hashNode(int codigo, T dados) {
            this.dados = dados;
            this.livre = 'O';
            this.codigo = codigo;
        }
    }

    private int tam; //tamanho total da tabela
    private hashNode<T>[] tabela; // Tabela com os Hashs
    private int n; //Quantidade atual de elementos na tabela;

    @SuppressWarnings("unchecked")
    public Tabela_Hash() {
        this.tam = 1000;
        this.n = 0;
        this.tabela = (hashNode<T>[]) new Object[tam];
    }

    @SuppressWarnings("unchecked")
    public Tabela_Hash(int tamBase) {
        this.tam = tamBase;
        this.n = 0;
        this.tabela = (hashNode<T>[]) new Object[tam];
    }

}
