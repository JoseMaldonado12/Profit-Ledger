/*This is the pop-up dialog box that appears when you
 try to add shit to the list.*/
#include "add_dialog.h"
#include "global_variables.h"

#include <QtWidgets>
add_dialog::add_dialog(QWidget *parent)
    :QDialog (parent)
{
     itemIdLabel = new QLabel("Item #");
     brandLabel =  new QLabel("Item Brand");
     typeOfItemLabel = new QLabel("Item Type");
     colorOfItemLabel = new QLabel("Item Color");
     costLabel = new QLabel("Item Cost ($)");
     soldLabel = new QLabel("Selling Price ($)");
     weightLabel = new QLabel("Weight (oz)");
     profitLabel = new QLabel("Profit ($)");
     dateAddedLabel = new QLabel("Date Added");


     okButton = new QPushButton("OK");
     cancelButton = new QPushButton("CANCEL");


    //setReadOnly=we dont want users changing this shit
     itemIdText = new QLineEdit;
     itemIdText->setReadOnly(true);

     brandText = new QLineEdit;
     typeOfItemText = new QLineEdit;
     colorOfItemText = new QLineEdit;
     costText = new QLineEdit;
     soldText = new QLineEdit;
     weightText = new QLineEdit;

     profitText = new QLineEdit;
     profitText->setReadOnly(true);

     dateAddedText = new QLineEdit;
     dateAddedText->setReadOnly(true);


     QGridLayout *gLayout = new QGridLayout;
     /* imagine these numbers as part of a grid,
        this will make the numbers make sense*/
     gLayout->setColumnStretch (1,2);

     //Itemid+1 otherwise incorrect number is shown
     itemIdText->setText(QString::number((globalItemId+1)));
     gLayout->addWidget(itemIdLabel, 0, 0);
     gLayout->addWidget(itemIdText, 0, 1);

     gLayout->addWidget(brandLabel, 1, 0);
     gLayout->addWidget(brandText, 1, 1);

     gLayout->addWidget(typeOfItemLabel, 2, 0);
     gLayout->addWidget(typeOfItemText, 2, 1);

     gLayout->addWidget(colorOfItemLabel, 3, 0);
     gLayout->addWidget(colorOfItemText, 3, 1);

     gLayout->addWidget(costLabel, 4, 0);
     gLayout->addWidget(costText, 4, 1);

     gLayout->addWidget(soldLabel, 5, 0);
     gLayout->addWidget(soldText, 5, 1);

     gLayout->addWidget(weightLabel, 6, 0);
     gLayout->addWidget(weightText, 6, 1);


     gLayout->addWidget(profitLabel, 7, 0);
     gLayout->addWidget(profitText, 7, 1);


     QDate date;
     dateAddedText->setText(date.currentDate().toString());
     gLayout->addWidget(dateAddedLabel, 8, 0);
     gLayout->addWidget(dateAddedText, 8, 1);


     QHBoxLayout *buttonLayout = new QHBoxLayout;
     buttonLayout->addWidget(okButton);
     buttonLayout->addWidget(cancelButton);

     gLayout->addLayout(buttonLayout, 9, 1, Qt::AlignRight);

     QVBoxLayout *mainLayout = new QVBoxLayout;
     mainLayout->addLayout(gLayout);
     setLayout(mainLayout);

     connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);
     connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

     setWindowTitle(tr("Add an Item"));
}
