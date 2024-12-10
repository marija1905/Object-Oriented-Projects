package gui;

import java.awt.Color;
import java.awt.Graphics;

public class Kometa extends NebeskoTelo {
	
	private int nizX[] = new int[10];
	private int nizY[] = new int[10];
	private double angle = 0.0;

	public Kometa(int r, int x, int y, Color color) {
		super(r, x, y, color);
		sredi();
	}
	
	@Override
	void sredi() {
		pX();
		pY();
	}
	
	public void pX() {
		double uvecaj = 2 * Math.PI / 5;
		int i = 0;
		for(double j = angle; j < 2 * Math.PI + angle; j += uvecaj) {
			nizX[i] =  x + (int)(r * Math.cos(j));
			i++;
		}
	}
	public void pY() {
		double uvecaj = 2 * Math.PI / 5;
		int i = 0;
		for(double j = angle; j < 2 * Math.PI + angle; j += uvecaj) {
			nizY[i] =  y + (int)(r * Math.sin(j));
			i++;
		}
	}
	
	public void postavi(double angle) {
		this.angle = angle;
	}

	@Override
	public void paint(Graphics g) {
		Color pboja = g.getColor();
		g.setColor(color);
		g.drawPolygon(nizX, nizY, 5);
		g.fillPolygon(nizX, nizY, 5);
		g.setColor(pboja);
	}

}
