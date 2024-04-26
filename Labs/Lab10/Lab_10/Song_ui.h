
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QListWidget>
#include <QTableWidget>
#include<QGridLayout>


class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
private:
    void setupUI();

    QWidget* m_centralWidget;
    QHBoxLayout* m_mainLayout;
    QVBoxLayout* m_leftVLayout;
    QFormLayout* m_leftFormLayout;
    QHBoxLayout* m_buttonsHLayout;
    QVBoxLayout* m_centerVLayout;
    QFormLayout* m_centerFormLayout;
    QVBoxLayout* m_rightVLayout;
    QFormLayout* m_rightFormLayout;
    QHBoxLayout* m_buttonsHLayout1;
    QFormLayout* m_buttonsFormLayout1;
    QGridLayout* m_buttonsMatrix;
    QGridLayout* m_buttonsMatrix1;


    // form layout
    QLabel* m_titleLable;
    QLineEdit* m_titleText;

    QLabel* m_artistLable;
    QLineEdit* m_artistText;

    QLabel* m_durationLable;
    QLineEdit* m_durationText;

    QLabel* m_linkLable;
    QLineEdit* m_linkText;

    QLabel* m_listSongsLabel;
    QListWidget* m_listSongs;

    QLabel* m_playlistLabel;
    QListWidget* m_playlist;

    // buttons
    QPushButton* m_addButton;
    QPushButton* m_deleteButton;
    QPushButton* m_updateButton;
    QPushButton* m_filterButton;
    QPushButton* m_arrowButton;
    QPushButton* m_playButton;
    QPushButton* m_nextButton;
};

#endif // MAINWINDOW_H
