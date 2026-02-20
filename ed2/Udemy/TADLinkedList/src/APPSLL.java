/**
 * As alteracoes no codigo para atender ao exercicio 1 estao com comentarios iniciados por "Ex1".
 */
import java.util.Scanner;

/**
 * classe TadL1LJava_Exercicio1
 *
 * @author Marcio Porto Feitosa - 23/12/2022 - 10:48:35
 */
public class APPSLL {

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        LinkedList<Elemento> ll = new LinkedList<>();

        while (true) {

            System.out.println("\n\n================================================");
            System.out.println("             LISTA LIGADA TIPO II");
            System.out.println("          (operacao em modo TAD Fila)");
            System.out.println("       Quantidade de elementos na fila -> " + ll.size());  // Ex1
            System.out.println("================================================");
            System.out.println("0 - encerrar");
            System.out.println("1 - inserir elemento (no final)");
            System.out.println("2 - extrair elemento (do inicio)");
            System.out.println("3 - imprimir elementos da lista (sentido inicio -> fim)");
            System.out.println("4 - localizar um elemento dado seu numero (primeira ocorrencia)");  // Ex1
            System.out.println("5 - inserir um elemento em determinada posicao");  // Ex1
            System.out.println("6 - remover um elemento de determinada posicao");  // Ex1
            System.out.println("");
            System.out.print("Opcao -> ");

            int opc;
            try {
                opc = scn.nextInt();
            } catch (Exception ex) {
                System.out.println("ERRO: Opcao invalida.");
                scn.next();
                continue;
            }

            if (opc == 0) {
                break;
            } else if (opc == 1) {

                Elemento e = criaElem();

                if (ll.addLast(e)) {
                    System.out.println("Elemento inserido com sucesso!!");
                } else {
                    System.out.println("*** Falha na insercao do elemento!! ***");
                }
            } else if (opc == 2) {
                Elemento e = ll.removeFirst();
                if (e == null) {
                    System.out.println("A Lista esta' vazia!!");
                } else {
                    System.out.println("O elemento foi removido da fila com sucesso.");
                    System.out.print("\nNome ---> " + e.getNome());
                    System.out.print("\nNumero -> " + e.getNumero());
                }
            } else if (opc == 3) {
                System.out.println("Elementos da fila:");
                System.out.println("--------------------------------------------");
                if (ll.isEmpty()) {
                    System.out.println("A fila esta' vazia.");
                } else {
                    Elemento e = ll.getFirst();
                    int pos = 0;
                    while (e != null) {
                        System.out.println(e.getNumero() + " | " + e.getNome());
                        pos++;
                        e = ll.get(pos);
                    }
                }

            } else if (opc == 4) {  // Ex1

                //= verificar se a lista esta' vazia
                if (ll.isEmpty()) {
                    System.out.println("A fila esta' vazia.");
                    continue;
                }

                //= solicitar numero do elemento a ser localizado
                System.out.print("Informe o numero do elemento -> ");

                int n;
                try {
                    n = scn.nextInt();
                } catch (Exception ex) {
                    System.out.println("ERRO: Numero invalido.");
                    continue;
                }

                Elemento e = ll.getFirst();  // ponteiro para o elemento inicial
                int pos = 0;  // indica a posicao em que estamos na lista
                boolean loc = false;

                while (e != null) {
                    pos++;
                    if (e.getNumero() == n) {
                        System.out.println("Localizado elemento na posicao " + pos);
                        printElem(e);
                        loc = true;
                        break;
                    }
                    e = ll.get(pos);
                }

                if (!loc) {
                    System.out.println("Elemento nao encontrado.");
                }

            } else if (opc == 5) {  // Ex1
                System.out.println("A maior posicao possivel e' " + (ll.size()));

                //= solicitar a posicao a inserir
                System.out.print("Informe a posicao que o elemento ira' ocupar -> ");

                int pos;
                try {
                    pos = scn.nextInt();
                } catch (Exception ex) {
                    System.out.println("ERRO: Numero invalido.");
                    continue;
                }

                if (pos > ll.size()) {
                    System.out.println("Nao e' possivel inserir nesta posicao.");
                    continue;
                }

                Elemento e = criaElem();

                if (ll.add(e, pos)) {
                    System.out.println("Inclusao bem sucedida.");
                } else {
                    System.out.println("ERRO: Falha na inclusao.");
                }
            } else if (opc == 6) {  // Ex1
                System.out.println("A maior posicao possivel e' " + (ll.size() - 1));

                //= solicitar a posicao a inserir
                System.out.print("Informe a posicao que o elemento ira' remover -> ");

                int pos;
                try {
                    pos = scn.nextInt();
                } catch (Exception ex) {
                    System.out.println("ERRO: Numero invalido.");
                    continue;
                }

                if (pos >= ll.size()) {
                    System.out.println("Nao e' possivel remover nesta posicao.");
                    continue;
                }

                Elemento e = ll.remove(pos);

                if (e != null) {
                    System.out.println("Remocao bem sucedida:");
                    System.out.print("\nNome ---> " + e.getNome());
                    System.out.print("\nNumero -> " + e.getNumero());
                } else {
                    System.out.println("ERRO: Falha na Remocao.");
                }
            }
        }

    }

    private static void printElem(Elemento e) {  // Ex1
        System.out.print("\nNumero -> " + e.getNumero());
        System.out.print("\nNome ---> " + e.getNome());
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

}
