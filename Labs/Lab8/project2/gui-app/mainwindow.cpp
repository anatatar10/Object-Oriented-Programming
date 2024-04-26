#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setupUI();
}

MainWindow::~MainWindow()
{
    delete m_leftVLayout;
    delete m_centralWidget;
}

void MainWindow::setupUI()
{
    m_centralWidget = new QWidget();
    m_leftVLayout = new QVBoxLayout();

    m_listSongsLabel = new QLabel("All songs:");
    m_listSongs = new QTextEdit();
    m_leftFormLayout = new QFormLayout();

    m_titleLable = new QLabel("Title:");
    m_titleText = new QLineEdit();

    m_artistLable = new QLabel("Artist:");
    m_artistText = new QLineEdit();

    m_durationLable = new QLabel("Duration:");
    m_durationText = new QLineEdit();

    m_linkLable = new QLabel("Link:");
    m_linkText = new QLineEdit();

    m_leftFormLayout->addRow(m_titleLable, m_titleText);
    m_leftFormLayout->addRow(m_artistLable, m_artistText);
    m_leftFormLayout->addRow(m_durationLable, m_durationText);
    m_leftFormLayout->addRow(m_linkLable, m_linkText);

    m_leftVLayout->addWidget(m_listSongsLabel);
    m_leftVLayout->addWidget(m_listSongs);
    m_leftVLayout->addLayout(m_leftFormLayout);
