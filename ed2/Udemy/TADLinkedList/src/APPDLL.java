
/**
 * As alteracoes no codigo para atender ao exercicio 1 estao com comentarios iniciados por "Ex1".
 */
import java.util.Scanner;

/**
 * classe TadL1LJava_Exercicio1
 *
 * @author Marcio Porto Feitosa - 23/12/2022 - 10:48:35
 */
public class APPDLL {

    static LinkedList<Elemento> ll;
    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        ll = new LinkedList<>();

        while (true) {

            System.out.println("\n\n================================================");
            System.out.println("             LISTA DUPLAMENTE LIGADA");
            System.out.println("       Quantidade de elementos na lista -> " + ll.size());  // Ex1
            System.out.println("================================================");
            System.out.println(" 0 - encerrar");
            System.out.println(" 1 - inserir elemento no inicio");
            System.out.println(" 2 - inserir elemento no final");
            System.out.println(" 3 - extrair elemento do inicio");
            System.out.println(" 4 - extrair elemento do final");
            System.out.println(" 5 - imprimir elementos da lista (sentido inicio -> fim)");
            System.out.println(" 6 - imprimir elementos da lista (sentido fim -> inicio");
            System.out.println(" 7 - retornar elemento de uma determinada posicao (sentido inicio -> fim)");
            System.out.println(" 8 - retornar elemento de uma determinada posicao (sentido fim -> inicio)");
            System.out.println(" 9 - localizar a primeira ocorrencia um elemento dado seu numero (sentido inicio -> fim)");
            System.out.println("10 - localizar a primeira ocorrencia um elemento dado seu numero (sentido fim -> inicio)");
            System.out.println("11 - inserir um elemento em determinada posicao (sentido inicio -> fim)");
            System.out.println("12 - inserir um elemento em determinada posicao (sentido fim -> inicio)");
            System.out.println("13 - remover um elemento de determinada posicao (sentido inicio -> fim)");
            System.out.println("14 - remover um elemento de determinada posicao (sentido fim -> inicio)");

            System.out.println("98 - inicializa a lista com algum elementos");
            System.out.println("99 - destroi a lista");

            System.out.println("");
            System.out.print("Opcao -> ");

            int opc = -1;
            try {
                if (scn.hasNextInt()) { // Verifica SE existe um inteiro antes de tentar ler
                    opc = scn.nextInt();
                } else {
                    System.out.println("ERRO: Digite apenas números.");
                    scn.next(); // Limpa o que quer que tenha sido digitado (texto)
                }
            } catch (Exception ex) {
                System.out.println("ERRO inesperado.");
                if (scn.hasNext()) scn.next(); // Limpa com segurança
            }

            if (opc == 0) {
                break;
            } else if (opc == 1) {  //* insere no inicio

                Elemento e = criaElem();
                ll.addFirst(e);
                System.out.println("Elemento inserido no inicio com sucesso!!");

            } else if (opc == 2) {  //* insere no final

                Elemento e = criaElem();
                ll.addLast(e);
                System.out.println("Elemento inserido no final com sucesso!!");

            } else if (opc == 3) {  //* remove do inicio
                if (ll.isEmpty()) {
                    continue;
                }
                Elemento e = ll.removeFirst();
                System.out.println("Elemento removido do inicio com sucesso.");
                printElem(e);
            } else if (opc == 4) {  //* remove do final
                if (ll.isEmpty()) {
                    continue;
                }
                Elemento e = ll.removeLast();
                System.out.println("Elemento removido do final com sucesso.");
                printElem(e);
            } else if (opc == 5) {
                System.out.println("Elementos da lista:");
                System.out.println("--------------------------------------------");
                if (ll.isEmpty()) {
                    System.out.println("A lista esta' vazia.");
                } else {
                    Elemento e = ll.getFirst();
                    int pos = 0;
                    while (e != null) {
                        System.out.println(e.getNumero() + " | " + e.getNome());
                        pos++;
                        e = ll.get(pos);
                    }
                }

            } else if (opc == 6) {
                System.out.println("Elementos da lista:");
                System.out.println("--------------------------------------------");
                if (ll.isEmpty()) {
                    System.out.println("A lista esta' vazia.");
                } else {
                    Elemento e = ll.getLast();
                    int pos = ll.size() - 1;
                    while (e != null) {
                        System.out.println(e.getNumero() + " | " + e.getNome());
                        pos--;
                        e = ll.get(pos);
                    }
                }
            } else if (opc == 7 || opc == 8) {
                Scanner scn7 = new Scanner(System.in);
                System.out.println("A posicao desejada nao pode ser maior que a quantidade de elementos.");
                System.out.print("Informe a posicao -> ");
                int pos = scn7.nextInt();
                Elemento e = ll.get(pos);
                printElem(e);
            } else if (opc == 98) {
                inicializa();
                System.out.println("Lista inicializada com valores na ordem do inicio para o final.");
            } else if (opc == 99) {
                ll.clear();
                System.out.println("A lista foi reinicializada.");
            }

        }
        
    }

    /**
     * Imprime um elemento no formato -> [ numero | nome ]
     *
     * @param e
     */
    private static void printElem(Elemento e) {  // Ex1
        if (e == null) {
            System.out.println("ERRO: Elemento nulo.");
        } else {
            System.out.println(e.getNumero() + " | " + e.getNome());
        }
    }

    private static Elemento criaElem() {  // Ex1

        Scanner scn = new Scanner(System.in);
        String nm;
        int nr;
        while (true) {
            try {

                System.out.print("\n\nNome do elemento -> ");
                nm = scn.next();
                System.out.print("Numero do elemento -> ");
                nr = scn.nextInt();
                break;
            } catch (Exception ex) {
                scn.next();
                System.out.println("ERRO: entrada invalida.");
            }
        }
        
        return new Elemento(nm, nr);
    }

    private static void inicializa() {

        for (int i = 100; i <= 300; i = i + 10) {
            Elemento e = new Elemento("Elemento_" + String.valueOf(i), i);
            ll.addLast(e);
        }

    }

}

