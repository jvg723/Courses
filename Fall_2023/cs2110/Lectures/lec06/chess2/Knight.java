package chess2;

/**
 * Represents one of a player's knights in a game of chess.
 */
public class Knight extends Piece {

    /**
     * Create a new knight controlled by player `player` (1 or 2).
     * If `kingSide` is true, knight starts on king's side of board.
     */
    public Knight(int player, boolean kingSide) {
        super((player == 1) ? 0 : 7, kingSide ? 1 : 6, player);
    }

    @Override
    public boolean legalMove(int dstRow, int dstCol, Board board) {
        // A knight jumps two spaces in one direction, then one space in the orthogonal direction.
        int dx = Math.abs(col - dstCol);
        int dy = Math.abs(row - dstRow);
        return board.playerAt(dstRow, dstCol) != player() &&
                ((dx == 1 && dy == 2) || (dx == 2 && dy == 1));
    }
}
