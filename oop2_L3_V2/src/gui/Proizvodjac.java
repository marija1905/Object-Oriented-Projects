package gui;

import java.awt.Color;

public abstract class Proizvodjac extends Parcela implements Runnable{
	
	private int ovreme;
	private Baterija baterija;
	private Thread nit;

	public Proizvodjac(String oznaka, Color boja, int ovreme, Baterija baterija) {
		super(oznaka, boja);
		nit = new Thread(this);
		this.ovreme = ovreme;
		this.baterija = baterija;
	}
	
	private void zaustavi() {
		nit.interrupt();
	}

	@Override
	public void run() {
		boolean znaj;
		try {
			while(!Thread.interrupted()) {
				synchronized(this) {
					int ukvreme = ovreme + (int)(Math.random() * 300);
					Thread.sleep(ukvreme);
					znaj = baterija.dodaj(Generisi());
				}
				Thread.sleep(300);
				if(znaj == true) {
					PromeniBoju(Color.RED);
				}
			}
			
		} catch(InterruptedException e) {}
		
	}
	
	public abstract int Generisi();

}
