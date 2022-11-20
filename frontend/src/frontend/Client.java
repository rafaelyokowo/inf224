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
	private JButton b1, b2, exitBtn, clear;
	private JMenuBar mb;
  private JToolBar tb;
  private JTextField tf, text;
  private JTextArea textArea;

	private JMenu mediaMenu;
	private JMenuItem listMenu, m2, m;

  private Client client;
	
	private int count = 0;
	private String commande;
	
	GUI(Client _client) {

    this.client = _client;
			
		panel = createPanel();
    frame = createFrame();
    createMenuBar();

    textArea = new JTextArea(20, 20);  
    JScrollPane scrollableTextArea = new JScrollPane(textArea);
    scrollableTextArea.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);  
    scrollableTextArea.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);  

    this.clear = new JButton("Clear");
    this.clear.setActionCommand("CLEAR_BUTTON");
    this.clear.addActionListener(this);

    panel.add(scrollableTextArea, BorderLayout.SOUTH); 

		frame.setJMenuBar(mb);
    frame.add(panel, BorderLayout.CENTER);
    frame.add(this.clear, BorderLayout.SOUTH);
		
		frame.pack();
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}

  private void printText(String text) {
    String[] arrOfStr = text.split("@", 100);
      for (String name : arrOfStr){
        this.textArea.append(name);
        this.textArea.append("\n");
      }
  }
	
	@Override
	public void actionPerformed(ActionEvent e) {
		String command = e.getActionCommand();
    String request = "foo";
    String response = "bar";

    if (command == "LIST") {
		  String rep = this.client.send("L-");
      String[] arrOfStr = rep.split("@@", 100);
      for (String name : arrOfStr){
        this.textArea.append(name);
      }
    }
    if (command == "BUTTON_1"){
      request = this.tf.getText();
      response = this.client.send("P-"+request);
    }
    if (command == "BUTTON_2") {
      request = this.tf.getText();
      response = this.client.send("S-"+request);
      this.printText(response);
    }
    if (command == "EXIT_BUTTON")
      System.exit(0);

    if (command == "CLEAR_BUTTON")
      this.textArea.setText("");
	}

	private JFrame createFrame() {
		frame = new JFrame();
		frame.setTitle("TP INF224");
		frame.setResizable(false);
		frame.setSize(1200,800);

		return frame;
	}

	private JPanel createPanel() {
		JPanel panel = new JPanel();
		panel.setBorder(BorderFactory.createEmptyBorder(50, 50, 10, 30));
		panel.setLayout(new GridLayout(1, 1));
		panel.setFont(new Font("Arial", 0, 10));
		return panel;
	}
	
	private void createMenuBar() {

    this.exitBtn = new JButton("Exit");
    this.exitBtn.setActionCommand("EXIT_BUTTON");
    this.exitBtn.addActionListener(this);

    this.b1 = new JButton("Play");
    this.b1.setActionCommand("BUTTON_1");
    this.b1.addActionListener(this);

    this.b2 = new JButton("Show");
    this.b2.setActionCommand("BUTTON_2");
    this.b2.addActionListener(this);

    this.tf = new JTextField();

    tb = new JToolBar();
    tb.add(this.tf);
    tb.add(this.b1);
    tb.add(this.b2);
    tb.add(this.exitBtn);

    this.mb = new JMenuBar();
    this.mb.setOpaque(true);
    this.mb.setBackground(Color.WHITE);
		this.mediaMenu = new JMenu("Media");
    
    this.listMenu = new JMenuItem("List");
    this.listMenu.setActionCommand("LIST");
    this.listMenu.addActionListener(this);

    this.mediaMenu.add(listMenu);

    this.mb.add(mediaMenu);
    this.mb.add(tb);
	}
}
