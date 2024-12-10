package gui;

import java.awt.Color;

public class Hidroelektrana extends Proizvodjac {
	
	int brVodenih;

	public Hidroelektrana(int ovreme, Baterija baterija) {
		super("H", Color.BLUE, ovreme, baterija);
		brVodenih = 0;
	}
	
	public void postavi() {
		this.brVodenih = brVodenih;
	}

	@Override
	public int Generisi() {
		// TODO Auto-generated method stub
		return 0;
	}

}
