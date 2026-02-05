import java.util.ArrayList;
import java.util.Scanner;

/**
 * Classe representativa da estrutura de dados PILHA.
 * <br>Funcionalidades minimalistas - vide javadoc.
 *
 * @author Marcio Porto Feitosa - 23/09/2022 - 10:44:12
 */
public class TadPilhaJava {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        System.out.println("--------------------------------------------");
        System.out.println("PROGRAMA PARA ESTUDO DO TAD PILHA - VERSÃO 1");
        System.out.println("--------------------------------------------");
        System.out.println("");
        System.out.print("Tamanho maximo da pilha: ");
        int qtd = scn.nextInt();
        System.out.print("Pode repetir elementos?(0 para nao/1 para sim): ");
        int repetir = scn.nextInt();

        Stack pilha = new Stack(qtd, repetir);

        while (true) {
            System.out.println("\n\n--------------------------------------------");
            System.out.println("PROGRAMA PARA ESTUDO DO TAD PILHA - VERSÃO 1");
            System.out.println("      Conteudo: numeros inteiros");
            System.out.println("      Capacidade:" + qtd + " elementos");
            System.out.println("--------------------------------------------");
            System.out.println("");
            System.out.println("0 - Encerrar");
            System.out.println("1 - Inserir um elemento");
            System.out.println("2 - Extrair um elemento");
            System.out.println("3 - Imprimir a pilha");
            System.out.println("4 - Informar a quantidade de elementos da pilha.");
            System.out.println("5 - Informar a posição do topo.");
            System.out.println("6 - Localizar um elemento e retornar sua posição.");
            System.out.println("");

            System.out.println("Opcao: ");
            int opc = scn.nextInt();

            if (opc == 0) {
                break;
            } else if (opc == 1) {
                Scanner scn1 = new Scanner(System.in);
                System.out.print("Valor do elemento a inserir: ");
                int opc1 = scn1.nextInt();
                
                if (pilha.push(opc1)) {
                    System.out.println("Insercao bem sucedida.");
                } else {
                    System.out.println("Insercao falhou!!");
                }
                
            }
            else if (opc == 2){
                Integer value = pilha.pop();
                if (value != null){
                    System.out.println("Extracao bem sucedida. Valor do elemento = " + value);
                }
                else{
                    System.out.println("Extracao falhou.");
                }
            }
            else if (opc == 3){
                System.out.println("");
                pilha.print();
            } else if (opc == 4) {
                System.out.println("A quantidade atual de elementos na pilha é: " + pilha.getQuant());
            } else if (opc == 5) {
                System.out.println("A posicao do topo é " + pilha.getTop());
            } else if (opc == 6) {
                System.out.println("Informe o elemento que deseja procurar: ");
                int elemento = scn.nextInt();
                ArrayList<Integer> posicoes = pilha.getPosSpec(elemento);
                System.out.println("Posicão(s) do elemento: ");
                for (int i = 0; i < posicoes.size(); i++) {
                    System.out.println(posicoes.get(i));
                }
            } else {
                System.out.println("Opcao invalida");
            }

        }

    }

}
