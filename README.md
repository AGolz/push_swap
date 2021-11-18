# push_swap

**Push_swap ([42cursus](https://www.42.fr)) 2021**

**Actual Status :** Finished

**Result :** 125% 

Push_swap is a 42 Project, the goal of which is to sort the stack using a limited set of operations and as few instructions as possible. It is allowed to use only two stacks (Stack A and Stack B), as a result of the program, stack A must be sorted in ascending order from top to bottom.

There are only a few moves that are allowed to be used, let's call them "actions" :

```
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa

```
## Here's how it should work :

![stacks](https://github.com/AGolz/push_swap/blob/main/image/result%20of%20the%20algorithm.png)
```
The actions are called: sa, sb, ss, pa, pb, ra, rb, rr and rra, rrb, rrr.
```

### Commands "sa, sb, ss"

![sa, sb, ss](https://github.com/AGolz/push_swap/blob/main/image/sa%20sb%20ss.png)

### Commands "pa, pb"

![pa, pb](https://github.com/AGolz/push_swap/blob/main/image/pa%20pb.png)

### Commands "ra, rb, rr"

![ra, rb, rr](https://github.com/AGolz/push_swap/blob/main/image/ra%20rb%20rr.png)

### Commands "rra, rrb, rrr"

![ra, rb, rr](https://github.com/AGolz/push_swap/blob/main/image/rra%20rrb%20rrr.png)

## The bonus part
### The "checker" program

This program reads the instructions passed to push_swap and checks whether the stack is sorted.
```
$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
```
Run `make bonus` to compile the **checker** program.

Run using `./push_swap 3 5 1 | ./checker 3 5 1` (or `ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG`). The program should display **OK** if the instructions are correct. If the stack is still not sorted, the program will display **KO**. If you submit duplicated numbers, arguments that are not numeric or int, the program will return **Error**. The argument must be the same for **checker** and **push_swap**.

[Project instructions](/en.subject.pdf)

Need help: cfiora@student.21-school.ru

Special thanks: [elijahkash](https://github.innominds.com/elijahkash) for the [push_swap_gui](https://github.innominds.com/elijahkash/push_swap_gui)
