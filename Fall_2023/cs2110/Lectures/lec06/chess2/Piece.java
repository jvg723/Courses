package chess2;

/**
 * Represents a chess piece.  Subclasses are responsible for determining legal moves.
 */
public abstract class Piece {
    /**
     * The row (0-7) this piece is currently on.
     */
    protected int row;

    /**
     * The column (0-7) this piece is currently in.
     */
    protected int col;

    /**
     * Which player (1 or 2) controls this piece.
     */
    private int player;

    /**
     * Initialize this piece so it is controlled by player `player` (1 or 2) and is initially at
     * position (`row`, `col`).
     */
    protected Piece(int row, int col, int player) {
        this.row = row;
        this.col = col;
        this.player = player;
    }

    /**
     * Which player (1 or 2) controls this piece.
     */
    public int player() {
        return player;
    }

    /**
     * Return whether this piece is able to move to location (`dstRow`, `dstCol`) from its current
     * position, given board configuration `board`.
     */
    public abstract boolean legalMove(int dstRow, int dstCol, Board board);
}
