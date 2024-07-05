/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "drawingarea.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *rectangleButton;
    QPushButton *ellipseButton;
    QPushButton *triangleButton;
    QFrame *line;
    QPushButton *connectButton;
    QPushButton *moveButton;
    QPushButton *deleteButton;
    QFrame *line_2;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QSpacerItem *horizontalSpacer;
    DrawingArea *drawingArea;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(812, 681);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setTabletTracking(false);
        centralwidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        centralwidget->setAutoFillBackground(false);
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        rectangleButton = new QPushButton(centralwidget);
        rectangleButton->setObjectName("rectangleButton");
        rectangleButton->setCursor(QCursor(Qt::PointingHandCursor));
        rectangleButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 255);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/rectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        rectangleButton->setIcon(icon);
        rectangleButton->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(rectangleButton);

        ellipseButton = new QPushButton(centralwidget);
        ellipseButton->setObjectName("ellipseButton");
        ellipseButton->setCursor(QCursor(Qt::PointingHandCursor));
        ellipseButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 255);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/ellipse.png"), QSize(), QIcon::Normal, QIcon::Off);
        ellipseButton->setIcon(icon1);
        ellipseButton->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(ellipseButton);

        triangleButton = new QPushButton(centralwidget);
        triangleButton->setObjectName("triangleButton");
        triangleButton->setCursor(QCursor(Qt::PointingHandCursor));
        triangleButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 255);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icons/triangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        triangleButton->setIcon(icon2);
        triangleButton->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(triangleButton);

        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setStyleSheet(QString::fromUtf8(""));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(1);
        line->setFrameShape(QFrame::VLine);

        horizontalLayout_5->addWidget(line);

        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName("connectButton");
        connectButton->setCursor(QCursor(Qt::PointingHandCursor));
        connectButton->setStyleSheet(QString::fromUtf8("background-color: rgb(140, 245, 255);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/icons/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        connectButton->setIcon(icon3);
        connectButton->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(connectButton);

        moveButton = new QPushButton(centralwidget);
        moveButton->setObjectName("moveButton");
        moveButton->setCursor(QCursor(Qt::PointingHandCursor));
        moveButton->setStyleSheet(QString::fromUtf8("background-color: rgb(140, 245, 255);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/icons/move.png"), QSize(), QIcon::Normal, QIcon::Off);
        moveButton->setIcon(icon4);
        moveButton->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(moveButton);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setCursor(QCursor(Qt::PointingHandCursor));
        deleteButton->setStyleSheet(QString::fromUtf8("background-color: rgb(140, 245, 255);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon5);
        deleteButton->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(deleteButton);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setStyleSheet(QString::fromUtf8(""));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(1);
        line_2->setFrameShape(QFrame::VLine);

        horizontalLayout_5->addWidget(line_2);

        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");
        saveButton->setCursor(QCursor(Qt::PointingHandCursor));
        saveButton->setStyleSheet(QString::fromUtf8("background-color: rgb(142, 255, 159);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon6);
        saveButton->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(saveButton);

        loadButton = new QPushButton(centralwidget);
        loadButton->setObjectName("loadButton");
        loadButton->setCursor(QCursor(Qt::PointingHandCursor));
        loadButton->setStyleSheet(QString::fromUtf8("background-color: rgb(142, 255, 159);"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/icons/load.png"), QSize(), QIcon::Normal, QIcon::Off);
        loadButton->setIcon(icon7);
        loadButton->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(loadButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_5);

        drawingArea = new DrawingArea(centralwidget);
        drawingArea->setObjectName("drawingArea");
        sizePolicy.setHeightForWidth(drawingArea->sizePolicy().hasHeightForWidth());
        drawingArea->setSizePolicy(sizePolicy);
        drawingArea->setMinimumSize(QSize(700, 500));
        drawingArea->setMouseTracking(true);
        drawingArea->setFocusPolicy(Qt::StrongFocus);
        drawingArea->setFrameShape(QFrame::StyledPanel);
        drawingArea->setFrameShadow(QFrame::Raised);

        verticalLayout_3->addWidget(drawingArea);

        verticalLayout_3->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 812, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(accessibility)
        rectangleButton->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        rectangleButton->setText(QString());
        ellipseButton->setText(QString());
        triangleButton->setText(QString());
        connectButton->setText(QString());
        moveButton->setText(QString());
        deleteButton->setText(QString());
        saveButton->setText(QString());
        loadButton->setText(QString());
#if QT_CONFIG(statustip)
        drawingArea->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
