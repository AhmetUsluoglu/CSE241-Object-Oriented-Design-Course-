/**
 * @author Ahmet Usluoglu 1801042602
 * @version Homework 8
 * A pegsolitaire game with grapic user interface.
 * Only need to compile and run this driver code.
 * javac test.java
 * java test
 *
 * To be able to play the game manually:
 * first click to the peg(orange) that you want to move, then click to an empty(grey) space to move it to there.
 * cyan indicates the borders.
 */

import Peg.PegSolitaire;

import java.awt.image.BufferedImage;
import java.io.File;
import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.awt.event.ActionEvent;

/**
 * Driver Class
 */
public class test
{
    /**
     * Main for driver code.
     * @param args command line argument.
     */
    public static void main(String[] args)
    {
        /**
         * Creating a main frame for game board selection.
         */
        final JFrame frame = new JFrame();
        // Adding 5 images of different boards.
        try{

            JPanel panel1 = new JPanel();
            panel1.setBounds(0,10,200,200);
            BufferedImage image1 = ImageIO.read(new File("images/peg1.png"));
            JLabel pic1 = new JLabel(new ImageIcon(image1));
            panel1.add(pic1);
            frame.add(panel1);

            JPanel panel2 = new JPanel();
            panel2.setBounds(200,10,200,200);
            BufferedImage image2 = ImageIO.read(new File("images/peg2.png"));
            JLabel pic2 = new JLabel(new ImageIcon(image2));
            panel2.add(pic2);
            frame.add(panel2);
            
            JPanel panel3 = new JPanel();
            panel3.setBounds(400,10,200,200);
            BufferedImage image3 = ImageIO.read(new File("images/peg3.png"));
            JLabel pic3 = new JLabel(new ImageIcon(image3));
            panel3.add(pic3);
            frame.add(panel3);

            JPanel panel4 = new JPanel();
            panel4.setBounds(600,10,200,200);
            BufferedImage image4 = ImageIO.read(new File("images/peg4.png"));
            JLabel pic4 = new JLabel(new ImageIcon(image4));
            panel4.add(pic4);
            frame.add(panel4);

            JPanel panel5 = new JPanel();
            panel5.setBounds(800,10,200,200);
            BufferedImage image5 = ImageIO.read(new File("images/peg5.png"));
            JLabel pic5 = new JLabel(new ImageIcon(image5));
            panel5.add(pic5);
            frame.add(panel5);

        }
        catch (IOException e) {e.toString();}

        //Creating label and buttons.
        JLabel label1 = new JLabel("Please choose a board type");
        label1.setBounds(400, 300, 250, 20);

        JRadioButton rb1 = new JRadioButton("1)");
        JRadioButton rb2 = new JRadioButton("2)");
        JRadioButton rb3 = new JRadioButton("3)");
        JRadioButton rb4 = new JRadioButton("4)");
        JRadioButton rb5 = new JRadioButton("5)");

        rb1.setBounds(90,210,50,20);
        rb2.setBounds(290,210,50,20);
        rb3.setBounds(490,210,50,20);
        rb4.setBounds(690,210,50,20);
        rb5.setBounds(890,210,50,20);

        // Grouping the radio buttons
        ButtonGroup bg = new ButtonGroup();    
        bg.add(rb1); bg.add(rb2); bg.add(rb3); bg.add(rb4); bg.add(rb5); 

        // Confirmation "Select" button.
        JButton select = new JButton("Select");
        select.setBounds(400, 250, 200, 50);

        // Adding an action listener for select button and overriding it to start the peg solitaire game.
        select.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e) {

                if(rb1.isSelected())
                {
                    PegSolitaire game = new PegSolitaire();
                }
                else if(rb2.isSelected())
                {
                    PegSolitaire game = new PegSolitaire(2);
                }
                else if(rb3.isSelected())
                {
                    PegSolitaire game = new PegSolitaire(3);
                }
                else if(rb4.isSelected())
                {
                    PegSolitaire game = new PegSolitaire(4);
                }
                else if(rb5.isSelected())
                {
                    PegSolitaire game = new PegSolitaire(5);
                }
            }
        });

        /*Main Frame Settings*/
        frame.add(label1);
        frame.add(rb1); frame.add(rb2); frame.add(rb3); frame.add(rb4); frame.add(rb5); 
        frame.add(select);
        frame.setBounds(500,250,1000,400);
        frame.setLayout(null);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(frame.DISPOSE_ON_CLOSE);

    }
}
