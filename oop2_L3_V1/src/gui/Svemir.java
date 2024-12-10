package gui;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;

public class Svemir extends Canvas implements Runnable{
	
	private ArrayList <NebeskoTelo> nt = new ArrayList <>();
	private Color pboja = Color.GRAY;
	private Thread nit;
	private long spavaj = 100;
	private int pomeri = 5;

	
	public Svemir() {
		//proveri();
		nit = new Thread(this);
	}

	
	@Override
	public void paint(Graphics g) {
		for(NebeskoTelo n:nt) {
			n.paint(g);
		}
	}
	/*

	private synchronized void proveri() {
		if(nit != null) nit.interrupt();
		while(nit != null) {
			try {
				wait();
			} catch (InterruptedException e) {}
		}
	}
	*/

	
	public void pokreni(){
		nit.start();
	}
	
	public void zavrsi() {
		nit.interrupt();
	}
	
	public void dodajNT(NebeskoTelo telo) {
		nt.add(telo);
		double angle = Math.random() * 2 * Math.PI;
		((Kometa)nt.get(nt.size()-1)).postavi(angle);
	}
	


	@Override
	public void run() {
		try {
			while(!Thread.interrupted()) {
				Thread.sleep(spavaj);
				synchronized(this) {
					repaint();
					for(NebeskoTelo t: nt) {
						t.PomerajY(pomeri);
						t.sredi();
					}
				}
			}
			
		} catch (InterruptedException e) {}
		
		/*
		synchronized (this) {
			nit = null;
			notifyAll();
		}
		*/

	}

}
