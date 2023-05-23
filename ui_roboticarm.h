/********************************************************************************
** Form generated from reading UI file 'roboticarm.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTICARM_H
#define UI_ROBOTICARM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <drawarea.h>

QT_BEGIN_NAMESPACE

class Ui_RoboticArm
{
public:
    QWidget *centralWidget;
    QPushButton *btnClose;
    QLabel *lblError;
    QPushButton *btnSet;
    QTabWidget *tabWidget;
    QWidget *tabManual;
    QSlider *sldS1;
    QLabel *label_7;
    QSlider *sldS2;
    QSlider *sldS3;
    QSlider *sldS4;
    QSlider *sldS5;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QGraphicsView *gwArm;
    QWidget *tabPosition;
    QSlider *sldHand_2;
    QSlider *sldRotar;
    QSlider *sldHand;
    QComboBox *cmbSpeed;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_6;
    QSlider *sldZ;
    QGraphicsView *graphicsView;
    QSlider *sldX;
    QLabel *lblHand;
    QLabel *lblRotar;
    QLabel *lblHand_2;
    QComboBox *cmbGamePositions;
    QPushButton *btnSetAsPosition;
    QWidget *tabGame2;
    QGraphicsView *gwGame2;
    QGraphicsView *gwCube2;
    QPushButton *btnShuffle2;
    QPushButton *btnNext;
    QPushButton *btnHome;
    QLabel *lblMoving;
    QPushButton *btnAutoPlay;
    QGraphicsView *gwCameraGame;
    QWidget *tabDrawGame;
    QPushButton *btnShuffle2_2;
    QPushButton *btnHome_2;
    QGraphicsView *gwCube2_2;
    QGraphicsView *gwCameraGame_2;
    QPushButton *btnAutoPlay_2;
    QGraphicsView *drawArea;
    DrawArea *drawWidget;
    QLabel *lblMoving_2;
    QPushButton *btnDrawGame;
    QPushButton *btnCancel;
    QWidget *tabVideo;
    QPushButton *btnPlay;
    QPushButton *btnPause;
    QGraphicsView *gwCamera;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *RoboticArm)
    {
        if (RoboticArm->objectName().isEmpty())
            RoboticArm->setObjectName(QStringLiteral("RoboticArm"));
        RoboticArm->setWindowModality(Qt::NonModal);
        RoboticArm->resize(1366, 768);
        RoboticArm->setMinimumSize(QSize(1366, 768));
        RoboticArm->setMaximumSize(QSize(1366, 768));
        RoboticArm->setStyleSheet(QLatin1String("QWidget{\n"
"color: white;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"}\n"
"\n"
"QWidget#centralWidget, QMainWindow, QStatusBar,QToolBar, QMenuBar{\n"
"        background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2198c0, stop: 1 #0d5ca6);;\n"
"}\n"
"\n"
"QWidget#tabManual,QWidget#tabPosition,QWidget#tabGame,QWidget#tabVideo,QWidget#tabGame2{\n"
"        background-color:grey;\n"
"color: white;\n"
"	border: 0px;\n"
"border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton{\n"
"	background: #0080FF;\n"
"	border: 1px inset white;\n"
"	border-radius: 10px;\n"
"color: black;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background: #B3D9FF;\n"
"\n"
"}\n"
"\n"
"QSlider::handle:vertical{\n"
"	border: 1px solid white;\n"
"	background: #0080FF;\n"
"	width: 40px;\n"
"	height: 40px;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QSlider::groove:vertical {\n"
"        background:#303030;\n"
"        border: 1px inset #202020;\n"
"        padding:0 1px;\n"
"        border-radius:5px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal"
                        "{\n"
"	border: 1px solid white;\n"
"	background: #0080FF;\n"
"	width: 40px;\n"
"	height: 40px;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"        background:#303030;\n"
"        border: 1px inset #202020;\n"
"        padding:0 1px;\n"
"        border-radius:5px;\n"
"}\n"
"\n"
"\n"
"\n"
"QSlider::handle:hover{\n"
"	background: #B3D9FF;\n"
"	cursor: Pointer;\n"
"}\n"
"\n"
"QGraphicsView#graphicsView,QGraphicsView#gwGame2{\n"
"	background: gray;\n"
"        border-radius:5px;\n"
"}\n"
"\n"
"QGraphicsView#gwArm{\n"
"	background: gray;\n"
"        border-radius:5px;\n"
"}\n"
"\n"
"QGraphicsView#gwCamera{\n"
"	background: gray;\n"
"        border-radius:5px;\n"
"}\n"
"\n"
"QTabWidget::QLabel{\n"
"	color: white;\n"
"}\n"
"\n"
"QObject#cmbGamePositions QWidget{\n"
"	color: black;\n"
"}\n"
"\n"
"QTabWidget{\n"
"        background-color:grey;\n"
"	color: white;\n"
"	border: 1px solid white;\n"
"        border-radius: 20px;\n"
"}\n"
"\n"
"QTabWidget::pane { /* The tab widget frame */\n"
"bor"
                        "der-top: 0px solid grey;\n"
