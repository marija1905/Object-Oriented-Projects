package gui;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;

public class Plac extends Canvas{
	
	private int redovi, kolone;
	private EnergetskiSistem es;
	private ArrayList <Parcela> parcela;
	private int kvadrat;
	
	private int dohvD() {
		int sirina = es.centar.getWidth();
		int visina = es.centar.getHeight();
		int s = sirina/kolone * kolone;
		int v = visina/ redovi * redovi;
		return Math.max(s, v);
	}
	
	
	
	private void crtajLinije() {
		int dimenzije = dohvD();
		int iteriraj = dohvD() / redovi;
		Graphics g = getGraphics();
		g.setColor(Color.WHITE);
		
		for(int i = 0; i < dimenzije; i += iteriraj) {
			g.drawLine(0, i,  dimenzije - 1, i);
		}
		
		dimenzije = dohvD() / kolone;
		for(int i = 0; i < dimenzije; i += iteriraj) {
			g.drawLine(i, 0, i, dimenzije - 1);
		}
		
	}
	@Override
	public void paint(Graphics g) {
		kvadrat = dohvD() / redovi;
		crtajLinije();
		
		for(Parcela p:parcela) {
			p.paint(g);
		}
	}

	public Plac(int redovi, int kolone) {
		this.redovi = redovi;
		this.kolone = kolone;
		
		double nasumicno = Math.random();
		
		int iteriraj = dohvD() / kvadrat;
		int kraj = dohvD();
		
		for(int i = 0; i < kraj; i+= iteriraj) {
			if(nasumicno <= 0.7) {
				parcela.add(new TravnataPovrs());
			}
			else {
				parcela.add(new VodenaPovrs());
			}
		}
		
	}

}
