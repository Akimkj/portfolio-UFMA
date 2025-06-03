package aulas.aula001;

public class Caneta {
	  public String cor;
	  public String modelo;
	  public float tamanho = 1.05f;
	  private boolean tampada = true;
	  protected int carga;
	  
	  public Caneta() {} 
	  public Caneta(String cor, String modelo, int carga) {
		  this.cor = cor;
		  this.modelo = modelo;
		  this.carga = carga;
	  }
	  
	  public float getTamanho() {
		  return this.tamanho;
	  }
	  
	  public void setTamanho(float tamanho) {
		  this.tamanho = tamanho; 
	  }
	  
	  public void destampar() {
		  tampada = false;
	  }
	  public void tampar() {
		  tampada = true;
	  }
	  public void rabiscar() {
		  if (tampada || carga == 0 ) {
			  System.out.printf("\nERRO, a caneta está tampada ou está sem carga!\n");
		  }
		  else {
			  carga -= 10;
			  System.out.printf("\nVocê rabiscou! Perdeu 10 de carga.\n");
		  }
	  }
	  
	  public void recarregar() {
		  if (carga != 0) {
			  System.out.printf("\nVocê ainda tem Carga! Carga atual = %d\n", carga);
		  }
		  else {
			  carga = 100;
			  System.out.printf("\nRecarregamento feito!\n");
		  }
	  }
	  
	  public void mostrarInfos() {
		  System.out.printf("Modelo = %s\n", modelo);
		  System.out.printf("Cor = %s\n", cor);
		  System.out.printf("Tamanho = %.2f\n", tamanho);
		  System.out.printf("Está tampada? %b\n", tampada);
		  System.out.printf("Carga = %d\n", carga);
	  }
	  
}
