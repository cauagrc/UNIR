package model;

public abstract class Atendimento {
	public static double valorTotal = 0;
	private int quantidade = 0;
	private String codigo;
	private String paciente;
	private String data;
	private double valorBase;
	private String status;
	public static int total = 0;
	private boolean convenio = false;
	
	public Atendimento(String codigo, String paciente, String data, double valorBase, boolean convenio) {
		this.codigo = codigo;
		this.paciente = paciente;
		this.data = data;
		this.convenio =  convenio;
		setValorBase(valorBase);
		registrarAgendamento();
	}

	public abstract void exibirDetalhes();
	
	public abstract double calcularValorFinal();
	
	public void registrarAgendamento() {
		this.setStatus("AGENDADO");
	}
	
	public void registrarCancelamento() {
		this.setStatus("CANCELADO");
	}
	
	public void registrarRealizamento() {
		this.setStatus("REALIZADO");
	}

	public double getValorBase() {
		return valorBase;
	}

	public static double getValorTotal() {
		return valorTotal;
	}

	public static void setValorTotal(double valorTotal) {
		Atendimento.valorTotal = valorTotal;
	}

	public int getQuantidade() {
		return quantidade;
	}

	public void setQuantidade(int quantidade) {
		this.quantidade = quantidade;
	}

	public String getCodigo() {
		return codigo;
	}

	public void setCodigo(String codigo) {
		this.codigo = codigo;
	}

	public String getPaciente() {
		return paciente;
	}

	public void setPaciente(String paciente) {
		this.paciente = paciente;
	}

	public String getData() {
		return data;
	}

	public void setData(String data) {
		this.data = data;
	}

	public String getStatus() {
		return this.status;
	}

	public void setStatus(String status) {
		switch (status) {
		case "CANCELADO":
			status = "CANCELADO";
			break;
		case "AGENDADO":
			status = "AGENDADO";
			break;
		case "REALIZADO":
			status = "REALIZADO";
			break;
		default:
			System.out.println("ERRO: " + status + "Nao e aceito");
			break;
		}
		
		this.status = status; 
	}

	public static int getTotal() {
		return total;
	}

	public static void setTotal(int total) {
		Atendimento.total = total;
	}

	public void setValorBase(double valorBase) {
		if(valorBase > 0) {
			this.valorBase = valorBase;
		} 
		else {
			this.valorBase = 0;
		}
	}

	public boolean isConvenio() {
		return convenio;
	}

	public void setConvenio(boolean convenio) {
		this.convenio = convenio;
	}
	
}
