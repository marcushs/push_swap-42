# **Push_swap**  

## **Project introduction**  
  
Push_swap is an algorithm exercise, aimed to teach us about complexity.  

The objective of this project is to find the most efficient way to sort a random list of integers in ascending order under certain given constraints.  

### **The rules:**  

- We are given two stacks, stack A and stack B.  
- At the beginning:  
	- Stack A holds a list of random number of negative and/or positive integers, with no duplicate of any of the intergers.  
	- Stack B is empty at this instance.  
- As mentioned above, the aim of this exercise is to sort the random list of integers in ascending order. In order to do that, we are give a set of instructions we can use to manipulate the list:  
	- `sa` (swap a): Swap the first 2 elements in stack A. Nothing happens if stack A is empty or has only one element.  
	- `sb` (swap b): Swap the first 2 elements in stack B. Nothing happens if stack B is empty or has only one element.  
	- `ss` Execute `sa` and `sb` at the same time.  
	- `pa` (push a): Move the top element of stack B and place it at the top of stack A. Nothing happens if stack B is empty.  
	- `pb` (push b): Move the top element of stack A and place it at the top of stack B. Nothing happens if stack A is empty.  
	- `ra` (rotate a): Shift the whole stack A upward by one position. The first element becomes the last element. In other words, move the first integer in stack A and put it at the bottom of stack A.  
	- `rb` (rotate b): Shift the whole stack B upward by one position. The first element becomes the last element. In other words, move the first integer in stack B and put it at the bottom of stack B.  
	- `rr` Execute `ra` and `rb` at the same time.  
	- `rra` (reverse rotate a): Shift the whole stack A downward by one position. The last element becomes the first element. In other words, move the last integer in stack A and put it at the top of stack A.  
	- `rrb` (reverse rotate b): Shift the whole stack B downward by one position. The last element becomes the first element. In other words, move the last integer in stack B and put it at the top of stack B.  
	- `rrr` Execute `rra` and `rrb` at the same time.  

## **The algorithm**  
Before starting this project, I did some research on different algorithms and how people have done it in the past. I read a few blog posts and got inspired by the works of Jamie Dawson, Anya Schukin and A. Yigit Ogun, I would like to express my gratitude to these fantastic people.  

### **Structure of my program**  
After my research, I decided to work with **Doubly Circular Linked List**. Prior to this project, I had no experience wth this data structure, I only knew normal linked lists. Storing my stacks at a Doubly Circular Linked Lists gives me a few advantages:  
- Possible to traverse the lists from the head or the tail, this makes accessing the first or second half of the lists more efficient, especially when we have a large list.  
- Contrary to arrays, we would not need a large chunk of contiguous memory to store the lists.  
- Easier memory management, no need to `malloc` everytime the stacks change in size, or allocate a fixed size of memory for both stacks when we do not actually need those extra memory. We only need to allocate the number of nodes once and free the whole stack at the end of our program.  

The structure we need is called t_stack, and the node looks like this:  
```c
typedef struct s_stack 
{
	long			nb;
	int				index;
	struct s_stack	next;
	struct s_stack	prev;
}					t_stack;
```  
As we are not working with arrays, we will not have indices, hence I added `index` in the structure, making a node more voluminous.  

### **Command line arguments**  

The program we create, `./push_swap` can take a range of numbers of command line arguments. For example: 
```bash
./push_swap 2 1 3 6 5 8
```
```bash
./push_swap "2 1 3 6 5 8"
```
```bash
./push_swap "2 1" 3 6 "5 8"
``` 
or 
```bash
$>ARG="4 67 3 87 23"; ./push_swap $ARG
``` 
are all valid.  

In order to be able to handle all these different cases, I decided to separate my parsing into 2 different files, `check_1_arg.c`, to handle cases where the list of integers are given inside one set of quotes (1 command line argument/list as a variable) and `check_args.c` to handle cases where numbers are given one by one or mix with sublists of numbers between quotes.  

#### **check_1_arg.c**  

The main function of this file is:  
```c
t_stack	*check_1arg(char *argv);
```  



