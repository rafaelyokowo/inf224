package frontend;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class GUI implements ActionListener{
	
	private JLabel label;
	private JFrame frame;
	private JPanel panel;
	
	static JMenuBar mb;
	static JMenu menu1, menu2;
	static JMenuItem m1, m2, m3;
	static JFrame f;
	
	private int count = 0;
	
	public GUI() {
		
		JButton button = new JButton("Please click me !");
		button.addActionListener(this);
		
		label = new JLabel("Clicks: 0");
		
		panel = new JPanel();
		panel.setBorder(BorderFactory.createEmptyBorder(50, 50, 10, 30));
		panel.setLayout(new GridLayout(0, 1));
		panel.add(button);
		panel.add(label);
		
		frame = new JFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setTitle("TP INF224");
		frame.add(panel, BorderLayout.CENTER);

		createMenu(frame);
		
		frame.pack();
		frame.setVisible(true);
 

	}
	
	public static void main(String[] args) {
		// Pour les utilisateurs de macOSX
		// System.setProperty("apple.laf.useScreenMenuBar", "true");
		new GUI();
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		count++;
		label.setText("Clicks: " + count);
	}
	
	private void createMenu(JFrame f) {
		mb = new JMenuBar();
		menu1 = new JMenu("Menu 1");
		menu2 = new JMenu("Menu 2");
		

		m1 = new JMenuItem("Item 1");
		m2 = new JMenuItem("Item 2");
		m3 = new JMenuItem("Item 3");

		menu1.add(m1);
		menu1.add(m2);
		menu1.add(m3);

		mb.add(menu1);
		mb.add(menu2);

		f.setJMenuBar(mb);
		f.setSize(500, 500);
		f.setVisible(true);
	}
}
