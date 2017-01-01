#ifndef FANGJIANYIZHUREN_H
#define FANGJIANYIZHUREN_H

#include <QDialog>

namespace Ui {
class fangjianyizhuren;
}

class fangjianyizhuren : public QDialog
{
    Q_OBJECT
    
public:
    explicit fangjianyizhuren(QWidget *parent = 0);
    ~fangjianyizhuren();
    
private:
    Ui::fangjianyizhuren *ui;
};

#endif // FANGJIANYIZHUREN_H
