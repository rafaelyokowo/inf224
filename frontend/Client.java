/**
 * @file Client.java
 * @author Rafael Yuji Yokowo (rafael.yokowo@telecom-paris.fr)
 * @brief Project's frontend main file 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
import java.io.*;
import java.net.*;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyledDocument;
import javax.swing.text.SimpleAttributeSet;

/** @brief Class used to create the Client and establish the connection
  * with the cpp server

    It has, as parameters, the connection informations such as the host,
    the port as well as the socket
    @author Y., RAFAEL
    @date November 2022
    */
public class Client
{
  private static final long serialVersionUID = 1L;
  static final String DEFAULT_HOST = "localhost";
  static final int DEFAULT_PORT = 3331;
  private Socket sock;
  private BufferedReader input;
  private BufferedWriter output;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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
  }
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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

/** @brief Class used to create the GUI used as the interface for the user

    It has, as parameters, all the required javaswing elements 
    @author Y., RAFAEL
    @date November 2022
    */
class GUI implements ActionListener{
	
  private Client client;

	private JFrame frame;
	private JPanel panel;
  private JToolBar toolbar;
  private JTextField textfield;
  private JTextArea textArea;
  private JTextPane textPane;
	private JButton b1, b2, exitBtn, clear;

	private JMenuBar menubar;
	private JMenu menu, listMenu;
	private JMenuItem mediaMenu, groupMenu;
	
	GUI(Client _client) {

    this.client = _client;
		this.panel = createPanel();
    this.frame = createFrame();
    createMenuBar();
    createMainFrame();
	}

  private void printText(String text) {
    String[] arrOfStr = text.split("@@", 100);
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

    if (command == "LIST_MEDIA") {
		  response = this.client.send("LM-");
      this.printText(response);
    }
    if (command == "LIST_GROUP") {
		  response = this.client.send("LG-");
      this.printText(response);
    }
    if (command == "BUTTON_1"){
      request = this.textfield.getText();
      response = this.client.send("P-"+request);
      this.printText(response);
    }
    if (command == "BUTTON_2") {
      request = this.textfield.getText();
      response = this.client.send("S-"+request);
      this.printText(response);
    }
    if (command == "EXIT_BUTTON")
      System.exit(0);

    if (command == "CLEAR_BUTTON")
      this.textArea.setText("");
	}

	private JFrame createFrame() {
		this.frame = new JFrame();
		this.frame.setTitle("Media Manager 1.0");
		this.frame.setResizable(false);
		this.frame.setSize(1600,1200);

		return this.frame;
	}

	private JPanel createPanel() {
		this.panel = new JPanel();
		this.panel.setBorder(BorderFactory.createEmptyBorder(50, 50, 10, 30));
		this.panel.setLayout(new GridLayout(1, 1));
		this.panel.setFont(new Font("Arial", 0, 10));
		return this.panel;
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

    this.textfield = new JTextField();

    this.toolbar = new JToolBar();
    this.toolbar.add(this.textfield);
    this.toolbar.add(this.b1);
    this.toolbar.add(this.b2);
    this.toolbar.add(this.exitBtn);

    this.menubar = new JMenuBar();
    this.menubar.setOpaque(true);
    this.menubar.setBackground(Color.WHITE);
		this.menu = new JMenu("Media");
    
    this.listMenu = new JMenu("List");

    this.mediaMenu = new JMenuItem("Media");
    this.mediaMenu.setActionCommand("LIST_MEDIA");
    this.mediaMenu.addActionListener(this);
    this.groupMenu = new JMenuItem("Group");
    this.groupMenu.setActionCommand("LIST_GROUP");
    this.groupMenu.addActionListener(this);

    this.listMenu.add(this.mediaMenu);
    this.listMenu.add(this.groupMenu);
    this.menu.add(this.listMenu);

    this.menubar.add(this.menu);
    this.menubar.add(this.toolbar);
	}

  void createMainFrame (){
    this.textPane = new JTextPane();
    StyledDocument documentStyle = this.textPane.getStyledDocument();
    SimpleAttributeSet centerAttribute = new SimpleAttributeSet();
    StyleConstants.setAlignment(centerAttribute, StyleConstants.ALIGN_CENTER);
    documentStyle.setParagraphAttributes(0, documentStyle.getLength(), centerAttribute, false);

    Font font = new Font("Arial", Font.BOLD, 12);
    this.textPane.setText("\nBienvenue à Media Manager 1.0 !\n" +
                  "Pour voir les medias disponibles, veuillez acceder \n" +
                  "à Media > List et selectioner l'option souhaitée.\n");
    this.textPane.setEditable(false);
    this.textPane.setFont(font);

    this.textArea = new JTextArea(20, 20);  
    JScrollPane scrollableTextArea = new JScrollPane(this.textArea);
    scrollableTextArea.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);  
    scrollableTextArea.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);  
    
    this.panel.add(scrollableTextArea, BorderLayout.SOUTH); 

    this.clear = new JButton("Clear");
    this.clear.setActionCommand("CLEAR_BUTTON");
    this.clear.addActionListener(this);

		this.frame.setJMenuBar(this.menubar);
    this.frame.add(this.textPane, BorderLayout.NORTH);
    this.frame.add(this.panel, BorderLayout.CENTER);
    this.frame.add(this.clear, BorderLayout.SOUTH);
		
		this.frame.pack();
    this.frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.frame.setVisible(true);
  }
}
