import java.util.ArrayList;

public class Lista_Melwn {
	private static Lista_Melwn single_instance = null;
	private ArrayList<Melos> Meli_EHDE;
	
	
	private Lista_Melwn() {
		Meli_EHDE = new ArrayList<Melos>();
	}
	
	public static Lista_Melwn ListaMelwn() {
		if(single_instance == null) {
			single_instance = new Lista_Melwn();
		}
		
		return single_instance;
	}
	public ArrayList<Melos> getMeli_EHDE() {
		return this.Meli_EHDE;
	}

	public void setMeli_EHDE(ArrayList<Melos> Meli_EHDE) {
		this.Meli_EHDE = Meli_EHDE;
	}

	
	public boolean prosthiki_melous(Melos melos) {
		
		if(melos !=null) {
			this.Meli_EHDE.add(melos);
			return true;
		}
		return false;
	}

	
	public void diagrafi_melous(Melos melos) {
		
		this.Meli_EHDE.remove(melos);
	}
	
	public void printData() {
		for(Melos m: Meli_EHDE) {
			m.printData();
		}
	}
}
