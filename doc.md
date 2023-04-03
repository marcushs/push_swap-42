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

This function is called when `argc == 2`, it first count how many elements are inside, if there is none, we consider that there is nothing to be sorted, hence exiting the program without `Error` message.  

Then we call `ft_split` to turn the argument into an array of strings. Next, this array of strings will be passed to a function which converts the strings into an array of `long int`. It first check if all the characters are valid, then, with the help of our `ft_atoi`, they are converted to `long`. Why `long` you may ask, because we need to handle the `MAX_INT` and `MIN_INT` cases, so we store every element as `long` and we check if it is in the range of an `int`.  

After that, we will check if there are duplicates with another function `check_double`, if no error has occured in the whole process, function `arr_to_list` is called to create a doubly circular linked list with all the elements, the list will be returned as `stack A`.  

#### **check_args.c**  

As the name suggests, this function is called when we have more than one arguments:  
```c
t_stack	*check_args(int argc, char **argv);
```  

It follows the same logic as `check_1arg`, it first counts the total number of elements (including multile elements inside quotes), then with the know number of elements we allocate memory for the array of `long`.  

Next, we call function `args_to_arr` to put arguments into the array, and at the same time we check if the characters are valid and the numbers are in range. (Note for `args_to_arr`: passed the `long` pointer to this function and I increment and dereference the pointer everytime to put a number to the array, a `tmp` pointer is set to be equal to arr, in case errors occur, it could be used to free the whole array instead of part of it since the pointer is being incremented).  

Same as `check_1arg`, the array is then passed to `check_double` to see if there are duplicates of a same number. If no error, `arr_to_list` is called to create `stack A`.  

### **Solve**  
Now that we checked that our entries have no error and we have a `stack A`, we call `solve` to finally sort our list of numbers.  

`solve` is a general function, there are 2 main parts, `solve_5_or_under` and `solve_large_list`. As their names indicate, they handle lists of 5 or less elements and everything more than 5 elements respectively.  

#### **solve_5_or_under**  
Let's start with smaller lists that have 5 elements or less.  

The magic number of this algorithm is `3`, why 3? Because we know that for `n` number of elements, we have `n!` permutations, one of them being already sorted, we actually have `n! - 1` possibilities. For a list of 3 random numbers, we have 5 possibilites.  

If we know how to sort 3 numbers, the rest is fairly easy.  

My approach of sorting 3 numbers is to find the index of the smallest number `min` in the list. If it is in the last position, one `rra` is enough, then I check if `stack A` is sorted, if it's not, I continue. Now `min` is at index 0 and that the list is not sorted, there is only one possibility which is the biggest number `max` is at index 1. All we need to do is `rra` to bring the second number to the top and `sa` once to make the list sorted.  

Now that we have a functional `solve_3` function (pun intended haha), we start dealing with 4 and 5 numbers. We would like to first push 1 or 2 numbers to `stack B`, sort 3 numbers in `stack A` and push the numbers back.  

To do so, for 4 numbers, I would like to push `min` to `stack B` because I only can directly push it back to the top of `stack A` after the 3 numbers are sorted. So I first find the index of `min`, if it is in the upper half, I `sa` till it reaches the top, otherwise I `rra` until index of `min` is 0. Then I push it to `stack B` and sort `stack A`. Finally I push `min` back and its done!  

For 5 numbers, basically the same, but this time I want to push `max` over first, then I call `solve_4` which will push the smallest to `stack B`. At this point, we have a `stack B` in ascending order. After the 3 elements in `stack A` are sorted, we push `min` and `max` back to `stack A`. `min` will be at index 1 (second position) and `max` at top, all we need to do is one `ra` and the whole stack is sorted, that is why we wanted `stack B` to be in ascending order.  

#### **solve_large_list**  

The main part of this project is this, sorting a large list of numbers.  

Learning from A. Yigit Ogun, I also took the approach of pushing everything to `stack B` until there are only 3 elements left in `stack A`. We sort `stack A` and push everything back.  

These are the 2 functions, their names are pretty self-explanatory:  

```c
void	push_b_sort_3_a(t_stack **a, t_stack **b);
```  

```c
void	push_back_a(t_stack **a, t_stack **b);
```  

However, we do not push everything to `stack B` randomly.  

This is why we have a `smart_rotate` function, as called AdrianWR.  

#### **smart_rotate_till_3_in_a**  

This is my version:  

```c
void	smart_rotate_till_3_in_a(t_stack **a, t_stack **b);
```  

The ground rule when pushing to `stack B` is that we would like it to be somewhat in a descending order, so when we push back to `stack A` it would be in ascending order. We have to keep in mind that the calculations we do next when finding the cheapest moves are the complete opposite when pushing to `stack B` than when we are pushing to `stack A`.  

Hence, I have a helper function  

#### **best_rotate_comb_a_to_b**  

```c
int	best_rotate_comb_a_to_b(t_stack *a, t_stack *b);
```  

