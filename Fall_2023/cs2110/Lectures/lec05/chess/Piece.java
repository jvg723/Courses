package chess;

/**
 * Can determine legal moves as a chess piece.
 */
public interface Piece {
    /**
     * Return whether this piece is able to move to location (`dstRow`, `dstCol`) from its current
     * position, given board configuration `board`.
     */
    boolean legalMove(int dstRow, int dstCol, Board board);
}
