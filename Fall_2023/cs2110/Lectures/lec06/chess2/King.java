package chess2;

/**
 * Represents a player's king in a game of chess.
 */
public class King extends Piece {

    /**
     * Whether this King has moved at least once (and therefore may not castle with a rook).
     */
    boolean hasMoved;

    /**
     * Create a new king controlled by player `player` (1 or 2).
     */
    public King(int player) {
        super((player == 1) ? 0 : 7, 3, player);
        hasMoved = false;
    }

    @Override
    public boolean legalMove(int dstRow, int dstCol, Board board) {
        // A king moves one space in either direction, or may "castle" with a rook if neither has
        // moved and the row is clear in between.
        int dx = Math.abs(col - dstCol);
        int dy = Math.abs(row - dstRow);
        // Note: the dx=dy=0 case is handled by the player check
        return (board.playerAt(dstRow, dstCol) != player() &&
                dx <= 1 && dy <= 1) ||
                (!hasMoved && canCastle(dstRow, dstCol, board));
    }

    /**
     * Return whether this king can castle to position (`dstRow`, `dstCol`) given board
     * configuration `board`.
     */
    public boolean canCastle(int dstRow, int dstCol, Board board) {
        throw new UnsupportedOperationException("Not yet implemented");
    }
}
