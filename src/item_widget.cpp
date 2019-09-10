/* this constructor accepts a parent widget
 *  and instantiates NewAddressTab, TableModel and QSortFilterProxyModel.
 *  The NewAddressTab object, which is used to indicate that the address book is empty,
 *  is added. THIS IS ALSO WHERE YOU DECLARE THE "KEY" */
#include "add_dialog.h"
#include "item_widget.h"
#include "global_variables.h"

#include <QtWidgets>
//did this because im too lazy to create an entire fucking class just for this one dialog box that im using like once
#include <QDialog>

item_widget::item_widget(QWidget *parent)
    : QTabWidget (parent)
{

    table= new tablemodel(this);
    newItemTab = new newitemtab(this);

    connect(newItemTab, &newitemtab::sendDetails, this, &item_widget::addEntry);
    addTab(newItemTab, "Items");

    setupTabs();

}

void item_widget::showAddEntryDialog()
{
    add_dialog dialog;
    if(dialog.exec()){
        //Shit with this validator only accepts positive integers.
        QRegExpValidator* positiveOnly = new QRegExpValidator(QRegExp("\\d*"), this);

        dialog.itemIdText->setValidator(positiveOnly);
        int itemId = dialog.itemIdText->text().toInt();

        QString brand = dialog.brandText->text();
        QString typeOfItem= dialog.typeOfItemText->text();
        QString colorOfItem = dialog.colorOfItemText->text();

        dialog.costText->setValidator(positiveOnly);
        int cost = dialog.costText->text().toInt();

        dialog.soldText->setValidator(positiveOnly);
        int sold = dialog.soldText->text().toInt();

        dialog.weightText->setValidator(positiveOnly);
        float weight = dialog.weightText->text().toFloat();

        //doesnt need positive only validator; it can be negative
        int profit = dialog.profitText->text().toInt();
        QString dateAdded = dialog.dateAddedText->text();

        addEntry(itemId,brand, typeOfItem, colorOfItem,cost, sold, weight,profit, dateAdded);
    }
}

void item_widget::addEntry(int itemId,  QString brand, QString typeOfItem,QString colorOfItem,
                           int cost, int sold, float weight, int profit, QString dateAdded )

{
    //used to get the current date.
        QDate date;

        table->insertRows(0, 1, QModelIndex());

        QModelIndex index = table->index(0, 0, QModelIndex());
        ++globalItemId;
        itemId=globalItemId;
        table->setData(index,itemId, Qt::EditRole);

        index = table->index(0, 1, QModelIndex());
        brand[0]=brand[0].toUpper(); //Proper capitalization babey
        table->setData(index,brand, Qt::EditRole);

        index = table->index(0, 2, QModelIndex());
        typeOfItem[0]=typeOfItem[0].toUpper();
        table->setData(index,typeOfItem, Qt::EditRole);

        index = table->index(0, 3, QModelIndex());
        colorOfItem[0]=colorOfItem[0].toUpper();
        table->setData(index, colorOfItem, Qt::EditRole);

        index = table->index(0, 4, QModelIndex());
        table->setData(index,cost, Qt::EditRole);

        index = table->index(0, 5, QModelIndex());
        table->setData(index,sold, Qt::EditRole);

        index = table->index(0, 6, QModelIndex());
        table->setData(index,weight, Qt::EditRole);

        index = table->index(0, 7, QModelIndex());
        profit=sold-cost;
        table->setData(index,profit, Qt::EditRole);

        /*Adding profit to the map, with itemid key.
         * Each unique itemid holds that items profit.
        */
        globalProfitList [globalItemId]=profit;

        index = table->index(0,8, QModelIndex());

        /*We can use this if statement to see whether or not
         * this is a new entry or we are adding from a file, since
         * if dateadded is already empty, it means its new.*/
        if(dateAdded.length()==0){//If its a new entry...
        //currentdate format: tue, july 30, 2019
        dateAdded = date.currentDate().toString();
        table->setData(index,dateAdded,Qt::EditRole);
        } else {//If its NOT a new entry..
           table->setData(index,dateAdded,Qt::EditRole);
        }

       removeTab(indexOf(newItemTab));
}

