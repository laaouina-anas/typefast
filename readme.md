# What is this ?

This is a simple C program that takes all the words in the english dictionary and
takes a bunch of them (currently 50) and puts them on a text file, the purpouse of this code is to 
help people learn how to touch type (after getting sufficient initial muscle memory)
and develop finger dexterty and fine motor skills by helping them practice on unusual words.
Another benefit of this program is that when practicing, the brain is urging for
speed, by practicing on hard words, the brain can't get into the state of "autopilot" which helps
focusing on accuracy rather than speed.

# How can I use this ?

Clone this repo, and compile the single .c file inside this project into an executable.
```bash
git clone "https://github.com/laaouina-anas/typefast"
cc type.c -o type
```
Put this executable whenever you want, so your operating system can find it.

Everytime you want to practice, execute the program and go to *practice*.txt in your favourite
text editor.
When you execute the program the word set will get updated by new ones, practice slowly.

# Notes 

This project could've been easily made in python or an easier language instead of C, yet I wanted
to make this purely for learning.
As for practical developement purpouses, this project is not performance critical (even for 300k words)
and i think python would have been an eaiser choice.

# Challenges

The main challenge that I faced in this program is the beloved Windows carriage return '\r'
instead of being like normal people ( UNIX ) and adding a simple '\n' for newline, windows says nooo
i'll add a newline and carriage return, why ? for no reason yet to disturb people like me.
I am kidding, there is a reason .. It has to do with legacy software and backward compatibility.

# Bugs

If you found a bug or room for further improvement, you are totally free ...
