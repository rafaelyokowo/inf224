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
	private JButton b1, b2, exitBtn;
	private JMenuBar mb;
  private JToolBar tb;
  private JTextField tf, text;
  private JTextArea textArea;

  private Client client;
	
	private int count = 0;
	private String commande;
	
	GUI(Client _client) {

    this.client = _client;
			
		panel = createPanel();
    frame = createFrame();
    mb = createMenuBar();

    textArea = new JTextArea(20, 20);  
    JScrollPane scrollableTextArea = new JScrollPane(textArea);
    scrollableTextArea.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);  
    scrollableTextArea.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);  

    panel.add(scrollableTextArea, BorderLayout.SOUTH); 

		frame.setJMenuBar(mb);
    frame.add(panel, BorderLayout.CENTER);
		
		frame.pack();
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		String command = e.getActionCommand();
    // BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));

    if (command == "MENU_1") {
      String request = this.textArea.getText();
    
		  String rep = this.client.send("S-logo telecom");
      System.out.println("Request: " + "logo telecom");
      this.textArea.setText(rep);
      //while (true) {
      // }
    }
    if (command == "BUTTON_1")
      this.textArea.setText("A\n");
    if (command == "BUTTON_2")
      this.textArea.setText("B\n");
    if (command == "EXIT_BUTTON")
      System.exit(0);
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
	
	private JMenuBar createMenuBar() {
	
    JMenuBar mb;
		JMenu menu1, menu2;
		JMenuItem m1, m2, m;

    this.exitBtn = new JButton("Exit");
    this.exitBtn.setActionCommand("EXIT_BUTTON");
    this.exitBtn.addActionListener(this);

    this.b1 = new JButton("Add 1");
    this.b1.setActionCommand("BUTTON_1");
    this.b1.addActionListener(this);

    this.b2 = new JButton("Add 2");
    this.b2.setActionCommand("BUTTON_2");
    this.b2.addActionListener(this);
  
    tb = new JToolBar();
    tb.add(this.b1);
    tb.add(this.b2);
    tb.add(this.exitBtn);

    mb = new JMenuBar();
    mb.setOpaque(true);
    mb.setBackground(Color.WHITE);
		menu1 = new JMenu("Afficher Media");
    menu2 = new JMenu("List Media");
		
		// m1 = new JMenuItem("Item 1");
    // m1.setBackground(Color.WHITE);
		// menu1.add(m1);

		m2 = new JMenuItem("Item 2");
    m2.setActionCommand("MENU_1");
    m2.addActionListener(this);
		menu1.add(m2);

    for (int i = 0; i < 3; i++) {
      m = new JMenuItem("Item");
		  menu2.add(m);
    }

    menu1.add(menu2);

    mb.add(menu1);
    mb.add(tb);

		return mb;
	}
}
