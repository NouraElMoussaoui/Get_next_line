# Get_next_line 

This project is a C programming task that involves creating a function to read a line ending with a newline character from a file descriptor. The function is called get_next_line.


## Functions

* isline: This function checks if a newline character ('\n') exists in the string save. It returns 1 if a newline character is found, and 0 otherwise.

* re_save: This function reads from a file descriptor fd into a buffer, then appends the contents of the buffer to the string save using the ft_strjoin function. It continues reading and appending until a newline character is found in save (as determined by the isline function) or until an error occurs during reading. In case of an error, it frees save and sets it to NULL.

* return_line: This function is designed to extract a line from the save string and return it.

## Usage
To use this project, you would typically call the get_next_line function in a loop to read a file line by line. The function is expected to return a string containing the next line from the file each time it is called, or NULL when there are no more lines to read.

## Note
This project is part of the 42 School curriculum. The 42 School is a network of non-profit, tuition-free, technology schools that teaches software engineering
