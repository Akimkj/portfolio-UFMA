import java.util.Scanner;

/**
 * @class TadL1LJava_I
 * @author Marcio Porto Feitosa - 22/12/2022 - 17:30:07
 */
public class AppPL {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        LinkedList<Elemento> ll = new LinkedList<>();

        while (true) {

            System.out.println("================================================");
            System.out.println("             LISTA LIGADA TIPO I");
            System.out.println("================================================");
            System.out.println("0 - encerrar");
            System.out.println("1 - inserir elemento");
            System.out.println("2 - extrair elemento");
            System.out.println("");
            System.out.print("Opcao -> ");
            int opc = scn.nextInt();

            if (opc == 0) {
                break;
            } else if (opc == 1) {
                System.out.print("Nome do elemento -> ");
                String nm = scn.next();
                System.out.print("Numero do elemento -> ");
                int nr = scn.nextInt();
                Elemento e = new Elemento(nm, nr);
                ll.addFirst(e);
                System.out.println("Elemento inserido com sucesso!!");
            }
            else if (opc == 2){
                Elemento e = ll.removeFirst();
                if (e==null){
                    System.out.println("A Lista esta' vazia!!");
                }
                else{
                    System.out.println("O elemento foi removido com sucesso.");
                    System.out.print("\nNome ---> " + e.getNome());
                    System.out.print("\nNumero -> " + e.getNumero());
                }
            }
        }

    }

}
