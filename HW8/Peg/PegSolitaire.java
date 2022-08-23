// Javadoc comments are in the interface file. Please Check that.

package Peg;

import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Objects;

/**
 * Implementation Class for Peg Solitaire game.
 */
public class PegSolitaire implements Cloneable, IPegSolitaire
{
    /**
     * Enum for peg types: peg, empty, free.
     */
    private enum pegType {
        empty, peg, free
    }

    // Fields for peg information and move.
    private int row;
    private int column;
    private int size;
    private int selectedBoard;
    private char Direction;

    // Fields for playing with mouse click
    private int firstRow, firstCol, secondRow, secondCol;
    private boolean firstSelected = false;

    //Fields for keeping the board information.
    private ArrayList<ArrayList<pegType>> Board;
    private ArrayList<ArrayList<pegType>> undoBoard;

    // Fields needed for graphic user interface
    private JButton[][] buttonGrid;
    private JPanel menuPanel, boardPanel;
    private JFrame gameFrame;
    private JButton playAuto, playAutoAll, save, undo, reset, load;
    private JLabel score;

    /**
     * No Argument Constructor initialize Board to first board.
     */
    public PegSolitaire() {
        selectedBoard = 1;
        initialize();
        setgame();
        saveUndo();
    }

    /**
     * A constructor that takes one int parameter and assigns the value to selectedBoard.
     * @param select value for selected board type.
     */
    public PegSolitaire(int select) {
        selectedBoard = select;
        initialize();
        setgame();
        saveUndo();
    }

