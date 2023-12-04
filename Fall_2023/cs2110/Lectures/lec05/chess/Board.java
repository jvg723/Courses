package chess;

/**
 * Can provide information about the state of a chess board.
 */
public interface Board {
    /**
     * Return 0 if position (`row`, `col`) is empty, 1 if occupied by a white piece, or 2 if
     * occupied by a black piece.
     */
    int playerAt(int row, int col);
}
