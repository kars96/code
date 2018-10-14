import javax.swing.*;
public class swtest extends JFrame
{
	JPanel p;
	swtest()
	{
		super("My first window");
		setSize(100,400);
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		p=new JPanel();
		//ImageIcon i1=new ImageIcon("/home/karthik/java/icon/archive-symbolic.svg");
		JButton b1=new JButton("Save");
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
		p.add(rb2);
		add(p);
		
		//pack();
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
	public static void main(String args[])
	{
		swtest s=new swtest();
		UIManager.LookAndFeelInfo[] laf=UIManager.getInstalledLookAndFeels();
		for(int i=0;i<laf.length;i++)
		{
			System.out.println("Class name: "+ laf[i].getClassName());
			System.out.println("Name: " + laf[i].getName() + "\n");
}
	
	}
}
		