    @Override
    public void setgame() {
        //creating a panel for game board.
        boardPanel = new JPanel(new GridLayout(size,size,3,3));
        boardPanel.setBounds(0,0,700,700);
        boardPanel.setBackground(Color.CYAN);

        buttonGrid = new JButton[size][size];
        // Creating buttons for every peg and adding an action listener to make it playable by clicking the pegs.
        for(int i = 0 ; i < size ; ++i) {
            for(int j = 0 ; j < size ; ++j) {
                JButton btn = new JButton();
                btn.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        for (int i = 0; i < size; ++i) {
                            for (int j = 0; j < size; ++j) {
                                if (buttonGrid[i][j].equals(btn)) {
                                    if (Board.get(i).get(j) == pegType.peg && !firstSelected) {
                                        firstRow = i; firstCol = j;
                                        firstSelected = true;
                                        break;
                                    }
                                    else if (Board.get(i).get(j) == pegType.empty && firstSelected) {
                                        secondRow = i; secondCol = j;
                                        int distance1 = firstRow - secondRow;
                                        int distance2 = firstCol - secondCol;
                                        if(firstRow == secondRow && (distance2 == 2 || distance2 == -2))
                                        {
                                            if(Board.get(firstRow).get(firstCol - distance2/2) == pegType.peg)
                                            {
                                                saveUndo();
                                                Board.get(firstRow).set(firstCol - distance2/2,pegType.empty);
                                                Board.get(firstRow).set(firstCol,pegType.empty);
                                                Board.get(secondRow).set(secondCol,pegType.peg);
                                                repaint();
                                                score.setText("\tPegs Left : " + boardScore());
                                            }
                                        }
                                        else if(firstCol == secondCol && (distance1 == 2 || distance1 == -2))
                                        {
                                            if(Board.get(firstRow - distance1/2).get(firstCol) == pegType.peg)
                                            {
                                                saveUndo();
                                                Board.get(firstRow - distance1/2).set(firstCol,pegType.empty);
                                                Board.get(firstRow).set(firstCol,pegType.empty);
                                                Board.get(secondRow).set(secondCol,pegType.peg);
                                                repaint();
                                                score.setText("\tPegs Left : " + boardScore());
                                            }
                                        }
                                        firstSelected = false; break;
                                    }
                                }
                            }
                        }
                        if(!endGame()) JOptionPane.showMessageDialog(gameFrame, "Game is ended your score is " + boardScore());
                    }
                });
                // Coloring the board for the first time
                if(Board.get(i).get(j) == pegType.peg) btn.setBackground(Color.ORANGE);
                else if(Board.get(i).get(j) == pegType.free)
                {
                    btn.setBackground(Color.CYAN);
                    btn.setBorderPainted(false);
                }
                else if(Board.get(i).get(j) == pegType.empty) btn.setBackground(Color.LIGHT_GRAY);
                // Adding current button to buttonGrid and to boardPanel.
                buttonGrid [i][j] = btn;
                boardPanel.add(btn);
            }
        }

        // Creating a menu panel for buttons and labels.
        menuPanel = new JPanel();
        menuPanel.setLayout(new GridLayout(10,1,5,5));
        menuPanel.setBounds(700,0,200,700);

        // playAuto button calls playAuto function to play one move automatically.
        playAuto = new JButton("Play Auto");
        playAuto.setBounds(700,0,40,20);
        playAuto.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {if (endGame()) playAuto();}});

        // playAutoAll button calls playAutoAll function to play until the end automatically.
        playAutoAll = new JButton("Play Auto All");
        playAutoAll.setBounds(700,0,40,20);
        playAutoAll.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {playAutoAll();}});

        // Reset button resets game to it's initial state.
        reset = new JButton("Reset");
        reset.setBounds(700,0,40,20);
        reset.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {initialize(); repaint();score.setText("\tPegs Left : " + boardScore());}});

        // Undo button updates board of one move ago.
        undo = new JButton("Undo");
        undo.setBounds(700,0,40,20);
        undo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Board = undoBoard;
                repaint();
                score.setText("\tPegs Left : " + boardScore());
            }});

        // Load button calls load function.
        load = new JButton("Load");
        load.setBounds(700,0,40,20);
        load.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {load();}});

        // Save button calls save function.
        save = new JButton("Save");
        save.setBounds(700,0,40,20);
        save.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {save();}});

        score = new JLabel("\tPegs Left : " + boardScore());
        score.setSize(40,20);

        // Adding buttons to menuPanel.
        menuPanel.add(playAuto);
        menuPanel.add(playAutoAll);
        menuPanel.add(reset);
        menuPanel.add(undo);
        menuPanel.add(load);
        menuPanel.add(save);
        menuPanel.add(score);

        // gameFrame configurations.
        gameFrame = new JFrame();
        gameFrame.add(boardPanel);
        gameFrame.add(menuPanel);
        gameFrame.setBounds(0,0,920,740);

        gameFrame.setDefaultCloseOperation(gameFrame.DISPOSE_ON_CLOSE);
        gameFrame.setBackground(Color.CYAN);
        gameFrame.setLayout(null);
        gameFrame.setVisible(true);
    }

    @Override
    public void repaint() {
        for (int x = 0; x < size; ++x)
        {
            for (int y = 0; y < size; ++y)
            {
                if (Board.get(x).get(y) == pegType.peg) buttonGrid[x][y].setBackground(Color.ORANGE);
                else if(Board.get(x).get(y) == pegType.empty) buttonGrid[x][y].setBackground(Color.LIGHT_GRAY);
                else buttonGrid[x][y].setBackground(Color.CYAN);
            }
        }
    }

    @Override
    public void saveUndo() {
        undoBoard = new ArrayList<>();
        for(int i = 0; i < size; i++)
        {
            undoBoard.add(new ArrayList<>());
            for(int j = 0; j < size; j++) undoBoard.get(i).add((Board.get(i).get(j)));
        }
    }

    @Override
    public int boardScore() {
        int counter = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if(Board.get(i).get(j) == pegType.peg) counter++;
            }
        }
        return counter;
    }

    @Override
    public boolean endGame() {
        boolean end = false;
        char[] directionArray = new char[]{'U','D','R','L'};
        
        for(int i = 0; i < size; ++i)
        {
            for(int j = 0; j < size; ++j)
            {
                for(int k = 0;k < 4; ++k)
                {
                    row = i; column = j; Direction = directionArray[k];
                    /*If there is a possible move Check returns 1 game is not ended, else endGame equals 0*/
                    end = check();
                    /*If there is any valid move Game is not ended*/
                    if(end)
                    {
                        i = size; j = size; k = 4;
                    } 
                }
            }
        }
        /*If no valid move is possible endGame returns 0 by default*/
        return end;
    }

    @Override
    public boolean check() {
        boolean flag = false;

        switch (Direction)
        {
            case 'U':/*Up*/
                if(Board.get(row).get(column) == pegType.peg && (row != 0 && row != 1))
                {
                    if(Board.get(row-1).get(column) == pegType.peg && Board.get(row-2).get(column) == pegType.empty)
                    {
                    flag = true;
                    }
                }
                break;
            case 'D':/*Down*/
                if(Board.get(row).get(column) == pegType.peg && (row != size -1 && row != size -2))
                {
                    if(Board.get(row + 1).get(column) == pegType.peg && Board.get(row + 2).get(column) == pegType.empty)
                    {
                    flag = true;
                    }
                }
                break;
            case 'R':/*Right*/
                if(Board.get(row).get(column) == pegType.peg && (column != size-1 && column != size -2))
                {
                    if(Board.get(row).get(column + 1) == pegType.peg && Board.get(row).get(column + 2) == pegType.empty)
                    {
                    flag = true;
                    }
                }
                break;
            case 'L':/*Left*/
                if(Board.get(row).get(column) == pegType.peg && (column != 0 && column != 1))
                {
                    if(Board.get(row).get(column - 1) == pegType.peg && Board.get(row).get(column - 2) == pegType.empty)
                    {
                    flag = true;
                    }
                }
                break;
            
            default:
                break;
        }
        return flag;
    }

    @Override
    public void move() {
        saveUndo();
        switch (Direction)
        {
            case 'U':/*Up*/
                Board.get(row).set(column,pegType.empty); buttonGrid[row][column].setBackground(Color.LIGHT_GRAY);
                Board.get(row-1).set(column,pegType.empty); buttonGrid[row-1][column].setBackground(Color.LIGHT_GRAY);
                Board.get(row-2).set(column,pegType.peg); buttonGrid[row-2][column].setBackground(Color.ORANGE);
                break;
            case 'D':/*Down*/
                Board.get(row).set(column,pegType.empty); buttonGrid[row][column].setBackground(Color.LIGHT_GRAY);
                Board.get(row+1).set(column,pegType.empty); buttonGrid[row+1][column].setBackground(Color.LIGHT_GRAY);
                Board.get(row+2).set(column,pegType.peg);   buttonGrid[row+2][column].setBackground(Color.ORANGE);
                break;
            case 'R':/*Right*/
                Board.get(row).set(column,pegType.empty); buttonGrid[row][column].setBackground(Color.LIGHT_GRAY);
                Board.get(row).set(column+1,pegType.empty); buttonGrid[row][column+1].setBackground(Color.LIGHT_GRAY);
                Board.get(row).set(column+2,pegType.peg);   buttonGrid[row][column+2].setBackground(Color.ORANGE);
                break;
            case 'L':/*Left*/
                Board.get(row).set(column,pegType.empty); buttonGrid[row][column].setBackground(Color.LIGHT_GRAY);
                Board.get(row).set(column-1,pegType.empty); buttonGrid[row][column-1].setBackground(Color.LIGHT_GRAY);
                Board.get(row).set(column-2,pegType.peg);   buttonGrid[row][column-2].setBackground(Color.ORANGE);
                break;
            default:
                break;
        }
    }

    @Override
    public void get_randomMove() {
        char[] directionArray = new char[]{'U','D','R','L'};
        Direction =  directionArray[(int)(Math.random()*4)]; 
        row = (int)(Math.random() * size);
        column = (int)(Math.random() * size);
    }

    @Override
    public void initialize() {
        Board = new ArrayList<ArrayList<pegType>>();
        
        switch (selectedBoard) 
        {
                case 1:
                size = 7;
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.peg,pegType.peg,pegType.peg,pegType.empty,pegType.peg,pegType.peg,pegType.peg)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free)));
                break;
            
                case 2:
                size = 9;
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.empty,pegType.peg,pegType.peg,pegType.peg,pegType.peg)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free,pegType.free)));

                break;
            
                case 3:
                size = 8;
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.peg,pegType.peg,pegType.peg,pegType.empty,pegType.peg,pegType.peg,pegType.peg,pegType.peg)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free,pegType.free)));
                break;
            
                case 4:
                size = 7;
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.peg,pegType.peg,pegType.peg,pegType.empty,pegType.peg,pegType.peg,pegType.peg)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free)));
                break;
            
                case 5:
                size = 9;
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.free,pegType.free,pegType.peg,pegType.free,pegType.free,pegType.free,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.empty,pegType.peg,pegType.peg,pegType.peg,pegType.peg)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.free,pegType.peg,pegType.peg,pegType.peg,pegType.free,pegType.free,pegType.free)));
                Board.add(new ArrayList<>(Arrays.asList(pegType.free,pegType.free,pegType.free,pegType.free,pegType.peg,pegType.free,pegType.free,pegType.free,pegType.free)));

                break;
        
            default:
                throw new IllegalStateException("Invalid Board Type");
        }
    }

    @Override
    public void playAuto() {
        while (true) {
            get_randomMove();
            if(check())
            {
                move(); break;
            }
        }
        if(!endGame()) JOptionPane.showMessageDialog(gameFrame, "Game is ended your score is " + boardScore());
        score.setText("\tPegs Left : " + boardScore());
    }

    @Override
    public void playAutoAll() {while (endGame()) {playAuto();}}

    @Override
    public void load() {
        JFileChooser explorer = new JFileChooser("out/");
        explorer.setDialogTitle("Select a .txt file");
        explorer.setAcceptAllFileFilterUsed(false);
        explorer.setApproveButtonText("Load Board");
        FileNameExtensionFilter restrict = new FileNameExtensionFilter("Only .txt files", "txt");
        explorer.addChoosableFileFilter(restrict);
        int respond = explorer.showOpenDialog(null);
        if (respond == JFileChooser.APPROVE_OPTION) {
            int len = 0;
            String board = "";
            try {
                FileReader fr = new FileReader(explorer.getSelectedFile());
                int content;
                while ((content = fr.read()) != -1) {
                    if ((char) content != '\n') {
                        board = board + (char) content;
                    } else len++;
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            size = len;

            Board.clear();
            Board = new ArrayList<ArrayList<pegType>>();
            char pChar;
            for (int i = 0; i < len; i++) {
                pegType[] pegs = new pegType[len];
                for (int j = 0; j < len; j++) {
                    pChar = board.charAt(i * len + j);

                    if (pChar == 'P') {
                        pegs[j] = pegType.peg;
                    } else if (pChar == '.') {
                        pegs[j] = pegType.empty;
                    } else if (pChar == ' ') {
                        pegs[j] = pegType.free;
                    }
                }
                Board.add(new ArrayList<>(Arrays.asList(pegs)));
            }
            gameFrame.dispatchEvent(new WindowEvent(gameFrame, WindowEvent.WINDOW_CLOSING));
            setgame();
            saveUndo();

            if (len == 8) selectedBoard = 3;
            else if (len == 7) {
                if (Board.get(1).get(1) == pegType.free) selectedBoard = 4;
                else selectedBoard = 1;
            }
            else if (len == 9) {
                if (Board.get(3).get(0) == pegType.peg) selectedBoard = 2;
                else selectedBoard = 5;
            }
            JOptionPane.showMessageDialog(gameFrame, "Game loaded");
        }
    }

    @Override
    public void save() {
        JFileChooser explorer = new JFileChooser("out/");
        explorer.setDialogTitle("Select a .txt file");
        explorer.setAcceptAllFileFilterUsed(false);
        explorer.setApproveButtonText("Save Board");
        FileNameExtensionFilter restrict = new FileNameExtensionFilter("Only .txt files", "txt");
        explorer.addChoosableFileFilter(restrict);
        int respond = explorer.showSaveDialog(null);

        if (respond == JFileChooser.APPROVE_OPTION) {
            try {
                FileWriter writer = new FileWriter(explorer.getSelectedFile() + ".txt");
                writer.write(toString());
                writer.close();
            } catch (IOException e) {
                JOptionPane.showMessageDialog(gameFrame, "File Error");
            }
            JOptionPane.showMessageDialog(gameFrame, "Game saved");
        }
    }

    /**
     * Overriden toString function.
     * @return a string that contains board state.
     */
    @Override
    public String toString() {
        String temp = "";
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if(Board.get(i).get(j) == pegType.peg) temp += "P";
                else if(Board.get(i).get(j) == pegType.empty) temp += ".";
                else if(Board.get(i).get(j) == pegType.free) temp += " ";
            }
            temp +=("\n");
        }
        return temp;
    }

    /**
     * Overriden Clone function.
     * @return a PegSolitaire reference.
     */
    @Override
    public  PegSolitaire clone() {
        PegSolitaire Clone = null;
        try {Clone = (PegSolitaire) super.clone();}
        catch (CloneNotSupportedException e){System.out.println(e.toString()); return null;}
        return  Clone;
    }

    /**
     * Overriden hashCode function
     * @return returns the hash code of the Object.
     */
    @Override
    public int hashCode() {return Objects.hash(Board);}
}
