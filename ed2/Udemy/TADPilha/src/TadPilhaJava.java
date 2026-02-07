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

        Stack<Integer> pilha = new Stack<>();

        while (true) {
            System.out.println("\n\n--------------------------------------------");
            System.out.println("PROGRAMA PARA ESTUDO DO TAD PILHA - VERSÃO 1");
            System.out.println("      Conteudo: Integer");
            System.out.println("--------------------------------------------");
            System.out.println("");
            System.out.println("0 - Encerrar");
            System.out.println("1 - Inserir um elemento");
            System.out.println("2 - Extrair um elemento");
            System.out.println("3 - Imprimir a pilha");
            System.out.println("4 - Informar a quantidade de elementos da pilha.");
            System.out.println("");

            System.out.println("Opcao: ");
            int opc = scn.nextInt();

            if (opc == 0) {
                break;
            } else if (opc == 1) {
                Scanner scn1 = new Scanner(System.in);
                System.out.print("Valor do elemento a inserir: ");
                int opc1 = scn1.nextInt();
                
                if (pilha.push(opc1) != null) {
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
                
            } else if (opc == 4) {
                System.out.println("A quantidade de elementos é " + pilha.size());
            } else {
                System.out.println("Opcao invalida");
            }

        }

    }

}
