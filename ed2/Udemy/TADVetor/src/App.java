import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(System.in);

        int tamanho, vaga, min, max, repetir;

        System.out.println("=====Configurações iniciais=====");
        
        System.out.println("Digite o tamanho do vetor: ");
        tamanho = input.nextInt();
        while ( tamanho <= 0) {
            System.out.println("O tamanho precisa ser positivo: ");
            tamanho = input.nextInt();
        }

        System.out.println("Digite o valor minimo do intervalo: ");
        min = input.nextInt();
        System.out.println("Digite o valor maximo do intervalo: ");
        max = input.nextInt();

        System.out.println("Digite o valor referente a espaço vago: ");
        vaga = input.nextInt ();
        while (vaga <= max && vaga >= min) {
            System.out.println("O valor da vaga deve ser fora do intervalo: ");
            vaga = input.nextInt();
        }
        System.out.println("Pode ter valores repetidos? (1 pra sim ou 0 pra nao");
        repetir = input.nextInt();
        while (repetir  > 1 || repetir < 0) {
            System.out.println("Digite 1 ou 0: ");
            repetir = input.nextInt();
        }
            

        Vetor vet = new Vetor(tamanho, min, max, vaga, repetir);
        int value, position, res;

        while (true) {
            System.out.println("===================================================");
            System.out.println("            Estudo do TAD Vetor");
            System.out.println("===================================================");
            System.out.println("0 - Encerrar");
            System.out.println("1 - Atribuir um valor a determinada posição.");
            System.out.println("2 - Alterar o valor de determinada posição.");
            System.out.println("3 - Remover o valor de determinada posição (atribui o valor indicativo de posição vaga).");
            System.out.println("4 - Ler o conteúdo de uma posicao.");
            System.out.println("5 - Localizar um valor e retornar sua posição (se permitir repetição tem que retornar todos).");
            System.out.println("6 - Inserir na primeira posição vaga (busca no sentido 0 → N).");
            System.out.println("7 - Remover da última posição ocupada (busca no sentido 0 → N).");
            System.out.println("8 - Imprimir o conteúdo do vetor.");

            System.out.println("\nSua opcao: ");
            int opcao = input.nextInt();
            
            if (opcao == 0) {
                System.out.println("Encerrando programa...");
                break;
            } else if (opcao == 1) {
                System.out.println("Digite o valor que deseja inserir: ");
                value = input.nextInt();
                System.out.println("Digite a posicao que será inserido: ");
                position = input.nextInt();
                
                res = vet.atribuir(value, position);
                Utils.printRet(res);
            } else if (opcao == 2) {
                System.out.println("Digite o valor que deseja inserir: ");
                value = input.nextInt();
                System.out.println("Digite a posicao que será inserido: ");
                position = input.nextInt();
                res = vet.alterar(value, position);
                Utils.printRet(res);
            } else if (opcao == 3) {
                System.out.println("Digite a posicao que sera liberada: ");
                position = input.nextInt();
                res = vet.remover(position);
                Utils.printRet(res);
            } else if (opcao == 4) {
                System.out.println("Digite a posicao que deseja ler: ");
                position = input.nextInt();
                res = vet.ler(position);
                Utils.printRet(res);
            } else if (opcao == 5) {
                int[] positions;
                System.out.println("Digite o valor que deseja localizar sua(s) posição(ões): ");
                value = input.nextInt();

                positions = vet.localizar(value);
                if (positions == null) {
                    System.out.println("Não foi encontrado posicoes com esse elemento");
                } else {
                    System.out.println("Posicoes encontradas: ");
                    for (int i = 0; i < positions.length; i++) {
                        System.out.printf("%d ", positions[i]);
                    }
                }
            } else if (opcao == 6) {
                System.out.println("Digite o valor que deseja inserir: ");
                value = input.nextInt();
                res = vet.inserirNaPrimeira(value);
                Utils.printRet(res);
            } else if (opcao == 7) {
                vet.removerDaUltima();
            } else if (opcao == 8) {
                System.out.println("\n\n");
                for (int i = 0; i < vet.getTamanho(); i++) {
                    vet.ler(i);
                }
                System.out.println("\n\n");
            } else {
                System.out.println("Opcao invalida");
            }
        }


        input.close();
    }
}
