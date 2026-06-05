import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Scanner;

public class App {
 
    public static void main(String[] args) throws Exception {
        Tabela_Hash<Funcionario> tabela = new Tabela_Hash<>();
        Scanner input = new Scanner(System.in);

        while (true) { 
            System.out.println("Deseja carregar tabela com dados? (1 -> sim | 0 -> não)");
            int op = input.nextInt();
            if (op != 0 && op != 1) {
                continue;
            } else if (op == 1) {
                BufferedReader br = new BufferedReader(new FileReader("dados.txt"));
                String linha;
                linha = br.readLine();
                while (linha != null) {
                    String[] elemText = linha.split(",");
                    int codigo = Integer.parseInt(elemText[0]);
                    String nome    = elemText[1];
                    int idade      = Integer.parseInt(elemText[2]);
                    float salario = Float.parseFloat(elemText[3]);

                    Funcionario elem = new Funcionario(nome, idade, salario);
                    tabela.insert(codigo, elem);
                    linha = br.readLine();
                }
                br.close();
                System.out.println("Inserções bem sucedidas");
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
                if (tabela.insert(codigo, elem)) {
                    System.out.println("Inserção bem sucedida");
                } else {
                    System.out.println("Inserção mal sucedida");
                }
            } else if (opc == 2) {
                System.out.println("Digite o código do funcionario a buscar: ");
                int codigo = input.nextInt();
                Funcionario elem = tabela.search(codigo);
                if (elem != null) {
                    System.out.println(elem.toString());
                } else {
                    System.out.println("O funcionário não está na tabela.");
                }
            } else if (opc == 3) {
                System.out.println("Digite o código do funcionario a remover: ");
                int codigo = input.nextInt();
                Funcionario elem = tabela.remove(codigo);
                if (elem != null) {
                    System.out.println("Remoção bem sucedida: ");
                    System.out.println(elem.toString());
                } else {
                    System.out.println("Remoção mal sucedida, funcionario nao presente na tabela");
                }
            } else if (opc == 4) {
                int[] codigos = tabela.entrySet();
                System.out.println(codigos.length);
                for (int i = 0; i < codigos.length; i++) {
                    Funcionario elem = tabela.search(codigos[i]);
                    System.out.println("Código: " + codigos[i] + " | Nome: " + elem.toString());
                }
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
