package gui;


import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Label;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class Parcela extends Label {
	
	private String oznaka;
	private Color boja;
	private int velicina = 14;
	
	
	public class MouseEventHandler extends MouseAdapter{
		public void mousePressed(MouseEvent e) {
			
		}
		public void mouseReleased(MouseEvent e) {
			revalidate();
			repaint();
		}
	}

	public Parcela(String oznaka, Color boja)  {
		this.oznaka = oznaka;
		this.boja = boja;
		MouseListener ml = new MouseEventHandler();
		addMouseListener(ml);
		
		if(ml != null) {
			velicina = 20;
			repaint();
		}
	}
	
	public void PromeniBoju(Color boja) {
		this.boja = boja;
	}
	
	@Override
	public void paint(Graphics g) {
		Color pboja = g.getColor();
		g.setColor(Color.WHITE);
		g.setFont(new Font(Font.SERIF, Font.BOLD, velicina));
		g.drawString(oznaka, 0, 0);
		g.setColor(pboja);
	}

}
