
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.Random;

public class Gerador {
    public static void main(String[] args) throws Exception {
        String[] nomes = {
            "Ana","Bia","Ericksen","Daniela","Eduarda","Iza","Gabriela","Helena","Isabela","Juliana",
            "Mika","Larissa","Mariana","Marina","Olivia","Camilly","Rafaela","Sabrina","Tatiana","Vanessa",
            "Carlos","Daniel","Eduardo","Felipe","Gustavo","Kelvin","Igor","Jose","Lucas","Marcos",
            "Nicolas","Otavio","Pedro","Rafael","Samuel","Thiago","Aqua","Diogo","Christian","Yago",
            "Edson","Leticia","Priscila","Adilla","Simone","Brendda","Luciana","Michele","Roberta","Viviane",
            "Andre","Bruno","Diego","Fabio","Giovanni","Guilherme","Matheus","Paulo","Ricardo","Rodrigo"
        };

        String[] sobrenomes = {
            "Silva","Santos","Oliveira","Souza","Rodrigues","Ferreira","Alves","Pereira","Pinho","Gomes",
            "Costa","Ribeiro","Martins","Carvalho","Almeida","Lopes","Sousa","Fernandes","Vieira","Barbosa",
            "Rocha","Dias","Nascimento","Andrade","Paiva","Nunes","Marques","Machado","Mendes","Freitas",
            "Cardoso","Barrio","Gonçalves","Soares","Castro","Araujo","Carneiro","Monteiro","Moura","Teixeira"
        };

        Random rand = new Random();
        Tabela_Hash<Boolean> usados = new Tabela_Hash<>();
        BufferedWriter bw = new BufferedWriter(new FileWriter("dados.txt"));
        int gerados = 0;

        while (gerados < 800) {
            int codigo = rand.nextInt(99999) + 1;
            if (usados.search(codigo) != null) {
                continue;
            }
            usados.insert(codigo, true);

            String nome = nomes[rand.nextInt(nomes.length)] + " " + sobrenomes[rand.nextInt(sobrenomes.length)];
            int idade = rand.nextInt(52) + 18;
            float salario = (1500 + rand.nextFloat() * 21500) * 100;
            salario = Math.round(salario) / 100.0f;
            
            bw.write(codigo + "," + nome + "," + idade + "," + salario);
            bw.newLine();
            gerados++;
        }
        bw.close();
    }
}
