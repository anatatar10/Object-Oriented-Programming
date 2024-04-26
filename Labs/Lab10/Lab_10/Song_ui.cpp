
#include "Song_ui.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    this->setupUI();
}

MainWindow::~MainWindow()
{
    delete m_mainLayout;
    delete m_leftVLayout;
    delete m_buttonsMatrix;
    delete m_centerVLayout;
    delete m_rightVLayout;
    delete m_buttonsHLayout1;
    delete m_centralWidget;
}

void MainWindow::setupUI()
{
    m_centralWidget = new QWidget();
    m_mainLayout = new QHBoxLayout();
    m_leftVLayout = new QVBoxLayout();
    m_buttonsHLayout = new QHBoxLayout();
    m_buttonsMatrix = new QGridLayout();


    m_listSongsLabel = new QLabel("All songs:");
    m_listSongs = new QListWidget();
    m_leftFormLayout = new QFormLayout();

    m_titleLable = new QLabel("Title:");
    m_titleText = new QLineEdit();

    m_artistLable = new QLabel("Artist:");
    m_artistText = new QLineEdit();

    m_durationLable = new QLabel("Duration:");
    m_durationText = new QLineEdit();

    m_linkLable = new QLabel("Link:");
    m_linkText = new QLineEdit();

    m_playlistLabel = new QLabel("Playlist:");
    m_playlist = new QListWidget();

    m_leftFormLayout->addRow(m_titleLable, m_titleText);
    m_leftFormLayout->addRow(m_artistLable, m_artistText);
    m_leftFormLayout->addRow(m_durationLable, m_durationText);
    m_leftFormLayout->addRow(m_linkLable, m_linkText);
    m_leftVLayout->addWidget(m_listSongsLabel);
    m_leftVLayout->addWidget(m_listSongs);

    m_addButton = new QPushButton("Add");
    m_deleteButton = new QPushButton("Delete");
    m_updateButton = new QPushButton("Update");
    m_filterButton = new QPushButton("Filter");
    m_arrowButton = new QPushButton(">");
    m_playButton = new QPushButton("Play");
    m_nextButton = new QPushButton("Next");

    m_leftVLayout->addLayout(m_leftFormLayout);
    m_leftVLayout->addLayout(m_buttonsMatrix);

    m_buttonsMatrix->addWidget(m_addButton, 0, 0);
    m_buttonsMatrix->addWidget(m_deleteButton, 0, 1);
    m_buttonsMatrix->addWidget(m_updateButton, 0, 2);
    m_buttonsMatrix->addWidget(m_filterButton, 1, 1);

    m_centerVLayout = new QVBoxLayout();
    m_centerFormLayout = new QFormLayout();

    m_centerVLayout->addWidget(m_arrowButton);

    m_rightVLayout = new QVBoxLayout();
    m_rightFormLayout = new QFormLayout();

    m_rightFormLayout->addWidget(m_playlistLabel);
    m_rightFormLayout->addWidget(m_playlist);
    m_rightVLayout->addLayout(m_rightFormLayout);

    m_buttonsHLayout1 = new QHBoxLayout();

    m_buttonsHLayout1->addWidget(m_playButton);
    m_buttonsHLayout1->addWidget(m_nextButton);

    m_rightVLayout->addLayout(m_buttonsHLayout1);

    m_mainLayout->addLayout(m_leftVLayout);
    m_mainLayout->addLayout(m_centerVLayout);
    m_mainLayout->addLayout(m_rightVLayout);
    m_centralWidget->setLayout(m_mainLayout);
    this->setCentralWidget(m_centralWidget);
}


