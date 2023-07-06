import java.util.ArrayList;

public class Lista_Aitisewn {
	private static Lista_Aitisewn onlyInstance = null;
	private ArrayList<Aitisi> aitiseis;

	public ArrayList<Aitisi> getAitiseis() {
		return aitiseis;
	}

	public void setAitiseis(ArrayList<Aitisi> aitiseis) {
		this.aitiseis = aitiseis;
	}

	private Lista_Aitisewn() {
		this.aitiseis = new ArrayList<Aitisi>();
	}
	
	public static Lista_Aitisewn ListaAitisewn() {
		if(onlyInstance == null) {
			onlyInstance = new Lista_Aitisewn();
		}
		return onlyInstance;
	}
	
	public boolean prosthiki_Aitisis(Aitisi aitisi) {
		
		if(aitisi!=null) {			
			this.aitiseis.add(aitisi);
			return true;
		}else {
			System.out.println("aitisi was null");
			return false;
		}
	}
	public ArrayList<Aitisi> provoli_Aitisewn(FaseisAitisis p){
		ArrayList<Aitisi> result = new ArrayList<Aitisi>();
		for(Aitisi a:this.aitiseis) {
			if(a.getVisibilityPhase().equals(p)) {
				result.add(a);
				System.out.println(a);
			}
		}
		return result;
	}

	public void printData() {
		
		for(Aitisi a:aitiseis) {
			System.out.println("\n");
			a.printData();
		}
	}
}
