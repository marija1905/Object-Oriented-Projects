package gui;

import java.awt.Color;

public class Generator implements Runnable{
	
	Svemir svemir;
	private int vreme = 900;
	private Thread nit;

	public Generator(Svemir svemir) {
		this.svemir = svemir;
		nit = new Thread(this);
	}
	
	/*
	public void paint(Graphics g) {
		proveri();
	}
	
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

	@Override
	public void run() {
		try {
			while(!Thread.interrupted()) {
				Thread.sleep(vreme);
				synchronized(svemir){
					int x1 = (int)(Math.random() * 200);
					int y1 = 0;
					int r1 = (int)(Math.random() * 20 + 10);
					svemir.dodajNT(new Kometa(r1, x1, y1, Color.GRAY));
				}
			}
		} catch(InterruptedException e) {}
		
		/*
		synchronized (this) {
			nit = null;
			notifyAll();
		}
		*/
	}

}
