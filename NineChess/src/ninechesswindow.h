﻿#ifndef NINECHESSWINDOW_H
#define NINECHESSWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QTextStream>
#include <QStringListModel>
#include <QFile>
#include <QTimer>
#include "ui_ninechesswindow.h"

class GameScene;
class GameController;

class NineChessWindow : public QMainWindow
{
	Q_OBJECT

public:
    NineChessWindow(QWidget *parent = nullptr);
	~NineChessWindow();

protected:
    bool eventFilter(QObject * watched, QEvent * event);
    void closeEvent(QCloseEvent *event);

private slots:
    // 初始化
    void initialize();
    // 动态增加的菜单栏动作的槽函数
    void actionRules_triggered();
    // 更新规则标签
    void ruleInfo();
    // 自动运行定时处理函数
    void onAutoRunTimeOut(QPrivateSignal signal);

    // 下面是各动作的槽函数
    // 注释掉的是已在UI管理器或主窗口初始化函数中连接好的
    void on_actionNew_N_triggered();
    void on_actionOpen_O_triggered();
    void on_actionSave_S_triggered();
    void on_actionSaveAs_A_triggered();
    //void on_actionExit_X_triggered();
    void on_actionEdit_E_toggled(bool arg1);
    //void on_actionFlip_F_triggered();
    //void on_actionMirror_M_triggered();
    //void on_actionTurnRight_R_triggered();
    //void on_actionTurnLeftt_L_triggered();
    void on_actionInvert_I_toggled(bool arg1);
    // 前后招的公共槽
    void on_actionRowChange();
    void on_actionAutoRun_A_toggled(bool arg1);
    //void on_actionGiveUp_G_triggered();
    void on_actionLimited_T_triggered();
    void on_actionLocal_L_triggered();
	void on_actionInternet_I_triggered();
    void on_actionEngine_E_triggered();
    //void on_actionEngine1_R_toggled(bool arg1);
    //void on_actionEngine2_T_toggled(bool arg1);
    //void on_actionSetting_O_triggered();
    //void on_actionToolBar_T_toggled(bool arg1);
    //void on_actionDockBar_D_toggled(bool arg1);
    //void on_actionSound_S_toggled(bool arg1);
    //void on_actionAnimation_A_toggled(bool arg1);
    void on_actionViewHelp_V_triggered();
    void on_actionWeb_W_triggered();
    void on_actionAbout_A_triggered();

private:
    // 界面文件
    Ui::NineChessWindowClass ui;
    // 视图场景
    GameScene *scene;
    // 控制器
    GameController *game;
    // 动态增加的菜单栏动作列表
    QList <QAction *> ruleActionList;
    // 游戏的规则号，涉及菜单项和对话框，所以要有
    int ruleNo;
    // 文件
    QFile file;
    // 定时器
    QTimer autoRunTimer;
};

#endif // NINECHESSWINDOW_H
