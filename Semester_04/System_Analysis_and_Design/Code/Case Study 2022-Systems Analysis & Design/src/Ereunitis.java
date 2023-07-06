import java.util.ArrayList;

public class Ereunitis {
	private String email;
	private String password;
	private ArrayList<Aitisi> Lista_Aitisewn_Tou;
	private int votesCounter;
	public Ereunitis(String email, String password) {
		this.email=email;
		this.password = password;
		Lista_Aitisewn_Tou = new ArrayList<Aitisi>();
		votesCounter=0;
	}
	
	
	public String getEmail() {
		return this.email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getPassword() {
		return this.password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public ArrayList getLista_Aitisewn_Tou() {
		return this.Lista_Aitisewn_Tou;
	}

	public void setLista_Aitisewn_Tou(ArrayList Lista_Aitisewn_Tou) {
		this.Lista_Aitisewn_Tou = Lista_Aitisewn_Tou;
	}
	
	public void prostheseAitisiStinListaTou(Aitisi a) {
		this.Lista_Aitisewn_Tou.add(a);
	}


	public void ypovolli_Aitisis(Aitisi a) {
		
		if(a.getEreunitis().equals(this)) {
			
			a.setVisibilityPhase(FaseisAitisis.ELEGXOS);
			
		}else {
			System.out.println("this operation is prohibited");
		}
		
		
	}
	public void epeksergasia_Aitisis(Aitisi aitisi) {
		
		throw new UnsupportedOperationException();
	}

	public void print_Aitiseis() {
		
		System.out.println(this.email+ " @uom.edu.gr");
		String currentMsg = "";
		for(Aitisi a: this.Lista_Aitisewn_Tou) {
			switch (a.getVisibilityPhase()) {
				case PROETOIMASIA:
					currentMsg = "Simplirwse ta aparaithta eggrafa";
					break;
				case ELEGXOS:
					currentMsg = "H aitisi elegxetai";
				case APORRIPSH:
					currentMsg = "H aitisi aporrifthike";
					break;
				case ENHMERWSH_GIA_VELTIWSEIS:
					currentMsg = "Xreiazontai kapoies beltiwseis sthn aitisi\n";
					currentMsg+= a.getApofasi().getText();
					break;
				case ENHMERWSH_GIA_APODOXH:
					currentMsg = "H aitisi egine apodekth";
					break;
				default:
					currentMsg = "H aitisi vrisketai se stadio eksetasis";
				
					
					
			}
			System.out.println("Aitisi:" + a);
			System.out.println("Minima: " + currentMsg);
		}
	}


	
	public void printData() {
		System.out.println("Ereunitis [email=" + email + ", password=" + password + ", Lista_Aitisewn_Tou=" + Lista_Aitisewn_Tou
				+ ", votesCounter=" + votesCounter + "]");
	}
}
