#BC's URM Tracer

Intro:
Binibining Comsci is studying abstract machines and in particular is interested in learning more about URM's. In order to help Binibining Comsci in her quest for dominance in the Comsci world, we need to create a URM tracer. A URM is an abstract model of a computer as discussed in class.
Our program reads a input file (ie, mp1.in) and performs the URM instructions as specified. For each line of our input, the program will display the current state of the URM on our output file (ie, mp1.out). The first line of input in the input file contains the initial state of our URM up to 10 indices (not so unlimited, eh?). The succeeding lines are the instructions that Binibining Comsci wants to test our URM with.
Important Points:
1. Code line numbers start with 1.
2. URM indices start with 0.
3. In the output file, echo the initial state of the URM on the first line.
4. Input file will contain the commands S (successor), Z (zero), C (copy) and J (jump).
5. Assume that input file will contain valid values. You may check invalid values and output an error message if you wish.
Sample execution
```
$> mp1.exe
```
Sample input (mp1.in)
```
0 0 3 0 0 0 0 0 0 0
S 0
S 1
Z 0
J 1 2 6
J 9 9 1
```
Sample output (mp1.out)
```
0 0 3 0 0 0 0 0 0 0
1 0 3 0 0 0 0 0 0 0
1 1 3 0 0 0 0 0 0 0
0 1 3 0 0 0 0 0 0 0
0 1 3 0 0 0 0 0 0 0
0 1 3 0 0 0 0 0 0 0
1 1 3 0 0 0 0 0 0 0
1 2 3 0 0 0 0 0 0 0
0 2 3 0 0 0 0 0 0 0
0 2 3 0 0 0 0 0 0 0
0 2 3 0 0 0 0 0 0 0
1 2 3 0 0 0 0 0 0 0
1 3 3 0 0 0 0 0 0 0
0 3 3 0 0 0 0 0 0 0
0 3 3 0 0 0 0 0 0 0
```