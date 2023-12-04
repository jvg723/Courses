package chess;

/**
 * Represents a knight piece in chess.
 */
public class Knight implements Piece {
    /**
     * The row (0-7) this piece is currently on.
     */
    private int row;

    /**
     * The column (0-7) this piece is currently in.
     */
    private int col;

    /**
     * Which player (1 or 2) controls this piece.
     */
    private int player;

    /**
     * Create a new knight controlled by player `player` (1 or 2).
     * If `kingSide` is true, knight starts on king's side of board.
     */
    public Knight(int player, boolean kingSide) {
        this.player = player;
        row = (player == 1) ? 0 : 7;
        col = kingSide ? 1 : 6;
    }

    @Override
    public boolean legalMove(int dstRow, int dstCol, Board board) {
        // A knight jumps two spaces in one direction, then one space in the orthogonal direction.
        int dx = Math.abs(col - dstCol);
        int dy = Math.abs(row - dstRow);
        return board.playerAt(dstRow, dstCol) != player &&
                ((dx == 1 && dy == 2) || (dx == 2 && dy == 1));
    }
}
