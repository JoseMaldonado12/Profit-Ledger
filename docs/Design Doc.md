## General Program Structure

### Item ID
In order to generate and use the unique item number, there is an entire class and header file whos sole purpose is 
to store the item number. This is necessary because having the correct item number is important in several different classes.

### DB Storage
The database is all stored inside a Qlist. Every time a user adds or edits an item, that corresponding item also gets
changed in the list. Rarely is the list ever touched, aside from editing, deletion or editing.

### Saving and Loading
Saving and loading files are done in two seperate functions. Saving simply saves the entire list, item by item, into the file.
Loading manually grabs each item and sends it to the "AddItem" function to avoid having to repeat code. When loading, however,
the files' items are in the opposite order in that they where originally saved as, so reversing the list is a must.

### Calculating Total
To calculate the overall total of the database, I have saved each individual "total" in a map, with its corresponding item number being its key.
(I recognize that this is redundant, as the total is already in Qlist and I can simply iterate addition. Will change this in future update.)

### Cents
Cents aren't supported due to my original client not requesting such a feature, as nearly all items are bought in flat dollars.
