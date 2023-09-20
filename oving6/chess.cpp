#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class ChessBoard {
public:
    enum class Color { WHITE,
        BLACK };
    function<void(const string &, const string &, const string &)> after_invalid_move;
    function<void(const string &, const string &, const string &)> after_piece_move;
    function<void(const string &, const string &)> remove_piece;
    function<void(const string &)> game_over;
    function<void(const string &)> no_piece;

    class Piece {
    public:
        Piece(Color color) : color(color) {}
        virtual ~Piece() {}
        virtual char identifier() const = 0;

        Color color;
        string color_string() const {
            if (color == Color::WHITE)
                return "white";
            else
                return "black";
        }

        /// Return color and type of the chess piece
        virtual string type() const = 0;

        /// Returns true if the given chess piece move is valid
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
    };

    class King : public Piece {
    public:
        King(Color color) : Piece(color) {}

        char identifier() const override {
            return color == Color::WHITE ? 'K' : 'k';
        }

        string type() const override {
            return color_string() + " king";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            int dx = abs(from_x - to_x);
            int dy = abs(from_y - to_y);
            return dx <= 1 && dy <= 1;
        }

    };

    class Knight : public Piece {
    public:
        Knight(Color color) : Piece(color) {}

        char identifier() const override {
            return color == Color::WHITE ? 'N' : 'n';
        }

        string type() const override {
            return color_string() + " knight";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            int dx = abs(from_x - to_x);
            int dy = abs(from_y - to_y);
            return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
        }
    };

    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for (auto &square_column : squares)
            square_column.resize(8);
    }

    /// 8x8 squares occupied by 1 or 0 chess pieces
    vector<vector<unique_ptr<Piece>>> squares;

    /// Move a chess piece if it is a valid move.
    /// Does not test for check or checkmate.
    bool move_piece(const string &from, const string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;

        auto &piece_from = squares[from_x][from_y];
        if (piece_from) {
            if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
                after_piece_move(piece_from->type(), from, to);
                auto &piece_to = squares[to_x][to_y];
                if (piece_to) {
                    if (piece_from->color != piece_to->color) {
                        remove_piece(piece_to->type(), to);
                        if (auto king = dynamic_cast<King *>(piece_to.get()))
                            game_over(king->color_string());
                    } else {
                        // piece in the from square has the same color as the piece in the to square
                        after_invalid_move(piece_from->type(), from, to);
                        return false;
                    }
                }
                piece_to = move(piece_from);
                return true;
            } else {
                after_invalid_move(piece_from->type(), from, to);
                return false;
            }
        } else {
            no_piece(from);
            return false;
        }
    }
};

class ChessBoardPrint {
private:
    ChessBoard &board;
public:
    ChessBoardPrint(ChessBoard &board) : board(board) {
        board.after_invalid_move = [](const string &type, const string &from, const string &to) {
            cout << "can not move " << type << " from " << from << " to " << to << endl;
        };

        board.no_piece = [](const string &from) {
            cout << "no piece at " << from << endl;
        };

        board.after_piece_move = [this](const string &type, const string &from, const string &to) {
            cout << type << " is moving from " << from << " to " << to << endl;
            print_board();
        };

        board.remove_piece = [](const string &type, const string &to) {
            cout << type << " is being removed from " << to << endl;
        };

        board.game_over = [](const string &color_string) {
            cout << color_string << " lost the game" << endl;
        };


    }
    void print_board() {
        for (int y = 7; y >= 0; --y) {
            for (int x = 0; x < 8; ++x) {
                if (board.squares[x][y]) {
                    cout << board.squares[x][y]->identifier() << ' ';
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
    }

};

int main() {
    ChessBoard board;
    ChessBoardPrint print(board);

    board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
    board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
    board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

    board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
    board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
    board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

    cout << "Invalid moves:" << endl;
    board.move_piece("e3", "e2");
    board.move_piece("e1", "e3");
    board.move_piece("b1", "b2");
    cout << endl;

    cout << "A simulated game:" << endl;
    board.move_piece("e1", "e2");
    board.move_piece("g8", "h6");
    board.move_piece("b1", "c3");
    board.move_piece("h6", "g8");
    board.move_piece("c3", "d5");
    board.move_piece("g8", "h6");
    board.move_piece("d5", "f6");
    board.move_piece("h6", "g8");
    board.move_piece("f6", "e8");
}