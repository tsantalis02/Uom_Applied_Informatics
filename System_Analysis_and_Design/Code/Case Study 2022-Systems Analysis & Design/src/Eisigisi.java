import java.util.ArrayList;
import java.util.Date;

public class Eisigisi {
	private Date date;
	private String eisigisiText;
	private int currentVotesScore;
	private ArrayList<Melos> listaMelwnPsifoforias;
	private boolean result;
	private Melos eisigitis = null;
	private Apofasi apofasi;
	private int psifoi;

	public Eisigisi() {
		
		this.listaMelwnPsifoforias = new ArrayList<Melos>();
		for(Melos m:Lista_Melwn.ListaMelwn().getMeli_EHDE()){
			this.listaMelwnPsifoforias.add(m);
		}
		this.psifoi = 0;
		this.currentVotesScore = 0;
		Lista_Eisigisewn listaEisigiseon = Lista_Eisigisewn.listaEisigiseon();
		listaEisigiseon.prosthiki_Eisigisis(this);
	}
	
	
	public void registerVote(int vote) {
		if(!this.psifisaneïloi()) {
			currentVotesScore+= vote;			
			this.setPsifoi(++psifoi);
		}else {
			System.out.println("oloi exoune pshfisei");
		}
	}
	
	public boolean psifisaneïloi() {
		
		return this.getListaMelwn().size() + 1 == psifoi;
	}
	public String getEisigisiText() {
		return eisigisiText;
	}

	public void setEisigisiText(String eisigisiText) {
		this.date = new Date();
		this.eisigisiText = eisigisiText;
	}
	public int getCurrentVotesScore() {
		return currentVotesScore;
	}

	public void eggrafi_Psifou(int currentVotesScore) {
		this.currentVotesScore = currentVotesScore;
	}

	public int getPsifoi() {
		return psifoi;
	}

	public void setPsifoi(int psifoi) {
		this.psifoi = psifoi;
	}

	public Date getDate() {
		return this.date;
	}

	public void setDate(Date date) {
		this.date = date;
	}

	public ArrayList<Melos> getListaMelwn() {
		return this.listaMelwnPsifoforias;
	}

	public void setListaMelwn(ArrayList<Melos> ListaMelwn) {
		this.listaMelwnPsifoforias = ListaMelwn;
	}

	public Melos getEisigitis() {
		return this.eisigitis;
	}

	public void setEisigitis(Melos eisigitis) {
		if(this.eisigitis != null)System.out.println("ginetai allagh eisigiti");//tha mporousame na mhn epitrepoume allagh
		this.eisigitis = eisigitis;
	}

	public Apofasi getApofasi() {
		return this.apofasi;
	}

	public void setApofasi(Apofasi apofasi) {
		this.apofasi = apofasi;
	}

	public void apomakryne_melos(Melos melos) {
		this.listaMelwnPsifoforias.remove(melos);
	}


	public boolean getResult() {
		return result;
	}

	public void setResult(boolean result) {
		this.result = result;
	}
	

	public void printData() {
		System.out.println("Eisigisi [date=" + date + ", eisigisiText=" + eisigisiText + ", currentVotesScore="
				+ currentVotesScore + ", listaMelwnPsifoforias=" + listaMelwnPsifoforias + ", result=" + result
				+ ", eisigitis=" + eisigitis + ", apofasi=" + apofasi + ", psifoi=" + psifoi + "]");
	}
	
	public void calc_result() {
		
		if(!this.psifisaneïloi()) {
			System.out.println("not everybody voted yet");
			return;
		}
		this.result = this.currentVotesScore > 0;
		String message = (result)? "Ginetai Apodekth":"Aporriptetai";
		System.out.println(message);
	}
}
