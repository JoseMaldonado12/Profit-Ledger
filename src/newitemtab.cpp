#include "add_dialog.h"
#include "newitemtab.h"

#include <QtWidgets>
newitemtab::newitemtab(QWidget *parent)
{
    Q_UNUSED(parent);

    descriptionLabel = new QLabel(tr ("There currently are no items in your list."
                                      "\n Click Add to add new items"));
    addButton = new QPushButton(tr("Add"));

    connect(addButton, &QAbstractButton::clicked, this, &newitemtab::addEntry);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(descriptionLabel);
    mainLayout->addWidget(addButton,0,Qt::AlignCenter);


    setLayout(mainLayout);

}

void newitemtab::addEntry()
{
    add_dialog dialog;
    //ADD THIS AS YOU ADD MROE COLUMNS
    if(dialog.exec()){
        int itemId = 0;
        QString brand = dialog.brandText->text();
        QString typeOfItem = dialog.typeOfItemText->text();
        QString colorOfItem = dialog.colorOfItemText->text();
        int cost = dialog.costText->text().toInt();
        int sold= dialog.soldText->text().toInt();
        float weight = dialog.weightText->text().toFloat();
        int profit = dialog.profitText->text().toInt();
        QString dateAdded = dialog.dateAddedText->text();
        emit sendDetails(itemId, brand, typeOfItem,
                         colorOfItem, cost,sold,weight,profit,dateAdded);
    }
}
