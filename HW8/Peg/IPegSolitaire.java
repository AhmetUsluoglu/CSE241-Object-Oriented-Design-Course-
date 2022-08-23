package Peg;

/**
 * Peg Solitaire Interface.
 */
public interface IPegSolitaire {

    /**
     * Sets the needs for user interface ex: frames, panels, labels buttons etc.
     */
    void setgame();

    /**
     * Recolors the pegs after an action is done on the board.
     */
    void repaint();

    /**
     * Copies Booard to undoBoard before a move made so undo button can retrieve the previous board.
     */
    void saveUndo();

    /**
     * Returns number of legs left in the Board.
     * @return number of pegs left.
     */
    int boardScore();

    /**
     * Controls the end game situation to determine if the game is ended or not.
     * @return true if game is ended.
     */
    boolean endGame();

    /**
     * Controls the given move. If the move is valid or not.
     * @return true if the move is possible.
     */
    boolean check();

    /**
     * Makes given move.
     */
    void move();

    /**
     * Creates random move values.
     */
    void get_randomMove();

    /**
     * Creates and fills the Boards with given board type.
     */
    void initialize();

    /**
     * Plays one move.
     */
    void playAuto();

    /**
     * Plays until the game is ended.
     */
    void playAutoAll();

    /**
     * Loads a game board from a .txt file in the out/ directory.
     */
    void load();

    /**
     * Saves the current board to file as .txt file to the out/directory.
     * User does not need to type .txt file extension.
     */
    void save();

}
