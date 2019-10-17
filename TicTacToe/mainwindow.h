#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int turn = 0;
    QString player1;
    QString player2;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void makeButtonsDisabled();
    void makeButtonVisible(QPushButton* button);
    void makeButtonInvisible(QPushButton* button);
    void newGame();
    void whenClicked(QPushButton* button);
    void customConfiguration();
    bool checkWinner();
    bool checkDraw();

private slots:
    void on_button00_clicked();

    void on_button01_clicked();

    void on_button02_clicked();

    void on_button10_clicked();

    void on_button11_clicked();

    void on_button12_clicked();

    void on_button20_clicked();

    void on_button21_clicked();

    void on_button22_clicked();

    void on_newGameButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