"        border-radius: 20px;\n"
"}\n"
"\n"
"QTabWidget::tab-bar{\n"
"        background-color:grey;\n"
"	width: 1000px;\n"
"left: 25px;\n"
"}\n"
"\n"
"QTabBar::tab{\n"
"        background-color:silver;\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 10px;\n"
"margin-right: 10px;\n"
"padding: 10px;\n"
"}\n"
"\n"
"QTabBar::tab:selected{\n"
"        background-color:grey;\n"
"}\n"
"\n"
"QTabBar::tab:hover{\n"
"        background-color:grey;\n"
"}\n"
"\n"
"QComboBox,QComboBox:editable,QComboBox::drop-down,QComboBox::drop-down:editable:on,QComboBox:on{\n"
"	color: black;\n"
"	\n"
"}\n"
"\n"
"QGraphicsView#gwCube,QGraphicsView#gwCube2{\n"
"        border-radius: 10px;\n"
"	background: white;\n"
"	\n"
"}"));
        centralWidget = new QWidget(RoboticArm);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnClose = new QPushButton(centralWidget);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setGeometry(QRect(1250, 670, 101, 41));
        lblError = new QLabel(centralWidget);
        lblError->setObjectName(QStringLiteral("lblError"));
        lblError->setGeometry(QRect(10, 660, 861, 41));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lblError->setFont(font);
        lblError->setStyleSheet(QLatin1String("QLabel{\n"
"	color: red;\n"
"	font-size: 35px;\n"
"}"));
        btnSet = new QPushButton(centralWidget);
        btnSet->setObjectName(QStringLiteral("btnSet"));
        btnSet->setEnabled(true);
        btnSet->setGeometry(QRect(180, 640, 531, 61));
#ifndef QT_NO_STATUSTIP
        btnSet->setStatusTip(QStringLiteral(""));
