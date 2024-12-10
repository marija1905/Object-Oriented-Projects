package gui;

import java.awt.Color;

public abstract class NebeskoTelo extends Objekat {
	
	protected int r;
	
	public NebeskoTelo(int r, int x, int y, Color color) {
		super(x, y, color);
		this.r = r;
	}
	
	abstract void sredi();

}
