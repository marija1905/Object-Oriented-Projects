package gui;

public class Baterija {
	
	private int energija;
	private int kapacitet;

	public Baterija(int kapacitet) {
		this.kapacitet = kapacitet;
		energija = kapacitet;
	}
	
	public boolean dodaj(int kolicina) {
		if(kolicina == 0) return false;
		if(energija < kapacitet) {
			energija += kolicina;
		}
		if(energija > kapacitet) {
			energija = kapacitet;
		}
		return true;
	}
	
	public void isprazni() {
		energija = 0;
	}
	
	public boolean DaLiJePuna() {
		return energija == kapacitet;
	}
}
