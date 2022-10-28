package frontend;
//
// Client Java pour communiquer avec le Serveur C++ 
// eric lecolinet - telecom paristech - 2015
//

import java.io.*;
import java.net.*;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class Client
{
  private static final long serialVersionUID = 1L;
  static final String DEFAULT_HOST = "localhost";
  static final int DEFAULT_PORT = 3331;
  private Socket sock;
  private BufferedReader input;
  private BufferedWriter output;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  
  ///
  /// Lit une requete depuis le Terminal, envoie cette requete au serveur,
  /// recupere sa reponse et l'affiche sur le Terminal.
  /// Noter que le programme bloque si le serveur ne repond pas.
  ///
  public static void main(String argv[]) {
    String host = DEFAULT_HOST;
    int port = DEFAULT_PORT;
    if (argv.length >=1) host = argv[0];
    if (argv.length >=2) port = Integer.parseInt(argv[1]);
    
    Client client = null;
    GUI gui = null;
    
    try {
      client = new Client(host, port);
      gui = new GUI(client);
    }
    catch (Exception e) {
      System.err.println("Client: Couldn't connect to "+host+":"+port);
      System.exit(1);
    }
    
    gui.setText("Client connected to "+host+":"+port);
    // System.out.println("Client connected to "+host+":"+port);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ///
  /// Initialise la connexion.
  /// Renvoie une exception en cas d'erreur.
  ///
  public Client(String host, int port) throws UnknownHostException, IOException {
    try {
      sock = new java.net.Socket(host, port);
    }
    catch (java.net.UnknownHostException e) {
      System.err.println("Client: Couldn't find host "+host+":"+port);
      throw e;
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't reach host "+host+":"+port);
      throw e;
    }
    
    try {
      input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
      output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't open input or output streams");
      throw e;
    }
  }
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  
  ///
  /// Envoie une requete au server et retourne sa reponse.
  /// Noter que la methode bloque si le serveur ne repond pas.
  ///
  public String send(String request) {
    // Envoyer la requete au serveur
    try {
      request += "\n";  // ajouter le separateur de lignes
      output.write(request, 0, request.length());
      output.flush();
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't send message: " + e);
      return null;
    }
    
    // Recuperer le resultat envoye par le serveur
    try {
      return input.readLine();
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't receive message: " + e);
      return null;
    }
  }
}

class GUI implements ActionListener{
	
	private JFrame frame;
	private JPanel panel;
	private JTextField command, info;
	private JButton submit;
	private JMenuBar mb;

  private Client client;
	
	private int count = 0;
	private String commande;
	
	GUI(Client _client) {

    this.client = _client;
		
    info = new JTextField();
		info.setPreferredSize(new Dimension(250, 80));
    info.setEditable(false);

		command = new JTextField();
		command.setPreferredSize(new Dimension(250, 40));

		submit = new JButton("Submit");
		submit.addActionListener(this);
			
		panel = createPanel();
    panel.add(info);
		panel.add(command);
		panel.add(submit);
		
		frame = createFrame();

		mb = createMenuBar();

		frame.setJMenuBar(mb);
		//frame.setSize(500, 500);
		
		frame.pack();
		frame.setVisible(true);
 
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == submit) {
      String request = this.command.getText();
      System.out.println("Request: " + request);
			this.client.send(request);
		}
	}

  public void setText(String text) {
    this.info.setText(text);
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




