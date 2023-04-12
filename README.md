# Welcome to My Mastermind
***

## Task
The task is to write a program simalar to the famous game named Mastermind. In this game a hidden code of 4 digits is giving
or genarated randomly and the user have to guess it. He have 10 attemps, after each attemps the program have to give a feedback on the numberof well placed and misplaced pieces.
## Description
The program use the getopt() function to parse the hidden code and the number of attemps passed by argument in the terminal.
The number of attemps is set by default to 10 and the code is generate randomly using rand() and srand() and time() , in the case where they are not specified by the user.

To get those values I create a void function named get_input() that take as input an array of char and the lenght of this array ( in this case the lenght of the code, without forgeting the null terminated value).
This function also handle the ctrl+d for exiting.
I also create a return function named genarate_random() that take as parameter le lenght of the code and return the address of the first element of a random code (4 digit in range 0 to 8) that is null-terminated value.


An If statement logic and the strncmp function are used to check if the guessed code suggested by the user match with the hidden code. If it matched, a congratulation message displayed to the user and the game end otherwise the program send a feedback to the user mentionned 
the number of well placed pieces and the number of misplaced pieces until the user win or the number of attemps finish.
## Installation
I do not instal anything

## Usage
TODO - How does it work?
To make the code work follow this setp in the terminal:
$make (this command will compile the program with all the flags required and generate an executable file and an object file)
$./my_mastermind (this will make the program genarate a random code and set the attemps by default to 10. You will immediatly starting enjoying your game)
$./my_mastermind -c"1234" -t"10" (this is when you want to specify the hidden code and the number of attemps by your self , the values inside the " " can be change by your conveniance)
```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