void item_widget::editEntry()
{
   QTableView *temp = static_cast<QTableView*>(currentWidget());
   QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
   QItemSelectionModel *selectionModel = temp->selectionModel();

   QModelIndexList indexes = selectionModel->selectedRows();

   int itemId=0;
   QString brand;
   QString typeOfItem;
   QString colorOfItem;
   int cost=0;
   int sold=0;
   float weight=0;
   int profit=0;
   QString dateAdded;
   int row = -1;

   foreach(QModelIndex index, indexes){

       row =proxy->mapToSource(index).row();


       QModelIndex itemIdIndex = table->index(row, 0, QModelIndex());
       QVariant varitemId = table->data(itemIdIndex, Qt::DisplayRole);
       itemId = varitemId.toInt();

       QModelIndex brandIndex = table->index(row, 1, QModelIndex());
       QVariant varbrand = table->data(brandIndex, Qt::DisplayRole);
       brand = varbrand.toString();

       QModelIndex typeOfItemIndex = table->index(row, 2, QModelIndex());
       QVariant vartypeOfItem = table->data(typeOfItemIndex, Qt::DisplayRole);
       typeOfItem = vartypeOfItem.toString();

       QModelIndex colorOfItemIndex = table->index(row, 3, QModelIndex());
       QVariant varcolorOfItem = table->data(colorOfItemIndex, Qt::DisplayRole);
       colorOfItem = varcolorOfItem.toString();

       QModelIndex costIndex = table->index(row, 4, QModelIndex());
       QVariant varcost = table->data(costIndex, Qt::DisplayRole);
       cost = varcost.toInt();

       QModelIndex soldIndex = table->index(row, 5, QModelIndex());
       QVariant varsold = table->data(soldIndex, Qt::DisplayRole);
       sold = varsold.toInt();

       QModelIndex weightIndex = table->index(row, 6, QModelIndex());
       QVariant varweight = table->data(weightIndex, Qt::DisplayRole);
       weight = varweight.toFloat();

       QModelIndex profitIndex = table->index(row, 7, QModelIndex());
       QVariant varprofit = table->data(profitIndex, Qt::DisplayRole);
       profit = varprofit.toInt();

       QModelIndex dateAddedIndex = table->index(row, 8, QModelIndex());
       QVariant vardateAdded = table->data(dateAddedIndex, Qt::DisplayRole);
       dateAdded = vardateAdded.toString();
   }

   //table is only updated if dialog has any changes made to it
   add_dialog dialog;
   dialog.setWindowTitle(tr("Edit an Item"));
//Itemid, profit, and date are the only things users cant edit.
   dialog.itemIdText->setReadOnly(true);
   dialog.itemIdText->setText(QString::number(itemId));
   dialog.brandText->setReadOnly(false);
   dialog.brandText->setText(brand);
   dialog.typeOfItemText->setReadOnly(false);
   dialog.typeOfItemText->setText(typeOfItem);
   dialog.colorOfItemText->setReadOnly(false);
   dialog.colorOfItemText->setText(colorOfItem);
   dialog.costText->setReadOnly(false);
   dialog.costText->setText(QString::number(cost));
   dialog.soldText->setReadOnly(false);
   dialog.soldText->setText(QString::number(sold));
   dialog.weightText->setReadOnly(false);
   dialog.weightText->setText(QString::number(weight));
   dialog.profitText->setReadOnly(true);
   dialog.profitText->setText(QString::number(profit));
   dialog.dateAddedText->setReadOnly(true);
   dialog.dateAddedText->setText(dateAdded);


    //IF TEXT DOENST WORK PROPERLY THIS IS PROBABLY WHERE IT WENT WRONG
   if(dialog.exec()){
       QString newBrand = dialog.brandText->displayText();
       QString newType = dialog.typeOfItemText->displayText();
       QString newColor = dialog.colorOfItemText->displayText();
       int newCost = dialog.costText->displayText().toInt();
       int newSold = dialog.soldText->displayText().toInt();
       float newWeight = dialog.weightText->displayText().toFloat();
       int newProfit = 0;
       if(newBrand != brand || newType != typeOfItem || newColor !=colorOfItem ||
          newCost != cost || newSold != sold || newWeight != weight){ //if any of these attributes changes...
           QModelIndex index = table->index(row, 1, QModelIndex());
           table->setData(index,newBrand, Qt::EditRole);

           index = table->index(row, 2, QModelIndex());
           table->setData(index,newType, Qt::EditRole);

           index = table->index(row, 3, QModelIndex());
           table->setData(index, newColor, Qt::EditRole);

           index = table->index(row, 4, QModelIndex());
           table->setData(index,newCost, Qt::EditRole);

           index = table->index(row, 5, QModelIndex());
           table->setData(index,newSold, Qt::EditRole);

           index = table->index(row, 6, QModelIndex());
           table->setData(index,newWeight, Qt::EditRole);

           index = table->index(row, 7, QModelIndex());
           newProfit=newSold-newCost;//Calculate new profit.
           table->setData(index,newProfit, Qt::EditRole);

           //allocate the new profit into the map
           globalProfitList.insert(itemId,newProfit);
       }
   }
}

