# Profit Ledger
A Simple ledger app that calculates profit built with QT 5.12.2 and C++ 11.

## Project information
This program is a profit ledger, built for mostly small business/perosnal use. While this initially
started as a simple project to practice QT libraries, I have further developed it into a program useable
by anyone looking to keep track of and calculate sold items and the profit one got from selling said items. 
This is meant for people who don't want to pay a pretty penny for anything more fancy than what
you could do with a pen and paper (thought with added bells and whistles).

## Getting started
In order to get started, you can either download the src folder and compile the files yourself, or you can go to the build folder, and then the installer folder to download the installer. You can also go to build->compiled files, and the EXE will be right there, thought this is a bigger file to download and you wont be able to have either a desktop shortcut or a start menu shortcut with this option. Once the program is up and running, you will find a screen similar to this: 

![](image_src/landing_page.PNG)

Once here, you can either click on the "Tools" button on the top to add an entry, or click "Add" on this landing page- both do the same action.

Once you have added an item, it will be sorted based on the item brand. For example, if you put up some Nike shoes for sale, it would go under the "MNO" tab for Nike. Alternatively, you could also go to the "Items in Order" tab to view all items you have added to the database.

From there, you can save your database, open a previous database, add another item, delete a certain item, or edit an item.

This is an example of what a filled up database could look like.
![](image_src/filled_example.PNG)

## Sources
This program was based on Qt's own [Address Book Example](https://doc.qt.io/qt-5/qtwidgets-itemviews-addressbook-example.html) .



