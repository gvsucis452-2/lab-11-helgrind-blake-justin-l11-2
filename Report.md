Blake Collings and Justin Birdsall
------------------------------------------------
1. 
First build main-race.c. Examine the code so you can see the (hopefully obvious) data race in the code.
    
    a) Run helgrind (by typing valgrind --tool=helgrind ./main-race) to see how it reports the race.

    b) Does it point to the right lines of code?

    c) What other information does it give to you?

2. 
    
    What happens when you remove (e.g., comment out) one of the offending lines of code?

3. 

    Add a lock around one of the updates to the shared variable. What does helgrind report?

4. 
    
    Now add locks around both. What does helgrind report?

5. 
Examine main-deadlock.c. This code has a problem known as deadlock. Based on this code,


    a) Describe what a deadlock is.

    b) Why specifically does this code have a deadlock?

6. Run helgrind on this code. What does it report?

7. 
Examine main-deadlock-global.c.

    b) Does it have the same problem that main-deadlock.c has?

    c) Why or why not?

    d) Should helgrind be reporting the same error?

    e) What does this tell you about tools like helgrind?

8. 
Look at main-signal.c. This code uses a variable (done) to signal that the child is done and that the parent can now continue. 

    a)Why is this code inefficient?

    b) What does the parent end up spending its time doing, particularly if the child thread takes a long time to complete?


9.

    a) Run helgrind on this program.

    b) What does it report?

    c) Is the code correct?

10. 
Look at the slightly modified version of the code found in main-signal-cv.c. This version uses a condition variable to do the signaling (and associated lock).

    a) Why is this code preferred to the previous version?

    b) Is it correctness, or performance, or both?

11. 
Once again run helgrind on main-signal-cv.

    Does running helgrind on main-signal-cv report any errors?
-------------------------------------------------
Answers:

1. 
    
    After running helgrind on the main-race program it does point to the correct lines of code.

2. 

    Commenting out one of the problem lines. 

3. 

    Helgrind reports that after ...

4. 

    Looking at helgrind after adding locks it reports ....

5. 

    Examining this code a deadlock is ...

6. 

    Running helgrind on the deadlocked code reported ....

7. 

    This code is particuarlly innefecient because... This is hilighted by ...

8.

9.

10. 

    This approach is preferred ...

11. 

    Looking at the output of helgrind on main-singal-cv ... 