which I call in `smart_rotate_till_3_in_a` that helps me to determine which rotate combination is going to take the least operations. We loop through the list and count, for each element the number of steps it would take to place the number in the right place.  

`best_rotate_comb_a_to_b` finds the best rotate combination (with least amount of steps), there are 4 possible combinations: `ra` and `rb`, `rra` and `rrb` , `rra` and `rb`, `ra` and `rrb`.  

For each combination, we have a function that counts its number of operations thanks to our function:  

```c
int	find_target_index_b(t_stack *b, long push_nb);
```  
we are able to determine where we should place a number.  

When pushing from `stack A` to `stack B`, if the number being pushed will become the new `min` or `max` of `stack B`, we place it above the old `max` in `stack B`, so we either only need to `rb` once to make it in descending order, or it is already in descending order.  

To do this, we need a number (whatever number that is) in `stack B` (being the only and hence `max`) to determine the correct positions for other numbers, so we push the first 2 numbers without checking anything at the beginning.  

When the number is neither `min` nor `max`, there are two possible cases: 1) if it's greater then the top number and smaller than the last number, it will be placed on top; 2) otherwise it will be in the stack and should be in between the 2 closest numbers (descending order). Always, we want the numbers to stay as closest as possible. This will create 2 substacks in `stack B`, both in descending order, seperated by `min`, this will cost even fewer operations.  

Here are the 4 functions:  

```c
int	ft_count_rarb(t_stack *a, t_stack *b, long nb);
```  

It compares `find_target_index_b` with the number's index, the greater one will be returned.  

```c
int	ft_count_rrarrb(t_stack *a, t_stack *b, long nb);
```  

It compares `lst_size - find_target_index_b` and `find_index_back` (because we have a dcll, we can count from the back to be faster), to see how many steps it would take to get to our target place using reverse rotate. The greater one will be returned.  

```c
int	ft_count_rrarb(t_stack *a, t_stack *b, long nb);
```  

We return the number of `find_index_back` to determine the number of `rra` needed plus `find_target_index_b`, number of `rb` needed.  

```c
int	ft_count_rarrb(t_stack *a, t_stack *b, long nb);
```  

This last one return the sum of `lst_size - find_target_index_b` to determine the number of `rrb` and `find_index`, number of `ra` needed.  

#### **run_combo.c**  

We have now determined which rotate combination takes the least amount of steps, we need to run it!  

```c
int	ft_run_rarb(t_stack **a, t_stack **b, long nb, char c);
```  

This is one of the four functions, as an example. For `ra` and `rb`, and `rra` and `rrb`, we have the option to run `rr` and `rrr` as well to lower the steps. We just execute `rr` or `rrr` until the number we want to push is at the top or the target_index becomes 0, then we finish off the other operations before pushing.  

That's it! This is the core of my `smart_rotate` function. When it's done, and only 3 elements are left in `stack A`, sorted, we can push the numbers back from `stack B`.  

As I mentionned above, push to `stack A` follows the same logic, just the opposite when it comes to finding the right index to place a number, that's why I have `cases_b_to_a.c` and function `best_rotate_comb_b_to_a` to handle this part.  

### **Operations**  

Since this is the first time I worked with a doubly circular linked list, I would like to document the way I coded the operations.  

I categorized and seperated them into:  
-	`swap.c`  
-	`push.c`  
-	`rotate.c`  
-	`rrotate.c`  

I realized that whether the actions are done in `stack A` or `stack B`, the are fundamentally the same, for each category I created a function which can be used for both: `ft_swap`, `ft_push`, `ft_rotate` and `ft_rrotate`.  

However, in each file I still created a function for each operation, meaning that I have `ft_sa` for `sa`, `ft_rrr` for `rrr` etc., because it is easier to make this function calls when I was coding, it is a sort of abstraction, which is less error prone.  

The main point of a doubly cirular linked list is that everytime I execute an operation, I have to update the pointers not to break the lists.  

The most complicated one was `swap`, I would say, so I will talk about this one here.  

When the list have more than one nodes, we have 2 possibilities: there are 2 nodes or more.  

If there are only 2 nodes, things are simple, we just update the head pointer to point to the second node in the list (head->next), as they are forming the circle, this action is enough to swap the list and pointers are intact.  

When there are more than 2 nodes, we have more work to do. I first initiate a pointer `first` which point to the head node and `second` which point to the second one (`head->next`), of course. This will prevent long -> party, I assure you, we get lost pretty fast.  

Order of the actions are also crucial, so becareful of the pointers, if they are already updated or not. For example, if we already pointed the next of first to the third one (`second->next`), we can't say `first->next->prev = head->prev` (last one) because `first->next` is already the third one and no longer `second`, that's why we set up new pointers to make things more clear.  

So in the case of swap, we link the `next` of `last` to `second`, `prev` of `second` to `last`; then `next` of `first` to `third` (`second->next`) and `prev` of `third` to `first`; finally `next` of `second` to `first` and `prev` of `first` to `second`.  

Lastly, don't forget, to update `head` and point it to `second` as it is now the new `head`.  
