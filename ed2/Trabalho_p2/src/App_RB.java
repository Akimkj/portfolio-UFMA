import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Scanner;

public class App_RB {
    public static void main(String[] args) throws Exception {
        RubroNegra<Funcionario> tree = new RubroNegra<>();
        Scanner input = new Scanner(System.in);

        while (true) { 
            System.out.println("Deseja carregar a árvore com dados? (1 -> sim | 0 -> não)");
            int op = input.nextInt();
            if (op != 0 && op != 1) {
                continue;
            } else if (op == 1) {
                BufferedReader br = new BufferedReader(new FileReader("dados_1M.txt"));
                String linha;
                linha = br.readLine();
                long timeInicial = System.currentTimeMillis();
                while (linha != null) {
                    String[] elemText = linha.split(",");
                    int codigo = Integer.parseInt(elemText[0]);
                    String nome    = elemText[1];
                    int idade      = Integer.parseInt(elemText[2]);
                    float salario = Float.parseFloat(elemText[3]);

                    Funcionario elem = new Funcionario(nome, idade, salario);
                    tree.insert(codigo, elem);
                    linha = br.readLine();
                }
                long timeFinal = System.currentTimeMillis();
                br.close();
                System.out.println("Inserções bem sucedidas");
                System.out.println("Tempo: " + (timeFinal - timeInicial) + " ms");
            }
            break;
        }
        


        while(true) {
            System.out.println("1 - Inserir um elemento");
            System.out.println("2 - Buscar um elemento");
            System.out.println("3 - Remover um elemento");
            System.out.println("4 - Mostrar todos os elementos");
            System.out.println("5 - Sair");
            int opc = input.nextInt();
            if (opc == 1) {
                System.out.println("Digite o código do funcionario a inserir: ");
                int codigo = input.nextInt();
                Funcionario elem = createFuncionario(input);
                if (tree.insert(codigo, elem)) {
                    System.out.println("Inserção bem sucedida");
                } else {
                    System.out.println("Inserção mal sucedida");
                }
            } else if (opc == 2) {
                System.out.println("Digite o código do funcionario a buscar: ");
                int codigo = input.nextInt();
                long timeInicial = System.currentTimeMillis();
                Funcionario elem = tree.search(codigo);
                long timeFinal = System.currentTimeMillis();
                System.out.println("Tempo: " + (timeFinal - timeInicial) + " ms");
                if (elem != null) {
                    System.out.println(elem.toString());
                } else {
                    System.out.println("O funcionário não está na árvore.");
                }
            } else if (opc == 3) {
                System.out.println("Digite o código do funcionario a remover: ");
                int codigo = input.nextInt();
                long timeInicial = System.currentTimeMillis();
                Funcionario elem = tree.remove(codigo);
                long timeFinal = System.currentTimeMillis();
                System.out.println("Tempo: " + (timeFinal - timeInicial) + " ms");
                if (elem != null) {
                    System.out.println("Remoção bem sucedida: ");
                    System.out.println(elem.toString());
                } else {
                    System.out.println("Remoção mal sucedida, funcionario nao presente na Árvore");
                }
            } else if (opc == 4) {
                System.out.println("Quer imprimir a árvore em qual ordem?");
                System.out.println("1 - pre-ordem");
                System.out.println("2 - Simétrica");
                System.out.println("3 - Pos-ordem");

                int type = input.nextInt();
                while (type > 3 || type < 1) {
                    System.out.println("Digite uma opção válida: ");
                    type = input.nextInt();
                }
                tree.printAll(type);
            } else if (opc == 5) {
                break;
            }
        }
        input.close();
    }

    public static Funcionario createFuncionario(Scanner input) {
        System.out.println("Nome do funcionário: ");
        input.nextLine();
        String nome = input.nextLine();
        System.out.println("Idade do funcionario: ");
        int idade = input.nextInt();
        System.out.println("Salário do funcionario: ");
        float salario = input.nextFloat();
        
        return new Funcionario(nome, idade, salario);
    }
}
