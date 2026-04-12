package main;

public class Main {

	public static void main(String[] args) {
		AppBancario app = new AppBancario();

		Conta Caua = new Conta("Caua", 123456789, "123");
		Conta Emilly = new Conta("Emilly", 987654321, "456");

		app.cadastrarConta(Caua);
		app.cadastrarConta(Emilly);

		app.logar(Caua.getNumConta(), "123");

		app.depositar(1000);
		app.transferir(Emilly.getNumConta(), 999);

		Caua.imprimirExtrato();
		
		System.out.printf("\n");

		app.logar(Emilly.getNumConta(), "456");

		Emilly.imprimirExtrato();
		
		System.out.printf("\n");

		AppBancario.exibirMetricas();
	}
}