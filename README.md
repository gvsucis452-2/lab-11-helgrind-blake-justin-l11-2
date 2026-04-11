# Helgrind

(Note: This is a very slightly modified version of the homework problems from [Chapter 27 of the OSTEP textbook](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-api.pdf).)

For this lab, you'll use a real tool on Linux to find problems in
multi-threaded code. The tool is called `helgrind` (available as part of the
valgrind suite of debugging tools).

See `http://valgrind.org/docs/manual/hg-manual.htm` for details about
the tool, including how to download and install it (if it's not
already on your Linux system). Note: Valgrind does not work on recent versions of MacOS.
I recommend you use EOS.

To begin, type `make` to build all the different programs. Examine the `Makefile`
for more details on how that works.

1. First build `main-race.c`. Examine the code so you can see the
   (hopefully obvious) data race in the code. Now run helgrind (by
   typing `valgrind --tool=helgrind ./main-race`) to see how it
   reports the race. 
   * Does it point to the right lines of code? 
   * What other information does it give to you?

2. What happens when you remove (e.g., comment out) one of the offending lines of code?

3. Add a lock around _one_ of the updates to the shared variable. What does helgrind report?

4. Now add locks around both. What does helgrind report?

5. Next examine `main-deadlock.c`. This
   code has a problem known as _deadlock_ (which we discuss in much
   more depth in a forthcoming chapter). Based on this code, 
   * Describe what a deadlock is.
   * Why specifically does this code have a deadlock?

6. Run helgrind on this code. What does it report?

7. Examine `main-deadlock-global.c`. 
   * Does it have the same problem `that main-deadlock.c`
   has? 
   * Why or why not? 
   * Should helgrind be reporting the same error? 
   * What does this tell you about tools like helgrind?


8. Look at `main-signal.c`. This code uses a variable (`done`)
   to signal that the child is done and that the parent can now continue.
   Why is this code inefficient? (what does the parent end up spending its time doing, particularly if the child thread takes a long time
   to complete?)

9. Run helgrind on this program. 
   * What does it report? 
   * Is the code correct?


10. Now look at the slightly modified version of the code found
   in `main-signal-cv`.c. This version uses a condition variable to
   do the signaling (and associated lock). 
   * Why is this code preferred to the previous version? 
   * Is it correctness, or performance, or both?

11. Once again run helgrind on `main-signal-cv`. Does it report
   any errors?
