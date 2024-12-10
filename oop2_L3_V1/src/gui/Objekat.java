package gui;

import java.awt.Color;
import java.awt.Graphics;

public abstract class Objekat {
	
	protected int x, y;
	protected Color color;

	public Objekat(int x, int y, Color color) {
		this.x = x;
		this.y = y;
		this.color = color;
	}
	
	public int DohvX() {
		return x;
	}
	
	public int DohvY() {
		return y;
	}
	
	public int PomerajX(int pomeraj) {
		return x += pomeraj;
	}
	
	public int PomerajY(int pomeraj) {
		return y += pomeraj;
	}
	
	public abstract void paint(Graphics g);

}
