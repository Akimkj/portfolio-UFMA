package exercicios.exBanco;

public class Banco {
	public int numBanco;
	protected String tipo;
	private String dono;
	private float saldo;
	private boolean status;
	
	public Banco() {
		this.status = false;
		this.saldo = 0;
	}
	
	public int getNumBanco() {
		return numBanco;
	}
	public void setNumBanco(int numBanco) {
		this.numBanco = numBanco;
	}
	
	public String getTipo() {
		return tipo;
	}
	public void setTipo(String tipo) {
		if (tipo == "corrente" || tipo == "poupança") {
			this.tipo = tipo;
		}
		else {
			System.out.printf("Tipo de conta incompatível! Escolha entre 'corrente' ou 'poupança'.\n");
		}
	}
	
	public String getDono() {
		return dono;
	}
	public void setDono(String dono) {
		this.dono = dono;
	}
	
	public float getSaldo() {
		return saldo;
	}
	public void setSaldo(float saldo) {
		this.saldo = saldo;
	}
	
	public boolean getStatus() {
		return status;
	}
	public void setStatus(boolean status) {
		this.status = status;
	}
	
	public void abrirConta(String tipo) {
		setStatus(true);
		setTipo(tipo);
		if (getTipo() == "corrente") {
			setSaldo(50f);
		}
		else if (getTipo() == "poupança") {
			setSaldo(150f);
		}
	}
	
	public void fecharConta(float saldo) {
		if (saldo > 0) {
			System.out.printf("\nConta com dinheiro!\n");
		}
		else if (saldo < 0) {
			System.out.printf("\nConta com pendência\n");
		}
		else {
			setStatus(false);
		}
	}
	
	public void depositar(float valorDepositar) {
		if (getStatus()) {
			setSaldo(getSaldo() + valorDepositar);
		}
		else {
			System.out.printf("Sua conta está fechada!\n");
		}
	}
	
	public void sacar(float valorSacar) {
		if (getStatus() && getSaldo() > valorSacar) {
			setSaldo(getSaldo() - valorSacar);
		}
		else {
			if (getStatus() == false) {
				System.out.printf("Conta fechada!");
			}
			else {
				System.out.printf("Dinheiro insuficiente!");
			}
		}
	}
	
	public void pagarMensal() {
		float valorPagar;
		if (getTipo() == "corrente") {
			valorPagar = 12f;
		}
		else {
			valorPagar = 20f;
		}
		
		setSaldo(getSaldo() - valorPagar);
	}
}
