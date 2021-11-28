# proc-mem-attack
Demo of proc/mem attack for full code execution in presence of ideal fine-grained CFI with shadow stacks.

Includes an *intentionally vulnerable* custom Nginx module that models an arbitrary-read-and-write memory vulnerability. The proof of concept exploit executes arbitrary code in the target process even in the presence of fine-grained CFI with shadow stacks.

For context on how the attack works, see chapter 4 of the paper:

Connor, Richard J. III, "Improved Architectures for Secure Intra-process Isolation. " PhD diss., University of Tennessee, 2021.
https://trace.tennessee.edu/utk_graddiss/6533
