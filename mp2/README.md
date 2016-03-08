#Binibining Comsci Problems (Deterministic Finite Automata)

###Intro:

Once upon a time, Binibining Comsci was taking her pet lion, her pet rabbit, and a carrot back to her farm. She came to a river, and had to get all three possessions (lion, rabbit, carrot) across the east bank. Because of the nature of the river, she could only carry one possession across at a time. This means that she had to leave the other two possessions on the shore while she carried the one across.

The problem is that, the lion would eat the rabbit if unattended, and the rabbit would eat the carrot if unattended. The lion could be left with the carrot safely, of course.

What sequence would the man need to take his possessions across, in order not to have any of them eaten?



###Important Points:

1. The lion will not eat the rabbit if Binibining Comsci is with them. The same is true for the rabbit and the carrot.

2. The lion, rabbit and carrot can not navigate the river by themselves!


###Problem:

Given a string representing the steps to be performed by Binibining Comsci, our program will tell us if it is a valid transition or not. (ie, everyone survives!). The program will receive a series of inputs from a file (ie, mp1.in), processes each input and writes the corresponding output in a separate file (ie, mp1.out). Each input is separated by a new line.

The sequence of moves/steps will be encoded as a string using the following symbols:

- Man crosses with lion (L)
- Man crosses with rabbit (R)
- Man crosses with carrot (C)
- Man crosses with nothing (N)

So the string RNLRCNR describes the following steps:

1. Cross the river with rabbit. R

2. Return to west bank with nothing. N

3. Cross the river with lion. L

4. Return to west bank with rabbit. R

5. Cross the river with carrot. C

6. Return to west bank with nothing. N

7. Cross the river with rabbit. R

Sample execution
```
$> mp1.exe
```
Sample input (mp2.in)
```
RNLRCNR
RNNNLRCNR
RNLNCN
```
Sample output (mp2.out)
```
OK
OK
Nope
```