void item_widget::removeEntry()
{
    int itemId=0;
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    QModelIndexList indexes = selectionModel->selectedRows();

    foreach (QModelIndex index, indexes){
        int row=proxy->mapToSource(index).row();
        table->removeRows(row, 1, QModelIndex());

        //get itemid
        QModelIndex itemIdIndex = table->index(row, 0, QModelIndex());
        QVariant varitemId = table->data(itemIdIndex, Qt::DisplayRole);
        itemId = varitemId.toInt();
        ++itemId; //tbh i dont know why it gives me one lower but whatever
    }

    if (table->rowCount(QModelIndex())==0){
        insertTab(0,newItemTab, "Items");
    }
    globalProfitList.remove(itemId);
}

void item_widget::totalProfit()
{
    int iterationProfits=0;
    //iterate through the map and add up the profits
    for(auto e: globalProfitList.toStdMap()){
        iterationProfits=iterationProfits+e.second;
    }
    QMessageBox showingprofit;
    showingprofit.setWindowTitle("Total");

   // all this bullshit JUST to get the numbered current date
    QString numberedDate=QDateTime::currentDateTime().toString("MM/dd/yy");
    QString profitMessage="Total profit made as of "+numberedDate+" :          $";
    profitMessage.append(QString::number(iterationProfits));

    showingprofit.setText(profitMessage);
    showingprofit.exec();


}

void item_widget::setupTabs()
{
    //This chunk creates the alphabetized tabs
    QStringList groups;
    groups<< "ABC" << "DEF" << "GHI" << "JKL" << "MNO" << "PQR" << "STU" << "VW" << "XYZ";
    //For every group, make a new tab named after the group.
    for(int i=0; i < groups.size(); ++i) {
        QString string = groups.at(i);
        QString regExp=  QString("^[%1].*").arg(string);

        proxyModel =  new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(table);
        proxyModel->setFilterRegExp(QRegExp(regExp, Qt::CaseInsensitive));
        proxyModel->setFilterKeyColumn(1);

        QTableView *tableView = new QTableView;

        tableView->setModel(proxyModel);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->hide();
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSortingEnabled(true);

        connect(tableView->selectionModel(),
                &QItemSelectionModel::selectionChanged, this,
                &item_widget::selectionChanged);
        connect(this, &QTabWidget::currentChanged, this, [this](int tabIndex){
            auto *tableView = qobject_cast<QTableView*>(widget(tabIndex));
            if(tableView)
                emit selectionChanged(tableView->selectionModel()->selection());
        });
        addTab(tableView,string);
    }
    //This tab creates the "Everything" tab
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(table);
    proxyModel->setFilterKeyColumn(0);

    QTableView *tableView = new QTableView;

    tableView->setModel(proxyModel);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->verticalHeader()->hide();
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->setSortingEnabled(true);


    connect(tableView->selectionModel(),
            &QItemSelectionModel::selectionChanged, this,
            &item_widget::selectionChanged);
    connect(this, &QTabWidget::currentChanged, this, [this](int tabIndex){
        auto *tableView = qobject_cast<QTableView*>(widget(tabIndex));
        if(tableView)
            emit selectionChanged(tableView->selectionModel()->selection());
    });
    addTab(tableView,"Items In Order");
}


void item_widget::readFromFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(this, tr("Can't open that file."), file.errorString());
        return;
    }

    //if theres a problem check this closely
    QList<Item> items;
    QDataStream in(&file);
    in >> items;

    if(items.isEmpty()){
        QMessageBox::information(this, tr("There are no items in the file"),
                                 tr("The file you are trying to open has no items in it."));
    }else{

        //necessary because otherwise it gives me items in reverse order
        std::reverse(items.begin(),items.end());

        //"For each item, call addEntry and add it one by one".
        for(const auto &item: qAsConst(items))
            addEntry(item.itemId, item.brand, item.typeOfItem, item.colorOfItem,
                     item.cost, item.sold, item.weight, item.profit, item.dateAdded);
    }
}

void item_widget::writeToFile(const QString &fileName)
{
    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly)){
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }
    QDataStream out(&file);
    out << table->getItems();
}
