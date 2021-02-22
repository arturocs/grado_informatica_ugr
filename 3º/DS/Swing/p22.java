import java.awt.*;
import javax.swing.JApplet;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class p22 extends JApplet {
  public void init(){
    setSize( 100, 100);
    JPanel panelSuperior= new JPanel();
    panelSuperior.setLayout(new BorderLayout());
    getContentPane().add(panelSuperior);//para acceder a JRootPane
    JLabel etiquetaHola= new JLabel("Hola a todo el mundo!");
    panelSuperior.add(etiquetaHola, BorderLayout.NORTH);     
   }
}
