import java.util.Date;

public class Aitisi {
	private int inqueueNumber;
	private String subject;
	private Date date;
	private Ereunitis ereunitis;
	private Apofasi apofasi;
	private Lista_Arxeiwn files;
	private String title;
	private FaseisAitisis visibilityPhase;
	private Eisigisi eisigisi;
	public Ereunitis getEreunitis() {
		return ereunitis;
	}

	public Lista_Arxeiwn getFiles() {
		return files;
	}
	public void setFiles(Lista_Arxeiwn files) {
		this.files = files;
	}
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public void setEreunitis(Ereunitis ereunitis) {
		this.ereunitis = ereunitis;
	}

	
	public Aitisi(Ereunitis e, String title,String subject,Lista_Arxeiwn arxeia) {
		this.ereunitis = e;
		this.title = title;
		this.subject = subject;
		this.files = arxeia;
		this.date = new Date();
		this.visibilityPhase = FaseisAitisis.PROETOIMASIA;
		this.eisigisi = new Eisigisi();
		this.ereunitis.prostheseAitisiStinListaTou(this);
		this.apofasi = new Apofasi();
		this.inqueueNumber = -1;
		Lista_Aitisewn lista = Lista_Aitisewn.ListaAitisewn();
		lista.prosthiki_Aitisis(this);
	
	}
	public int getInqueueNumber() {
		return this.inqueueNumber;
	}

	public void setInqueueNumber(int inqueueNumber) {
		this.inqueueNumber = inqueueNumber;
	}

	public String getSubject() {
		return this.subject;
	}

	public void setSubject(String subject) {
		this.subject = subject;
	}

	public Date getDate() {
		return this.date;
	}

	public void setDate(Date date) {
		this.date = date;
	}

	public Apofasi getApofasi() {
		return this.apofasi;
	}

	public void setApofasi(Apofasi apofasi) {
		this.apofasi = apofasi;
	}

	public FaseisAitisis getVisibilityPhase() {
		return this.visibilityPhase;
	}

	public void setVisibilityPhase(FaseisAitisis visibilityPhase) {
		this.visibilityPhase = visibilityPhase;
	}

	public Eisigisi getEisigisi() {
		return this.eisigisi;
	}

	public void setEisigisi(Eisigisi eisigisi) {
		this.eisigisi = eisigisi;
	}

	public void printData() {
		System.out.println( "Aitisi [me arithmo prwtokollou =" + inqueueNumber + ", thema=" + subject + ", hmeromhnia=" + date + ", Ereunitis="
				+ ereunitis + ", apofasi=" + apofasi + ", arxeia=" + files + ", titlo=" + title + ", Katastasi="
				+ visibilityPhase + ", Eisigisi=" + eisigisi + "]");
	}
	@Override
	public String toString() {
		return this.title + " " + this.inqueueNumber + " " + this.files + " " + this.visibilityPhase;
	}
}
