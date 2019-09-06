#ifndef ADD_DIALOG_H
#define ADD_DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QTextEdit;
class QLineEdit;
QT_END_NAMESPACE


class add_dialog : public QDialog
{
    Q_OBJECT

public:
    add_dialog(QWidget *parent = 0);
    //perhaps edit when you add more columns?
    //qlineedit=one line. qtext edit= giant ass box to add text
    //line= PLAIN TEXT, text=can have rich text
    QLineEdit *itemIdText;
    QLineEdit *brandText;
    QLineEdit *typeOfItemText;
    QLineEdit *colorOfItemText;
    QLineEdit *costText;
    QLineEdit *soldText;
    QLineEdit *weightText;
    QLineEdit *profitText;
    QLineEdit *dateAddedText;

private:

    QLabel *itemIdLabel;
    QLabel *brandLabel;
    QLabel *typeOfItemLabel;
    QLabel *colorOfItemLabel;
    QLabel *costLabel;
    QLabel *soldLabel;
    QLabel *weightLabel;
    QLabel *profitLabel;
    QLabel *dateAddedLabel;

    QPushButton *okButton;
    QPushButton *cancelButton;

};

#endif // ADD_DIALOG_H
