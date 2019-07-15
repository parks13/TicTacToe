#include "tictactoewindow.h"
#include "ui_tictactoewindow.h"

TicTacToeWindow::TicTacToeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TicTacToeWindow),
    tttModel(new TTTModel)
{
    ui->setupUi(this);
    updateScreen();
}

TicTacToeWindow::~TicTacToeWindow()
{
    delete ui;
}

void TicTacToeWindow::updateScreen()
{
    //QString getCurrentBoard(); // "---XOXX--"
    //QString getWhosTurn(); // "X" or "O" or if somebody already won, return anything
    //bool hasSomeoneWon(); // return if somebody has won
    //QString whosWinner(); // return "X" or "O" if there's any winner. return anything if there's no winner yet

    QString cur = tttModel->getCurrentBoard();

    ui->board00->setText("" + cur[0]);
    ui->board01->setText("" + cur[1]);
    ui->board02->setText("" + cur[2]);
    ui->board10->setText("" + cur[3]);
    ui->board11->setText("" + cur[4]);
    ui->board12->setText("" + cur[5]);
    ui->board20->setText("" + cur[6]);
    ui->board21->setText("" + cur[7]);
    ui->board22->setText("" + cur[8]);

    ui->boardLabel->setText(cur.left(3) + '\n' + cur.mid(3, 3) + '\n' + cur.right(3));

    // if somebody has won?
    if (tttModel->hasSomeoneWon()) {
        QString msg = tttModel->whosWinner() + " has won!";
        ui->IBStatusLabel->setText(msg);
        ui->TBStatusLabel->setText(msg);

        // Disable all the text boxes and buttons to prevent user from keep playing the game
        ui->board00->setEnabled(false);
        ui->board01->setEnabled(false);
        ui->board02->setEnabled(false);
        ui->board10->setEnabled(false);
        ui->board11->setEnabled(false);
        ui->board12->setEnabled(false);
        ui->board20->setEnabled(false);
        ui->board21->setEnabled(false);
        ui->board22->setEnabled(false);
        ui->rowInput->setEnabled(false);
        ui->colInput->setEnabled(false);
        ui->pushButton->setEnabled(false);
    }
    else if (tttModel->getCurrentBoard().count(QLatin1Char('-')) == 0){
        // Draw
        QString msg = "DRAW!";
        ui->IBStatusLabel->setText(msg);
        ui->TBStatusLabel->setText(msg);

        // Disable all the text boxes and buttons to prevent user from keep playing the game
        ui->board00->setEnabled(false);
        ui->board01->setEnabled(false);
        ui->board02->setEnabled(false);
        ui->board10->setEnabled(false);
        ui->board11->setEnabled(false);
        ui->board12->setEnabled(false);
        ui->board20->setEnabled(false);
        ui->board21->setEnabled(false);
        ui->board22->setEnabled(false);
        ui->rowInput->setEnabled(false);
        ui->colInput->setEnabled(false);
        ui->pushButton->setEnabled(false);
    }
    else {
        // no winner yet
        QString msg = tttModel->getWhosTurn() + "'s turn";
        ui->IBStatusLabel->setText(msg);
        ui->TBStatusLabel->setText(msg);
    }
}

void TicTacToeWindow::on_board00_clicked()
{
    tttModel->put(0, 0);
    updateScreen();
}

void TicTacToeWindow::on_board01_clicked()
{
    tttModel->put(0, 1);
    updateScreen();
}

void TicTacToeWindow::on_board02_clicked()
{
    tttModel->put(0, 2);
    updateScreen();
}

void TicTacToeWindow::on_board10_clicked()
{
    tttModel->put(1, 0);
    updateScreen();
}

void TicTacToeWindow::on_board11_clicked()
{
    tttModel->put(1, 1);
    updateScreen();
}

void TicTacToeWindow::on_board12_clicked()
{
    tttModel->put(1, 2);
    updateScreen();
}

void TicTacToeWindow::on_board20_clicked()
{
    tttModel->put(2, 0);
    updateScreen();
}

void TicTacToeWindow::on_board21_clicked()
{
    tttModel->put(2, 1);
    updateScreen();
}

void TicTacToeWindow::on_board22_clicked()
{
    tttModel->put(2, 2);
    updateScreen();
}

void TicTacToeWindow::on_pushButton_clicked()
{
    int col = ui->colInput->text().toInt();
    int row = ui->rowInput->text().toInt();
    tttModel->put(row, col);
    updateScreen();
}

void TicTacToeWindow::on_resetButton_clicked()
{
    // do some cleanup work for your UI
    tttModel->reset();
    updateScreen();

    // Enable all the text boxes and buttons to prevent user from keep playing the game
    ui->board00->setEnabled(true);
    ui->board01->setEnabled(true);
    ui->board02->setEnabled(true);
    ui->board10->setEnabled(true);
    ui->board11->setEnabled(true);
    ui->board12->setEnabled(true);
    ui->board20->setEnabled(true);
    ui->board21->setEnabled(true);
    ui->board22->setEnabled(true);
    ui->rowInput->setEnabled(true);
    ui->colInput->setEnabled(true);
    ui->pushButton->setEnabled(true);
}















