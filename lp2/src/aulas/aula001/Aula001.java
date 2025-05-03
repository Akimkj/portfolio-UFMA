package aulas.aula001;

public class Aula001 {
	public static void main(String[] ARGS) {
		Caneta c1 = new Caneta();
		
		c1.modelo = "Bic";
		c1.tamanho = 1.05f;
		c1.cor = "Azul";
		
		c1.mostrarInfos();
		
		c1.destampar();
		
		while (c1.carga != 0) {
			c1.rabiscar();
		}
		
		c1.recarregar();
		c1.mostrarInfos();
		
	}
}
