Blake Collins and Justin Birdsall
------------------------------------------------

### Answers

**1.** Helgrind reports a **data race** on the shared counter `balance`: both the main thread and the worker run `balance++` with no happens-before relationship between those accesses. It points at the **`balance++` lines** in `worker` and `main`. It also shows which threads are involved, call stacks, and (often) possible conflicting access ordering.

**2.** Commenting out **one** of the two `balance++` lines removes the concurrent write to `balance`, so there is no longer a race on that variable (only one thread updates it).

**3.** Protecting **only one** of the two increments with a mutex still leaves the **other** increment unsynchronized, so Helgrind still reports a **data race** (one unprotected conflicting access is enough).

**4.** With a proper mutex protecting **both** increments (lock before `balance++`, unlock after), the conflicting accesses are ordered and Helgrind should report **no data races** on `balance` for this program.

**5.**

- **a)** A **deadlock** is when a set of threads (or processes) each hold some resource and wait on another resource held by someone else in the set, so no one can make progress.

- **b)** In `main-deadlock.c`, one thread locks **m1 then m2** and the other locks **m2 then m1**. The two threads can each take their **first** mutex and then block forever waiting for the second—the classic **lock ordering** deadlock.

**6.** Helgrind reports a **lock order violation** / potential deadlock (ordering of `m1` and `m2` differs between threads), consistent with the inconsistent lock acquisition order.

**7.**

- **b)** **No.** `main-deadlock-global.c` adds mutex **`g`** and each worker locks **`g` before** taking `m1`/`m2`. Only one thread at a time can enter the inner lock sequence, so the two threads cannot hold **m1 vs m2** in the bad pattern at the same time.

- **c)** The extra mutex **serializes** the critical section that takes `m1` and `m2`, breaking the circular wait needed for deadlock.

- **d)** Helgrind may **not** report the same deadlock here because the dangerous interleaving is prevented; tools report what the execution model allows.  **zk** What do you mean by "may not"?  What did you observe?

- **e)** **False negatives/positives** are possible: tools approximate behavior; fixing ordering in one place can hide a pattern that would deadlock without the global lock.

**8.**

- **a)** The parent **busy-waits** in `while (done == 0) ;`—a spin loop.

- **b)** The parent burns **CPU** until `done` becomes 1. If the child takes a long time, the parent keeps spinning the whole time instead of sleeping.

**9.**

- **a)** Helgrind reports a **data race** on `done` (and possibly other issues): the child writes `done` while the main thread reads it in the spin loop with no synchronization.

- **b)** The intended order often “works,” but it is **not** correctly synchronized in the C memory model sense—undefined behavior is possible; use atomics or a mutex + condition variable.

**10.**

- **a)** Condition variables let the parent **block** efficiently until the child signals, instead of spinning.

- **b)** **Both:** correct synchronization (mutex protects `done`) and **much better performance** (no busy-wait).

**11.** With mutex + condition variable used consistently, Helgrind on `main-signal-cv` should report **no data races** for this pattern (assuming no other bugs).

------------------------------------------------
