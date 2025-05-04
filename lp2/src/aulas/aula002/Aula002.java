package aulas.aula002;

import aulas.aula001.Caneta;

public class Aula002 {
	public static void main(String[] ARGS) {
		 Caneta c1 = new Caneta();
		 c1.modelo = "Bic Cristal";
		 c1.cor = "preto";
		 //c1.tamanho = 0.5f;
		 c1.destampar();
		 c1.recarregar();
		 c1.mostrarInfos();
	}
}
