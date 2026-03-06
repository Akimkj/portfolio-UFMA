
import java.util.Scanner;

/**
 * classe AG_Java
 *
 * @author Marcio Porto Feitosa - 27/06/2023 - 18:38:19
 */
public class AGjava {

//    static Arvore arvore;
    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        //======================================================================
        //                        INSTANCIAR ARVORE
        //======================================================================
        NariaTree<Elemento2> arvore = new NariaTree<>();
        //----------------------------------------------------------------------

        while (true) {

            System.out.println("\n\n");
            System.out.println("===========================================================");
            System.out.println("  A R V O R E   D E   E S T R U T U R A   G E N E R I C A");
            System.out.println("===========================================================");
            System.out.println("0 - sair");
            System.out.println("1 - inserir elemento");
            System.out.println("2 - localizar elemento");
            System.out.println("3 - imprimir a arvore");
            System.out.println("-----------------------------------------------------------");
            System.out.print("Opcao -> ");

            int opc = scn.nextInt();

            if (opc == 0) {
                break;
            } else if (opc == 1) {
                Scanner scn1 = new Scanner(System.in);
                System.out.print("Informe o codigo do elemento pai -> ");
                String codigoPai = scn1.nextLine();
                Elemento2 e = criaElem();
                if (arvore.add(codigoPai, e.getCodigo(),e)) {
                    System.out.println("Inclusao bem sucedida");
                } else {
                    System.out.println("### INCLUSAO FALHOU ###");
                }

            } else if (opc == 2) {
                Scanner scn2 = new Scanner(System.in);
                System.out.print("Informe o codigo do elemento procurado -> ");
                String codigo = scn2.nextLine();
                Elemento2 e = arvore.search(codigo);
                System.out.println(e.getCodigo() + " | " + e.getNome());
            } else if (opc == 3) {
                arvore.display();
            }

        }

    }

    private static Elemento2 criaElem() {
        Scanner scn = new Scanner(System.in);
        System.out.println("--- NOVO ELEMENTO ---");
        System.out.print("Codigo -> ");
        String codigo = scn.nextLine();
        System.out.print("Nome -> ");
        String nome = scn.nextLine();
        System.out.print("Descricao -> ");
        String descr = scn.nextLine();

        return new Elemento2(codigo, nome, descr);
    }


}
