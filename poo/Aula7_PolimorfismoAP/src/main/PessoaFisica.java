package main;

public class PessoaFisica extends Cliente {
	private String cpf;

	public PessoaFisica(String nome, String endereco, String telefone, String cpf) {
		super(nome, endereco, telefone);
		this.cpf = cpf;
	}

	public String getCpf() {
		return cpf;
	}
	
	public void imprimirDados() {
		System.out.println("Perfil Pessoal de " + super.getNome());
		System.out.println("Cpf: " + this.cpf);
		System.out.println("Endereco: " + super.getEndereco());
		System.out.println("Telefone: " + super.getTelefone());
	}
}
