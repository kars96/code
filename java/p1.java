import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;
public class p1 extends JFrame implements ActionListener
{	static int i=0;
	static int n=0;
	static String[] std=new String[10];
		static String[] id=new String[10];
		static String[] marks=new String[10];
	JPanel p,p1,p2;
	JButton[] b={ new JButton("next"),new JButton("prev"),new JButton("exit")};
	JLabel[] l={new JLabel("Student",SwingConstants.RIGHT),new JLabel("Name",SwingConstants.RIGHT),new JLabel("Marks",SwingConstants.RIGHT)};
	JTextField[] tf={new JTextField(20),new JTextField(20),new JTextField(5)};
	p1()
	{
		super("Student id");
		setSize(300,300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		p=new JPanel();
		p1=new JPanel();
		p2=new JPanel();
		//for(int i=0;i<3;i++) {
		//tf[i].setColumns(
		BoxLayout box=new BoxLayout(p2,BoxLayout.Y_AXIS);
		p.setLayout(new GridLayout(3,2));
		p2.setLayout(box);
		/*b[0].addActionListener(new ActionListener(){
		public void actionPerformed(ActionEvent e){
		if(n==0)
			JOptionPane.showMessageDialog(null,"Table Empty");
			
		else if(i>=n || i<0)
			JOptionPane.showMessageDialog(null,"No more records");
		else{i++;
		np(this);
		}}
		});
		b[1].addActionListener(new ActionListener(){
		public void actionPerformed(ActionEvent e){
		if(n==0)
			JOptionPane.showMessageDialog(this,"Table Empty");
			
		else if(i>=n || i<0)
			JOptionPane.showMessageDialog(this,"No more records");
		else{i--;
		np(this);
		}}
		});*/
		b[0].addActionListener(this);
		b[1].addActionListener(this);
		b[2].addActionListener(new ActionListener(){
		public void actionPerformed(ActionEvent e){
		System.exit(0);
		}
		});
		//ImageIcon i1=new ImageIcon("/home/karthik/java/icon/archive-symbolic.svg");
		/*JButton b1=new JButton("Save");
		JLabel l1=new JLabel("Date:",SwingConstants.RIGHT);
		JLabel l2=new JLabel("Downloader:",SwingConstants.CENTER);
		JPasswordField pf= new JPasswordField(20);
		JTextArea ta=new JTextArea(4,8);
		ta.setLineWrap(true);
		ta.setWrapStyleWord(true);
		JCheckBox cb=new JCheckBox("fast download\n",true);
		JRadioButton rb1=new JRadioButton("Mbps\n");
		JRadioButton rb2=new JRadioButton("kbps\n");
		ButtonGroup bg=new ButtonGroup();
		bg.add(rb1);
		bg.add(rb2);
		pf.setEchoChar('*');
		String[] str={"music","movie","photo","doc"};
		//b1.setSize(100,50);
		JComboBox cbx=new JComboBox(str);
		//for(int i=0;i<str.length;i++) cbx.addItem(str[i]);
		cbx.setEditable(true);
		JScrollPane sp=new JScrollPane(ta,ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED,ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
		p.add(sp);
		p.add(b1);
		p.add(l1);
		p.add(cb);
		p.add(l2);
		p.add(pf);
		p.add(cbx);
		p.add(rb1);
		p.add(rb2);*/
		p.add(l[0]);
		p.add(tf[0]);
		p.add(l[1]);
		p.add(tf[1]);
		p.add(l[2]);
		p.add(tf[2]);
		
		p1.add(b[1]);
		p1.add(b[0]);
		p1.add(b[2]);
		p2.add(p);
		p2.add(p1);
		add(p2);
		setLocationByPlatform(true);	
	
		
		pack();
		//JOptionPane.showMessageDialog(this,getSize().height);
		try{
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
			SwingUtilities.updateComponentTreeUI(this);
		}
		catch(Exception e)
		{
			System.out.println("Cant set look and feel"+e.getMessage());
			e.printStackTrace();
		}
		setVisible(true);
	}
	public void actionPerformed(ActionEvent e)
	{
	if(n==0)
			JOptionPane.showMessageDialog(null,"Table Empty");
			

	if(e.getSource()==b[0])
	{i++; if(i>=n){
			JOptionPane.showMessageDialog(null,"No more records");i--;b[0].setEnabled(false);}
		else { np(this); b[1].setEnabled(true);}
		}
		else if(e.getSource()==b[1])
		{i--; if(i<0){
			JOptionPane.showMessageDialog(null,"No more records");i++;b[1].setEnabled(false);}
		else {np(this);b[0].setEnabled(true);}
		}
		}
	public static void np(p1 s)
	{	
		
		s.tf[0].setText(std[i]);
		s.tf[1].setText(id[i]);
		s.tf[2].setText(marks[i]);
		
	}
	
	
		
	public static void main(String args[])throws SQLException
	{
		p1 s=new p1();
		
		
		 String url="jdbc:mysql://localhost";
	 String user="root";
	 String password="Kar$";
		
	
		try{
			Connection c=DriverManager.getConnection(url,user,password);
			System.out.println("Success");
			System.out.println("Creating statement...");
      Statement stmt = c.createStatement();
      String sql;
      sql = "SELECT * FROM test.stud";
      ResultSet rs = stmt.executeQuery(sql);

      //STEP 5: Extract data from result set
      while(rs.next()){
         //Retrieve by column name
         id[n]=rs.getString("Stdid");
         std[n]=rs.getString("Name");
         marks[n]=rs.getString("marks");
	n++;
         
      }
      JOptionPane.showMessageDialog(null,"Records extracted");
      System.out.println(n);
      for(int i=0;i<n;i++)
      {
      	System.out.println(id[i]+std[i]+marks[i]);
      	}
      	np(s);
      	
      //STEP 6: Clean-up environment
      rs.close();
      stmt.close();
      c.close();
		}
		catch(Exception e){e.printStackTrace();
		}
		
	}
		/*UIManager.LookAndFeelInfo[] laf=UIManager.getInstalledLookAndFeels();
		for(int i=0;i<laf.length;i++)
		{
			System.out.println("Class name: "+ laf[i].getClassName());
			System.out.println("Name: " + laf[i].getName() + "\n");
}*/
	
	
}
		
