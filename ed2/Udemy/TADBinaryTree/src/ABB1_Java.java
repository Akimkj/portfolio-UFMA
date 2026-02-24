
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 * classe ABB1_Java
 *
 * @author Marcio Porto Feitosa - 21/04/2023 - 18:35:46
 */
public class ABB1_Java {

    static BinaryTree<Elemento> abb1;
    public static void main(String[] args) {

        abb1 = new BinaryTree<>();

        Scanner scn = new Scanner(System.in);

        while (true) {

            System.out.println("=======================================================");
            System.out.println("  PROGRAMA PARA ESTUDO DO TAD ARVORE BINARIA DE BUSCA");
            System.out.println("       Quantidade de elementos na arvore -> " + abb1.getQtd());
            System.out.println("=======================================================");
            System.out.println("0 - encerrar");
            System.out.println("1 - inserir no'");
            System.out.println("2 - ler no'");
            System.out.println("3 - excluir no'");
            System.out.println("4 - imprimir em ordem");
            System.out.println("5 - imprimir em pre-ordem");
            System.out.println("6 - imprimir em pos-ordem");
            System.out.println("=======================================================");
            System.out.println("*** OPCOES AUXILIARES ");
            System.out.println("7 - imprimir o no' raiz");
            System.out.println("8 - inserir no' por metodo recursivo.");
            System.out.println("99 - carregar valores (100, 50, 200, 30, 70, 150, 250, 60, 80, 220, 300)");

            System.out.print("\nOpcao -> ");

            int opc = scn.nextByte();

            if (opc == 0) {
                break;
            } else if (opc == 1) {
                Scanner scn1I = new Scanner(System.in);
                System.out.print("Informe o ID do elemento ---> ");
                int id = scn1I.nextInt();
                Scanner scn1S = new Scanner(System.in);
                System.out.print("Informe o nome do elemento -> ");
                String nm = scn1S.next();

                Elemento elem = new Elemento(id, nm);

                if (abb1.addRecursive(elem.getNumero(), elem)) {
                    System.out.println("\nInclusao bem sucedida.");
                } else {
                    System.out.println("\n*** ERRO: Inclusao negada.");
                }

            } else if (opc == 2) {
                Scanner scn2I = new Scanner(System.in);
                System.out.print("Informe o ID do elemento a ser localizado ---> ");
                int id = scn2I.nextInt();
                Elemento e = abb1.search(id);
                if (e == null) {
                    System.out.println("ERRO: nao consta na arvore.");
                } else {
                    System.out.println("\nElemento localizado:");
                    imprimeElem(e);
                }

            } else if (opc == 3) {

                Scanner scn3I = new Scanner(System.in);
                System.out.print("Informe o ID do elemento a ser extraido ---> ");
                int id = scn3I.nextInt();
                Elemento no = abb1.deleteRecursive(id);
                if (no == null) {
                    System.out.println("ERRO: nao consta na arvore.");
                } else {
                    System.out.println("\nElemento extraido:");
                    imprimeElem(no);
                }

            } else if (opc == 4) {
                abb1.simetrico();
            } else if (opc == 5) {
                abb1.preOrdem();
            } else if (opc == 6) {
                abb1.posOrdem();
            }  else if (opc == 7) {
                if (abb1.getQtd() == 0) {
                    System.out.println("*** A arvore esta' vazia ***");
                } else {
                    System.out.print("\nElemento do no' raiz -> ");
                    imprimeElem(abb1.getRaiz());
                }
            } else if (opc == 8) {

                Scanner scn11I = new Scanner(System.in);
                System.out.print("Informe o ID do elemento ---> ");
                int id = scn11I.nextInt();
                Scanner scn11S = new Scanner(System.in);
                System.out.print("Informe o nome do elemento -> ");
                String nm = scn11S.next();

                Elemento elem = new Elemento(id, nm);

                if (abb1.addRecursive(id, elem)) {
                    System.out.println("\nInsercao bem sucedida.");
                } else {
                    System.out.println("\n*** ERRO: insercao falhou (ver. se ja' nao consta este ID na arvore).");
                }

            } else if (opc == 99) {
                carregarDados();
            }

        }

    }

    private static void carregarDados() {

        abb1.addRecursive(100, new Elemento(100, "Cem"));
        abb1.addRecursive(50, new Elemento(50, "Cinquenta"));
        abb1.addRecursive(200, new Elemento(200, "Duzentos"));
        abb1.addRecursive(30, new Elemento(30, "Trinta"));
        abb1.addRecursive(70, new Elemento(70, "Setenta"));
        abb1.addRecursive(150, new Elemento(150, "Cento e Cinquenta"));
        abb1.addRecursive(250, new Elemento(250, "Duzentos e Cinquenta"));
        abb1.addRecursive(60, new Elemento(60, "Sessenta"));
        abb1.addRecursive(80, new Elemento(80, "Oitenta"));
        abb1.addRecursive(220, new Elemento(220, "Duzentos e Vinte"));
        abb1.addRecursive(300, new Elemento(300, "Trezentos"));

    }

    private static void imprimeElem(Elemento elem) {
        System.out.println("Numero -> " + elem.getNumero() + " | Nome -> " + elem.getNome());
    }

}