#endif // QT_NO_STATUSTIP
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(10, 10, 1341, 641));
        tabWidget->setMouseTracking(false);
        tabWidget->setAcceptDrops(false);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setProperty("tabletTracking", QVariant(false));
        tabManual = new QWidget();
        tabManual->setObjectName(QStringLiteral("tabManual"));
        sldS1 = new QSlider(tabManual);
        sldS1->setObjectName(QStringLiteral("sldS1"));
        sldS1->setGeometry(QRect(550, 210, 31, 351));
        sldS1->setStyleSheet(QStringLiteral(""));
        sldS1->setMinimum(0);
        sldS1->setMaximum(180);
        sldS1->setValue(90);
        sldS1->setOrientation(Qt::Vertical);
        sldS1->setTickPosition(QSlider::TicksBelow);
        sldS1->setTickInterval(10);
        label_7 = new QLabel(tabManual);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(540, 170, 67, 17));
        sldS2 = new QSlider(tabManual);
        sldS2->setObjectName(QStringLiteral("sldS2"));
        sldS2->setGeometry(QRect(470, 210, 31, 351));
        sldS2->setMinimum(-90);
        sldS2->setMaximum(90);
        sldS2->setOrientation(Qt::Vertical);
        sldS2->setTickPosition(QSlider::TicksBelow);
        sldS2->setTickInterval(10);
        sldS3 = new QSlider(tabManual);
        sldS3->setObjectName(QStringLiteral("sldS3"));
        sldS3->setGeometry(QRect(390, 210, 31, 351));
        sldS3->setMinimum(-40);
        sldS3->setMaximum(150);
        sldS3->setOrientation(Qt::Vertical);
        sldS3->setTickPosition(QSlider::TicksBelow);
        sldS3->setTickInterval(10);
        sldS4 = new QSlider(tabManual);
        sldS4->setObjectName(QStringLiteral("sldS4"));
        sldS4->setGeometry(QRect(310, 210, 31, 351));
        sldS4->setMinimum(-90);
        sldS4->setMaximum(90);
        sldS4->setOrientation(Qt::Vertical);
        sldS4->setTickPosition(QSlider::TicksBelow);
        sldS4->setTickInterval(10);
        sldS5 = new QSlider(tabManual);
        sldS5->setObjectName(QStringLiteral("sldS5"));
        sldS5->setGeometry(QRect(220, 260, 31, 301));
        sldS5->setMinimum(0);
        sldS5->setMaximum(50);
        sldS5->setValue(30);
        sldS5->setOrientation(Qt::Vertical);
        sldS5->setTickPosition(QSlider::TicksBelow);
        sldS5->setTickInterval(10);
        label_8 = new QLabel(tabManual);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(460, 170, 67, 17));
        label_9 = new QLabel(tabManual);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(380, 170, 67, 17));
        label_10 = new QLabel(tabManual);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(300, 170, 67, 17));
        label_11 = new QLabel(tabManual);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(210, 210, 67, 17));
        label_12 = new QLabel(tabManual);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(590, 380, 67, 17));
        label_13 = new QLabel(tabManual);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(590, 547, 67, 17));
        label_14 = new QLabel(tabManual);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(590, 210, 67, 17));
        label_15 = new QLabel(tabManual);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(510, 547, 67, 17));
        label_16 = new QLabel(tabManual);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(510, 211, 67, 17));
        label_17 = new QLabel(tabManual);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(510, 380, 67, 17));
        label_18 = new QLabel(tabManual);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(430, 547, 67, 17));
        label_19 = new QLabel(tabManual);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(430, 470, 67, 17));
        label_20 = new QLabel(tabManual);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(429, 210, 67, 17));
        label_21 = new QLabel(tabManual);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(350, 380, 67, 17));
        label_22 = new QLabel(tabManual);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(350, 211, 67, 17));
        label_23 = new QLabel(tabManual);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(350, 547, 67, 17));
        label_24 = new QLabel(tabManual);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(260, 547, 67, 17));
        label_25 = new QLabel(tabManual);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(260, 260, 67, 17));
        label_26 = new QLabel(tabManual);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(540, 190, 67, 17));
        label_27 = new QLabel(tabManual);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(460, 190, 81, 17));
        label_28 = new QLabel(tabManual);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(380, 190, 67, 17));
        label_29 = new QLabel(tabManual);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(300, 190, 67, 17));
        label_30 = new QLabel(tabManual);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(210, 230, 67, 17));
        gwArm = new QGraphicsView(tabManual);
        gwArm->setObjectName(QStringLiteral("gwArm"));
        gwArm->setGeometry(QRect(5, 0, 1001, 581));
        tabWidget->addTab(tabManual, QString());
        gwArm->raise();
        sldS1->raise();
        label_7->raise();
        sldS2->raise();
        sldS3->raise();
        sldS4->raise();
        sldS5->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        label_12->raise();
        label_13->raise();
        label_14->raise();
        label_15->raise();
        label_16->raise();
        label_17->raise();
        label_18->raise();
        label_19->raise();
        label_20->raise();
        label_21->raise();
        label_22->raise();
        label_23->raise();
        label_24->raise();
        label_25->raise();
        label_26->raise();
        label_27->raise();
        label_28->raise();
        label_29->raise();
        label_30->raise();
        tabPosition = new QWidget();
        tabPosition->setObjectName(QStringLiteral("tabPosition"));
        sldHand_2 = new QSlider(tabPosition);
        sldHand_2->setObjectName(QStringLiteral("sldHand_2"));
        sldHand_2->setGeometry(QRect(190, 45, 261, 29));
        sldHand_2->setMinimum(-90);
        sldHand_2->setMaximum(90);
        sldHand_2->setPageStep(10);
        sldHand_2->setValue(0);
        sldHand_2->setOrientation(Qt::Horizontal);
        sldHand_2->setTickPosition(QSlider::TicksBelow);
        sldRotar = new QSlider(tabPosition);
        sldRotar->setObjectName(QStringLiteral("sldRotar"));
        sldRotar->setGeometry(QRect(620, 45, 371, 29));
        sldRotar->setMinimum(0);
        sldRotar->setMaximum(180);
        sldRotar->setValue(90);
        sldRotar->setOrientation(Qt::Horizontal);
        sldRotar->setInvertedAppearance(true);
        sldRotar->setInvertedControls(false);
        sldRotar->setTickPosition(QSlider::TicksBelow);
        sldHand = new QSlider(tabPosition);
        sldHand->setObjectName(QStringLiteral("sldHand"));
        sldHand->setGeometry(QRect(20, 160, 201, 29));
        sldHand->setMinimum(-10);
        sldHand->setMaximum(50);
        sldHand->setPageStep(10);
        sldHand->setValue(10);
        sldHand->setOrientation(Qt::Horizontal);
        sldHand->setTickPosition(QSlider::TicksBelow);
        cmbSpeed = new QComboBox(tabPosition);
        cmbSpeed->setObjectName(QStringLiteral("cmbSpeed"));
        cmbSpeed->setGeometry(QRect(10, 230, 85, 27));
        label_2 = new QLabel(tabPosition);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(11, 50, 91, 17));
        label_3 = new QLabel(tabPosition);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 120, 121, 17));
        label = new QLabel(tabPosition);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(11, 210, 91, 17));
        label_6 = new QLabel(tabPosition);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 80, 111, 17));
        sldZ = new QSlider(tabPosition);
        sldZ->setObjectName(QStringLiteral("sldZ"));
        sldZ->setGeometry(QRect(0, 1, 29, 581));
        sldZ->setMaximum(300);
        sldZ->setPageStep(1);
        sldZ->setValue(5);
        sldZ->setOrientation(Qt::Vertical);
        sldZ->setTickPosition(QSlider::TicksAbove);
        graphicsView = new QGraphicsView(tabPosition);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 1, 991, 581));
        sldX = new QSlider(tabPosition);
        sldX->setObjectName(QStringLiteral("sldX"));
        sldX->setGeometry(QRect(40, 544, 951, 29));
        sldX->setMaximum(300);
        sldX->setPageStep(1);
        sldX->setValue(5);
        sldX->setOrientation(Qt::Horizontal);
        sldX->setInvertedAppearance(true);
        sldX->setTickPosition(QSlider::TicksBelow);
        lblHand = new QLabel(tabPosition);
        lblHand->setObjectName(QStringLiteral("lblHand"));
        lblHand->setGeometry(QRect(320, 20, 67, 17));
        lblRotar = new QLabel(tabPosition);
        lblRotar->setObjectName(QStringLiteral("lblRotar"));
        lblRotar->setGeometry(QRect(800, 20, 67, 17));
        lblHand_2 = new QLabel(tabPosition);
        lblHand_2->setObjectName(QStringLiteral("lblHand_2"));
        lblHand_2->setGeometry(QRect(90, 140, 67, 17));
        cmbGamePositions = new QComboBox(tabPosition);
        cmbGamePositions->setObjectName(QStringLiteral("cmbGamePositions"));
        cmbGamePositions->setGeometry(QRect(20, 550, 121, 27));
        btnSetAsPosition = new QPushButton(tabPosition);
        btnSetAsPosition->setObjectName(QStringLiteral("btnSetAsPosition"));
        btnSetAsPosition->setGeometry(QRect(20, 520, 121, 27));
        tabWidget->addTab(tabPosition, QString());
        sldZ->raise();
        sldX->raise();
        label_2->raise();
        label_6->raise();
        label_3->raise();
        graphicsView->raise();
        sldHand_2->raise();
        sldRotar->raise();
        sldHand->raise();
        cmbSpeed->raise();
        label->raise();
        lblHand->raise();
        lblRotar->raise();
        lblHand_2->raise();
        cmbGamePositions->raise();
        btnSetAsPosition->raise();
        tabGame2 = new QWidget();
        tabGame2->setObjectName(QStringLiteral("tabGame2"));
        gwGame2 = new QGraphicsView(tabGame2);
        gwGame2->setObjectName(QStringLiteral("gwGame2"));
        gwGame2->setGeometry(QRect(180, 20, 1141, 561));
        gwCube2 = new QGraphicsView(tabGame2);
        gwCube2->setObjectName(QStringLiteral("gwCube2"));
        gwCube2->setGeometry(QRect(10, 10, 141, 131));
        btnShuffle2 = new QPushButton(tabGame2);
        btnShuffle2->setObjectName(QStringLiteral("btnShuffle2"));
        btnShuffle2->setGeometry(QRect(10, 150, 141, 91));
        btnNext = new QPushButton(tabGame2);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        btnNext->setGeometry(QRect(200, 480, 141, 91));
        btnHome = new QPushButton(tabGame2);
        btnHome->setObjectName(QStringLiteral("btnHome"));
        btnHome->setGeometry(QRect(10, 250, 141, 91));
        lblMoving = new QLabel(tabGame2);
        lblMoving->setObjectName(QStringLiteral("lblMoving"));
        lblMoving->setGeometry(QRect(700, 250, 301, 91));
        lblMoving->setStyleSheet(QLatin1String("QLabel{\n"
"	color: blue;\n"
"	font-size: 35px;\n"
"}"));
        btnAutoPlay = new QPushButton(tabGame2);
        btnAutoPlay->setObjectName(QStringLiteral("btnAutoPlay"));
        btnAutoPlay->setGeometry(QRect(10, 350, 141, 91));
        gwCameraGame = new QGraphicsView(tabGame2);
        gwCameraGame->setObjectName(QStringLiteral("gwCameraGame"));
        gwCameraGame->setGeometry(QRect(10, 460, 181, 135));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gwCameraGame->sizePolicy().hasHeightForWidth());
        gwCameraGame->setSizePolicy(sizePolicy);
        gwCameraGame->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gwCameraGame->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tabWidget->addTab(tabGame2, QString());
        tabDrawGame = new QWidget();
        tabDrawGame->setObjectName(QStringLiteral("tabDrawGame"));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(128, 128, 128, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(192, 192, 192, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(160, 160, 160, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(64, 64, 64, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(85, 85, 85, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        tabDrawGame->setPalette(palette);
        tabDrawGame->setMouseTracking(false);
        tabDrawGame->setAcceptDrops(false);
        tabDrawGame->setAutoFillBackground(true);
        tabDrawGame->setProperty("tabletTracking", QVariant(false));
        btnShuffle2_2 = new QPushButton(tabDrawGame);
        btnShuffle2_2->setObjectName(QStringLiteral("btnShuffle2_2"));
        btnShuffle2_2->setGeometry(QRect(10, 150, 141, 91));
        btnHome_2 = new QPushButton(tabDrawGame);
        btnHome_2->setObjectName(QStringLiteral("btnHome_2"));
        btnHome_2->setGeometry(QRect(10, 250, 141, 91));
        gwCube2_2 = new QGraphicsView(tabDrawGame);
        gwCube2_2->setObjectName(QStringLiteral("gwCube2_2"));
        gwCube2_2->setGeometry(QRect(10, 10, 141, 131));
        gwCameraGame_2 = new QGraphicsView(tabDrawGame);
        gwCameraGame_2->setObjectName(QStringLiteral("gwCameraGame_2"));
        gwCameraGame_2->setGeometry(QRect(10, 460, 181, 135));
        sizePolicy.setHeightForWidth(gwCameraGame_2->sizePolicy().hasHeightForWidth());
        gwCameraGame_2->setSizePolicy(sizePolicy);
        gwCameraGame_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gwCameraGame_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        btnAutoPlay_2 = new QPushButton(tabDrawGame);
        btnAutoPlay_2->setObjectName(QStringLiteral("btnAutoPlay_2"));
        btnAutoPlay_2->setGeometry(QRect(10, 350, 141, 91));
        drawArea = new QGraphicsView(tabDrawGame);
        drawArea->setObjectName(QStringLiteral("drawArea"));
        drawArea->setEnabled(true);
        drawArea->setGeometry(QRect(200, 10, 1031, 581));
        drawArea->setMinimumSize(QSize(1031, 581));
        drawArea->setMaximumSize(QSize(1031, 581));
        drawArea->setMouseTracking(false);
        drawArea->setAcceptDrops(false);
        drawArea->setProperty("tabletTracking", QVariant(false));
        drawWidget = new DrawArea(tabDrawGame);
        drawWidget->setObjectName(QStringLiteral("drawWidget"));
        drawWidget->setGeometry(QRect(210, 20, 1011, 561));
        drawWidget->setMinimumSize(QSize(1011, 561));
        drawWidget->setMaximumSize(QSize(1011, 561));
        lblMoving_2 = new QLabel(tabDrawGame);
        lblMoving_2->setObjectName(QStringLiteral("lblMoving_2"));
        lblMoving_2->setGeometry(QRect(580, -10, 301, 91));
        lblMoving_2->setStyleSheet(QLatin1String("QLabel{\n"
"	color: blue;\n"
"	font-size: 35px;\n"
"}"));
        btnDrawGame = new QPushButton(tabDrawGame);
        btnDrawGame->setObjectName(QStringLiteral("btnDrawGame"));
        btnDrawGame->setGeometry(QRect(1240, 500, 91, 91));
        btnCancel = new QPushButton(tabDrawGame);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(1240, 400, 91, 91));
        tabWidget->addTab(tabDrawGame, QString());
        drawArea->raise();
        btnShuffle2_2->raise();
        btnHome_2->raise();
        gwCube2_2->raise();
        gwCameraGame_2->raise();
        btnAutoPlay_2->raise();
        lblMoving_2->raise();
        btnDrawGame->raise();
        drawWidget->raise();
        btnCancel->raise();
        tabVideo = new QWidget();
        tabVideo->setObjectName(QStringLiteral("tabVideo"));
        btnPlay = new QPushButton(tabVideo);
        btnPlay->setObjectName(QStringLiteral("btnPlay"));
        btnPlay->setGeometry(QRect(10, 10, 161, 101));
        btnPause = new QPushButton(tabVideo);
        btnPause->setObjectName(QStringLiteral("btnPause"));
        btnPause->setGeometry(QRect(10, 120, 161, 101));
        gwCamera = new QGraphicsView(tabVideo);
        gwCamera->setObjectName(QStringLiteral("gwCamera"));
        gwCamera->setGeometry(QRect(290, 80, 711, 501));
        tabWidget->addTab(tabVideo, QString());
        RoboticArm->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RoboticArm);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1366, 25));
        RoboticArm->setMenuBar(menuBar);
        statusBar = new QStatusBar(RoboticArm);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RoboticArm->setStatusBar(statusBar);
        mainToolBar = new QToolBar(RoboticArm);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RoboticArm->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(RoboticArm);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(RoboticArm);
    } // setupUi

    void retranslateUi(QMainWindow *RoboticArm)
    {
        RoboticArm->setWindowTitle(QApplication::translate("RoboticArm", "RoboticArm", 0));
        btnClose->setText(QApplication::translate("RoboticArm", "Exit", 0));
        lblError->setText(QApplication::translate("RoboticArm", "TextLabel", 0));
        btnSet->setText(QApplication::translate("RoboticArm", "SET", 0));
        label_7->setText(QApplication::translate("RoboticArm", "Servo 1", 0));
        label_8->setText(QApplication::translate("RoboticArm", "Servo 2", 0));
        label_9->setText(QApplication::translate("RoboticArm", "Servo 3", 0));
        label_10->setText(QApplication::translate("RoboticArm", "Servo 4", 0));
        label_11->setText(QApplication::translate("RoboticArm", "Servo 5", 0));
        label_12->setText(QApplication::translate("RoboticArm", "90\302\260", 0));
        label_13->setText(QApplication::translate("RoboticArm", "0\302\260", 0));
        label_14->setText(QApplication::translate("RoboticArm", "180\302\260", 0));
        label_15->setText(QApplication::translate("RoboticArm", "-90\302\260", 0));
        label_16->setText(QApplication::translate("RoboticArm", "90\302\260", 0));
        label_17->setText(QApplication::translate("RoboticArm", "0\302\260", 0));
        label_18->setText(QApplication::translate("RoboticArm", "-40\302\260", 0));
        label_19->setText(QApplication::translate("RoboticArm", "0\302\260", 0));
        label_20->setText(QApplication::translate("RoboticArm", "150\302\260", 0));
        label_21->setText(QApplication::translate("RoboticArm", "0\302\260", 0));
        label_22->setText(QApplication::translate("RoboticArm", "90\302\260", 0));
        label_23->setText(QApplication::translate("RoboticArm", "-90\302\260", 0));
        label_24->setText(QApplication::translate("RoboticArm", "0 mm", 0));
        label_25->setText(QApplication::translate("RoboticArm", "50 mm", 0));
        label_26->setText(QApplication::translate("RoboticArm", "(Rotate)", 0));
        label_27->setText(QApplication::translate("RoboticArm", "(Shoulder)", 0));
        label_28->setText(QApplication::translate("RoboticArm", "(Elbow)", 0));
        label_29->setText(QApplication::translate("RoboticArm", "(Wrist)", 0));
        label_30->setText(QApplication::translate("RoboticArm", "(Hand)", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabManual), QApplication::translate("RoboticArm", "Manual", 0));
        label_2->setText(QApplication::translate("RoboticArm", "Hand (mm):", 0));
        label_3->setText(QApplication::translate("RoboticArm", "Rotate (degree):", 0));
        label->setText(QApplication::translate("RoboticArm", "Speed (ms):", 0));
        label_6->setText(QApplication::translate("RoboticArm", "Hand (degree):", 0));
        lblHand->setText(QApplication::translate("RoboticArm", "0", 0));
        lblRotar->setText(QApplication::translate("RoboticArm", "90", 0));
        lblHand_2->setText(QApplication::translate("RoboticArm", "10", 0));
        btnSetAsPosition->setText(QApplication::translate("RoboticArm", "Set As Position", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabPosition), QApplication::translate("RoboticArm", "Position", 0));
        btnShuffle2->setText(QApplication::translate("RoboticArm", "Shuffle", 0));
        btnNext->setText(QApplication::translate("RoboticArm", "NEXT", 0));
        btnHome->setText(QApplication::translate("RoboticArm", "TO READY", 0));
        lblMoving->setText(QApplication::translate("RoboticArm", "Moving...", 0));
        btnAutoPlay->setText(QApplication::translate("RoboticArm", "Auto play", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabGame2), QApplication::translate("RoboticArm", "Game", 0));
        btnShuffle2_2->setText(QApplication::translate("RoboticArm", "Shuffle", 0));
        btnHome_2->setText(QApplication::translate("RoboticArm", "TO READY", 0));
        btnAutoPlay_2->setText(QApplication::translate("RoboticArm", "Auto play", 0));
        lblMoving_2->setText(QApplication::translate("RoboticArm", "Moving...", 0));
        btnDrawGame->setText(QApplication::translate("RoboticArm", "Draw Track", 0));
        btnCancel->setText(QApplication::translate("RoboticArm", "Cancel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabDrawGame), QApplication::translate("RoboticArm", "Draw Game", 0));
        btnPlay->setText(QApplication::translate("RoboticArm", "Play", 0));
        btnPause->setText(QApplication::translate("RoboticArm", "Stop", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabVideo), QApplication::translate("RoboticArm", "Video", 0));
    } // retranslateUi

};

namespace Ui {
    class RoboticArm: public Ui_RoboticArm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTICARM_H
