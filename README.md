AROS-H20

Ovaj repozitorijum sadrži rad na temu iz predmeta Arhitektura računara i operativni sistemi,
fokusiran na rešavanje problema stvaranja molekula vode, kao što je prikazano u knjizi Little Book of Semaphores.

Rešenje je razvijeno u programskom jeziku C i koristi semafore i niti za koordinaciju.

Tekst problema u originalu :

There are two kinds of threads, oxygen and hydrogen. In order to assemble these threads into water molecules, we have to create a barrier that makes each thread wait until a complete molecule is ready to proceed. As each thread passes the barrier, it should invoke bond. You must guarantee that all the threads from one molecule invoke bond before any of the threads from the next molecule do. In other words:

• If an oxygen thread arrives at the barrier when no hydrogen threads are present, it has to wait for two hydrogen threads. • If a hydrogen thread arrives at the barrier when no other threads are present, it has to wait for an oxygen thread and another hydrogen thread.

We don’t have to worry about matching the threads up explicitly; that is, the threads do not necessarily know which other threads they are paired up with. The key is just that threads pass the barrier in complete sets; thus, if we examine the sequence of threads that invoke bond and divide them into groups of three, each group should contain one oxygen and two hydrogen threads.


POKRETANJE PROGRAMA

Nakon kloniranja ovog repozitorijuma, program se u terminalu pokreće na sledeći način:


Najpre je potrebno da se pozicioniramo u odgovarajući direktorijum:

[student@phones-air ~]$ cd Desktop/h20

Pokrenemo komandu:

[student@phones-air h20]$ make

A potom i komandu:

[student@phones-air h20]$ ./kompajliraniProgram

