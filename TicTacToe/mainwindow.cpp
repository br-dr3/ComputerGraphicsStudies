#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    this->setFixedSize(QSize(442, 480));
    QList<QPushButton*> buttons = this->findChildren<QPushButton *>();

    for (QPushButton *b : buttons) {
        if(b->objectName() != "newGameButton") {
            makeButtonInvisible(b);
            b->setEnabled(false);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: makeButtonInvisible(QPushButton* b) {
    b->setFlat(true);
    b->setText("");
}

void MainWindow :: newGame() {
    QList<QPushButton*> buttons = this->findChildren<QPushButton *>();

    for (QPushButton *b : buttons) {
        if(b->objectName() != "newGameButton") {
            makeButtonInvisible(b);
            b->setEnabled(true);
        }
    }

    turn = 0;
    player1 = (ui->player1Name->toPlainText() == "")? "Player 1" : ui->player1Name->toPlainText();
    player2 = (ui->player2Name->toPlainText() == "")? "Player 2" : ui->player2Name->toPlainText();
}

void MainWindow :: makeButtonVisible(QPushButton *button) {
    button->setFlat(true);
}

void MainWindow :: whenClicked(QPushButton* b) {
    makeButtonVisible(b);
    b->setEnabled(false);
    b->setStyleSheet("color: rgb(0, 0, 0)");
    (turn == 0)? b->setText("X") : b->setText("O");
    (turn == 0)? turn = 1 : turn = 0;
}

void MainWindow::on_button00_clicked()
{
    whenClicked(ui->button00);
    QMessageBox message;
    if (checkWinner()) {
        if(turn == 0) {
            message.setText(player2 + " won!");
        } else {
            message.setText(player1 + " won!");
        }
        message.exec();
        makeButtonsDisabled();
    }

    if(checkDraw()) {
        message.setText("Draw!");
        message.exec();
        makeButtonsDisabled();
    }
}

void MainWindow::on_button01_clicked()
{
    whenClicked(ui->button01);
    QMessageBox message;
    if (checkWinner()) {
        if(turn == 0) {
            message.setText(player2 + " won!");
        } else {
            message.setText(player1 + " won!");
        }
        message.exec();
        makeButtonsDisabled();
    }

    if(checkDraw()) {
        message.setText("Draw!");
        message.exec();
        makeButtonsDisabled();
    }
}

void MainWindow::on_button02_clicked()
{
    whenClicked(ui->button02);
    QMessageBox message;
    if (checkWinner()) {
        if(turn == 0) {
            message.setText(player2 + " won!");
        } else {
            message.setText(player1 + " won!");
        }
        message.exec();
        makeButtonsDisabled();
    }

    if(checkDraw()) {
        message.setText("Draw!");
        message.exec();
        makeButtonsDisabled();
    }
}


void MainWindow::on_button10_clicked()
{
    whenClicked(ui->button10);
    QMessageBox message;
    if (checkWinner()) {
        if(turn == 0) {
            message.setText(player2 + " won!");
        } else {
            message.setText(player1 + " won!");
        }
        message.exec();
        makeButtonsDisabled();
    }

    if(checkDraw()) {
        message.setText("Draw!");
        message.exec();
        makeButtonsDisabled();
    }
}

void MainWindow::on_button11_clicked()
{
    whenClicked(ui->button11);
    QMessageBox message;
    if (checkWinner()) {
        if(turn == 0) {
            message.setText(player2 + " won!");
        } else {
            message.setText(player1 + " won!");
        }
        message.exec();
        makeButtonsDisabled();
    }

    if(checkDraw()) {
        message.setText("Draw!");
        message.exec();
        makeButtonsDisabled();
    }
}

void MainWindow::on_button12_clicked()
{
    whenClicked(ui->button12);
    QMessageBox message;
    if (checkWinner()) {
        if(turn == 0) {
            message.setText(player2 + " won!");
        } else {
            message.setText(player1 + " won!");
        }
        message.exec();
        makeButtonsDisabled();
    }

    if(checkDraw()) {
        message.setText("Draw!");
        message.exec();
        makeButtonsDisabled();
    }
}

void MainWindow::on_button20_clicked()
{
    whenClicked(ui->button20);
    QMessageBox message;
    if (checkWinner()) {
        if(turn == 0) {
            message.setText(player2 + " won!");
        } else {
            message.setText(player1 + " won!");
        }
        message.exec();
        makeButtonsDisabled();
    }

    if(checkDraw()) {
        message.setText("Draw!");
        message.exec();
        makeButtonsDisabled();
    }
}

void MainWindow::on_button21_clicked()
{
    whenClicked(ui->button21);
    QMessageBox message;
    if (checkWinner()) {
        if(turn == 0) {
            message.setText(player2 + " won!");
        } else {
            message.setText(player1 + " won!");
        }
        message.exec();
        makeButtonsDisabled();
    }

    if(checkDraw()) {
        message.setText("Draw!");
        message.exec();
        makeButtonsDisabled();
    }
}

void MainWindow::on_button22_clicked()
{
    whenClicked(ui->button22);
    QMessageBox message;
    if (checkWinner()) {
        if(turn == 0) {
            message.setText(player2 + " won!");
        } else {
            message.setText(player1 + " won!");
        }
        message.exec();
        makeButtonsDisabled();
    }

    if(checkDraw()) {
        message.setText("Draw!");
        message.exec();
        makeButtonsDisabled();
    }
}

bool MainWindow::checkWinner() {

    bool line1 = ui->button00->text() == ui->button01->text()
            && ui->button01->text() == ui->button02->text()
            && ui->button00->text() != "";
    bool line2 = ui->button10->text() == ui->button11->text()
            && ui->button11->text() == ui->button12->text()
            && ui->button10->text() != "";
    bool line3 = ui->button20->text() == ui->button21->text()
            && ui->button21->text() == ui->button22->text()
            && ui->button20->text() != "";

    bool column1 = ui->button00->text() == ui->button10->text()
            && ui->button10->text() == ui->button20->text()
            && ui->button00->text() != "";
    bool column2 = ui->button01->text() == ui->button11->text()
            && ui->button11->text() == ui->button21->text()
            && ui->button01->text() != "";
    bool column3 = ui->button02->text() == ui->button12->text()
            && ui->button12->text() == ui->button22->text()
            && ui->button02->text() != "";

    bool diagonal1 = ui->button00->text() == ui->button11->text()
            && ui->button11->text() == ui->button22->text()
            && ui->button00->text() != "";
    bool diagonal2 = ui->button20->text() == ui->button11->text()
            && ui->button11->text() == ui->button02->text()
            && ui->button20->text() != "";

    return line1 || line2 || line3 || column1 || column2 || column3 || diagonal1 || diagonal2;
}

bool MainWindow::checkDraw() {
    QList<QPushButton*> buttons = this->findChildren<QPushButton*>();

    for(QPushButton* p : buttons) {
        if(p->isEnabled() && p->objectName() != "newGameButton") {
            return false;
        }
    }

    return !checkWinner();
}

void MainWindow::on_newGameButton_clicked()
{
    newGame();
}

void MainWindow :: makeButtonsDisabled() {
    QList<QPushButton*> buttons = this->findChildren<QPushButton*>();

    for(QPushButton* button : buttons) {
        if(button->objectName() != "newGameButton") {
            button->setEnabled(false);
        }
    }
}
