# push_swap

Sorts a stack of integers using two stacks and a small instruction set, printing the moves it uses.

## What it does

- Takes integers as separate arguments or as one quoted string (`./push_swap 3 2 1` or `./push_swap "3 2 1"`) and prints one instruction per line.
- Instructions used: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, and the reverse rotations.
- Special cases for 2 and 3 numbers, and a general algorithm for larger inputs.
- Prints `Error` to stderr and exits with status 1 on non-numeric input, duplicate numbers or values outside the `int` range. Nothing is printed when the input is already sorted.
- Sample run (this build): about 565 instructions on average for 100 random numbers (max 615 over 20 runs) and about 5100 for 500 (max 5293 over 20 runs).

## Build and run

```
make            # builds ./push_swap (clones the ft_printf dependency into printf/ on first run)
make re         # clean rebuild
make clean      # removes the .obj directory
make fclean     # removes objects and the binary
make fsanitize  # rebuilds with AddressSanitizer
```

Example:

```
./push_swap 2 1 5 4 3
./push_swap $(seq 1 100 | sort -R | tr '\n' ' ')
```

The Makefile clones `https://github.com/BahaBerkPancar/printf-42.git` into `printf/` when that folder does not exist, so it needs network access the first time.

## How it works

Stack `a` holds the input and stack `b` starts empty.

1. Push the first two numbers to `b`.
2. While `a` has more than three numbers, find the number in `a` that is cheapest to move to its place in `b`. The cost is the number of rotations (or reverse rotations) needed on each stack, and when both stacks rotate in the same direction the shared moves count once because they can be combined into `rr` / `rrr`. Move that number to `b`, so `b` is kept in descending order.
3. Sort the remaining three numbers in `a` with a hard-coded case table.
4. Push every number back from `b` to `a`, first rotating `a` so the number lands just before its next larger value.
5. Rotate `a` so the smallest number is on top.

Rotation direction is chosen by which way is shorter (a position in the first half rotates forward, in the second half it rotates backward).

## Project structure

- `main.c`: argument handling and the top-level flow
- `sort/`: the sorting logic (`sort.c`, `sort2_3.c`) and the stack operations (`move.c`, `rotate_rev.c`)
- `ext/`: input parsing, validation, min/max helpers, and a small bundled copy of libft functions (`ext/libft/`)
- `push_swap.h`: types and prototypes

This is a 42 İstanbul project.
