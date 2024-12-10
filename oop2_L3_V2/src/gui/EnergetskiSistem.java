package gui;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Color;
import java.awt.Frame;
import java.awt.Panel;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class EnergetskiSistem extends Frame{
	
	private Plac plac;
	private Baterija baterija;
	Panel centar = new Panel();
	
	private void populateWindow() {
		add(plac, BorderLayout.CENTER);
		plac.paint(getGraphics());
		
		Button dugme = new Button("Dodaj!");
		add(centar, BorderLayout.NORTH);
		centar.add(dugme, BorderLayout.CENTER);
		dugme.addActionListener((ae) -> {
			
		});
		
		
	}

	public EnergetskiSistem(int redovi, int kolone, int kapacitet) {
		setResizable(false);
		setBounds(0, 0, 500, 500);
		setTitle("Energetski sistem");
		
		plac = new Plac(redovi, kolone);
		baterija = new Baterija(kapacitet);
		
		populateWindow();
		
		addWindowListener (new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				dispose();
			}
		});
		
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new EnergetskiSistem(5, 6, 100);
	}

}
