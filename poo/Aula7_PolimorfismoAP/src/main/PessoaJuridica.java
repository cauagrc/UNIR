package main;

public class PessoaJuridica extends Cliente {
	private String cnpj;
	private String nomeFantasia;

	public PessoaJuridica(String nome, String endereco, String telefone, String cnpj, String nomeFantasia) {
		super(nome, endereco, telefone);
		this.cnpj = cnpj;
		this.nomeFantasia = nomeFantasia;
	}

	public String getCnpj() {
		return cnpj;
	}

	public String getNomeFantasia() {
		return nomeFantasia;
	}
	
	public void setNomeFantasia(String nomeFantasia) {
		this.nomeFantasia = nomeFantasia;
	}

	public void imprimirDados() {
		System.out.println("Perfil Juridico de " + super.getNome());
		System.out.println("Cnpj: " + this.cnpj);
		System.out.println("Nome Fantasia: " + this.nomeFantasia);
		System.out.println("Endereco: " + super.getEndereco());
		System.out.println("Telefone: " + super.getTelefone());
	}
}
