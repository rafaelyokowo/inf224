package frontend;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class GUI implements ActionListener{
	
	private JFrame frame;
	private JPanel panel;
	private JTextField textField;
	private JButton submit;
	private JMenuBar mb;
	
	private int count = 0;
	private String commande = "";
	
	public GUI() {
		
		textField = new JTextField();
		textField.setPreferredSize(new Dimension(250, 40));

		submit = new JButton("Submit");
		submit.addActionListener(this);
			
		panel = createPanel();
		panel.add(textField);
		panel.add(submit);
		
		frame = createFrame();

		mb = createMenuBar();

		frame.setJMenuBar(mb);
		frame.setSize(500, 500);
		frame.setVisible(true);
		
		frame.pack();
		frame.setVisible(true);
 

	}
	
	public static void main(String[] args) {
		// System.out.println(client.getName());
		// Pour les utilisateurs de macOSX
		// System.setProperty("apple.laf.useScreenMenuBar", "true");
		new GUI();
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == submit) {
			System.out.println(textField.getText());
		}
	}

	private JFrame createFrame() {
		frame = new JFrame();
		frame.setTitle("TP INF224");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setResizable(true);
		frame.setSize(1200,800);
		frame.add(panel, BorderLayout.CENTER);

		return frame;
	}

	private JPanel createPanel() {
		JPanel panel = new JPanel();
		panel.setBorder(BorderFactory.createEmptyBorder(50, 50, 10, 30));
		panel.setLayout(new GridLayout(0, 1));
		panel.setFont(new Font("Arial", 0, 10));
		return panel;
	}
	
	private JMenuBar createMenuBar() {
	
		JMenuBar mb;
		JMenu menu1, menu2;
		JMenuItem m1, m2, m3;

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

		return mb;
	}
}
