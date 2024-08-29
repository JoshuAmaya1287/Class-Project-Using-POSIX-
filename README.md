
To run this program you should first put all these documetns into a folder, then after that you should go into nano and compile each and eveyr single doucemnt ,For example, "gcc -c main.c -pthread". 

Then after the five C source code files are compiled to the object files, use the following command to link the files and compile for the final executable file:
gcc -o sleeping_ta main.o ta.o student.o programming.o help_student.o -pthread

When the program is executed, it should show enough information to simulate the TA-student scenario
