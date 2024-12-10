package gui;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Color;
import java.awt.Frame;
import java.awt.Label;
import java.awt.Panel;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;


public class Simulator extends Frame{
	
	
	private Svemir svemir;
	private Generator gen;
	private Panel s = new Panel();

	public Simulator() {
		setResizable(false);
		setBounds(0, 0, 200, 400);
		setTitle("");
		svemir = new Svemir();
		gen = new Generator(svemir);
		
		populateWindow();
		
		addWindowListener (new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				svemir.zavrsi();
				gen.zavrsi();
				dispose();
			}
		});
		
		setVisible(true);
	}
	
	private void populateWindow() {
		add(svemir, BorderLayout.CENTER);
		svemir.setBackground(Color.BLACK);
		
		Button dugme = new Button("Pokreni!");
		add(s, BorderLayout.SOUTH);
		s.add(dugme, BorderLayout.CENTER);
		dugme.addActionListener((ae) -> {
			svemir.pokreni();
			gen.pokreni();
			dugme.setEnabled(false);
		});
		
		
	}
	
	public static void main(String[] args) {
		new Simulator();
	}

}
