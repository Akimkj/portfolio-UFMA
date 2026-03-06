import java.util.Random;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);

        System.out.print("Tamanho do vetor -> ");
        int tam = scn.nextInt();

        int[] dados = vetor(tam);

        while (true) {
            System.out.println("====================================================");
            System.out.println("         ALGORITMO DE ORDENACAO BUBBLE SORT");
            System.out.println("====================================================");
            System.out.println("0 - encerrar");
            System.out.println("1 - imprimir o vetor");
            System.out.println("2 - ordenar com Bubble");
            System.out.println("3 - ordenar com Insertion");
            System.out.println("4 - ordenar com Selection");
            System.out.println("====================================================");
            System.out.print("\nOpcao -> ");
            int opc = scn.nextInt();

            if (opc == 0) {
                break;
            } else if (opc == 1) {
                for (int i = 0; i < tam; i++) {
                    System.out.println(i + " - " + dados[i]);
                }
            } else if (opc == 2) {
                dados = bubble(dados);
            } else if (opc == 3) {
                dados = insertion(dados);
            } else if (opc == 4) {
                dados = selection(dados);
            }

        }

    }

    /*
    método para criar um vetor aleatorio de tamanho tam
     */
    private static int[] vetor(int tam) {
        Random gerador = new Random();

        int vetor[] = new int[tam];

        for (int i = 0; i < tam; i++) {
            int num = gerador.nextInt(1000);
            vetor[i] = num;
        }

        return vetor;
    }

    /*Ordenação com bubble sort */
    private static int[] bubble(int[] v) {
        long inicio = System.nanoTime();

        boolean trocou = true;

        while (trocou) {
            trocou = false;
            for (int i = 0; i < v.length - 1; i++) {
                if (v[i] > v[i+1]) {
                    int aux = v[i];
                    v[i] = v[i+1];
                    v[i+1] = aux;
                    trocou = true;
                }
            }
        }

        long fim = System.nanoTime();

        System.out.println("Tempo: " + (double) ((fim - inicio) / 1000000));
        return v;
    }

    /*Insertion Sort */
    private static int[] insertion(int[] v) {
        for (int i = 1; i < v.length; i++) {
            int atual = v[i];

            for (int j = i - 1; j >= 0; j--) {
                if (atual > v[j]) {
                    break;
                } else {
                    v[j + 1] = v[j];
                    v[j] = atual;
                }
            }
        }

        return v;
    }

    private static int[] selection(int[] v) {
        int valMenor, idxValMenor;

        for (int i = 0; i < v.length; i++) {
            valMenor = v[i];
            idxValMenor = i;
            for (int j = i + 1; j < v.length; j++) {
                if (v[j] < valMenor) {
                    valMenor = v[j];
                    idxValMenor = j;
                }
            }
            v[idxValMenor] = v[i];
            v[i] = valMenor; 
        }

        return v;
    }
}
