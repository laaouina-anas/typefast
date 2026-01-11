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

I made this project because I was learning C, I was reading K&R book, and simultaneously I suffered from touch typing inaccuracies, thus I decided to code this in pure C.

As for practical developement purpouses, this project is not performance critical (even for 300k words)
and i think python would have been an eaiser choice.

Also and this is important, this project has a lot of limitations, the words aren't random to my surprise, the algorithm I used is called "reservoir sampling" ,I used it unknowingly and intuitively because I had a question : How do I print N random english words on the screen ? the answer that screams itself it to store all the words, maybe suffle them and display first k words, yes I works yet it loads 300k words ~ 4MB words into memory for no reason.

Originally I mistakenly used fseek thinking It'll make me go to the desired line, yet after a second look I quickly realised my error. 

So I end Googling (and seeing IA generated code), it simply said that there is no way to go to Kth line without traversing the (K-1)th lines before, lines are just a humanly imposed convention, machines in constract only know the \n or a sequence of bytes that mean add a new line, and the content of the file, whatever the file may be is just a stream of bytes.

So .. Still slow, I'll need to go to a random line each iteration, and for each iteration traverse the 300k words, so inefficient..

Later in I had this idea : What If I can project myself inside the stream of bytes/characters, surely I'll be on a random line, yet anywhere inside, then just go to the begining, and pick up the word (alternatively pick the first word you encounter), Genius! Untill It isn't, although this is what I wanted, O(1) word retrieval, the words are no longer picked up randomly, using "reservoir sampling" statistically the longer words have more probability to be selected, the words are no longer selected "randomly" as I first intended, yet as longer words are better for practice, and I don't know how to even the distribution, I'll keep it as is .. just for now.


# More challenges ...

A challenge I faced is when I copied the .txt file containing all words, this file was made on windows so it had \r\n for newline instead of \n like on UNIX systems, this caused the script to crash, on a text editor (neovim in my case) it displayed a ^M symbol after each word .. only after researching I knew it was the carriage return.
To adress this issue, a simple if statement was added .. Thank you Windows !


# Conclusion

Hey! you've been reading this or just took a look inside my repo, thank you so much... really appreciate it.
