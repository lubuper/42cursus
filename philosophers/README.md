## ABOUT

This project addressed the classic Dining Philosophers Problem for me to learn about synchronization in concurrent programming. It involved philosophers who must alternate between eating, thinking, and sleeping, using forks to eat. The challenge was preventing deadlock and ensuring no philosopher starved by managing access to these forks.
    - Without Bonus: The focus was on using threads and mutexes for synchronization. Philosophers were represented by threads, sharing memory, with mutexes ensuring exclusive access to forks.
    - With Bonus: It introduced semaphores or processes for advanced synchronization, requiring me to handle inter-process communication (IPC) and changing a bit the rules coming from the non-Bonus version.

This project deepened my understanding of concurrency, resource management, and synchronization techniques in computer science.

For further exploration of this problem, you can consult the <a href="https://en.wikipedia.org/wiki/Dining_philosophers_problem">Wikipedia</a> article.


## HOW TO USE
#### 1º - Clone the repository
```bash
git clone git@github.com:lubuper/philosophers.git
```

#### 2º - Enter the project folder and run `make`
```bash
cd philosophers/philosophers
make
```

#### 3º - Launch the program
> The last argument is optional for the execution of the program.
```bash
./philo [n of philos] [time to die] [time to eat] [time to sleep] [n times each philo must eat]
```
#### ALTERNATE 2º - Enter the project folder and run `make bonus`
```bash
cd philosophers/philosophers
make philo_bonus
```

#### ALTERNATE 3º - Launch the bonus program
> The last argument is optional for the execution of the program.
```bash
./philo_bonus [n of philos] [time to die] [time to eat] [time to sleep] [n times each philo must eat]
```

#### MAKEFILE RULES
`make` or `make all` - Compile philosophers **mandatory** files.

`make clean` - Delete all .o (object files) files.

`make fclean` - Delete all .o (object file) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.

## MANDATORY
> Objective: can't kill the philosophers.
- [x] Each philosopher is a **thread** and each fork is a **mutex**.
- [x] They do it in order: `eat` -> `sleep` -> `think` (they don't think, they wait to have their forks to eat).
- [x] To eat they must have two forks, knowing that there is only one fork per philosopher.
- [x] If one of them dies, the simulation stops and death must be displayed in a maximum of 10 milliseconds.
- [x] Write each change of the philosopher's status.
 
## BONUS
> The bonus program takes the same arguments and it as to comply with the mandatory rules.
- [x] All the forks are put in the middle of the table.
- [x] They have no states in memory, but the number of available forks is represented by a semaphore.
- [x] Each philosopher should be a process, but the main process should not be a philosopher.

## PHILOSOPHERS

```bash
./philo [arg1] [arg2] [arg3] [arg4] [arg5]
``` 

| Arg | Function | Description |
| :- | :- | :- |
| [arg1] | `number_of_philosophers`                    | Number of philosophers and number of forks.              |
| [arg2] | `time_to_die`                               | If he hasn't eaten for time_to_die milliseconds he dies. |
| [arg3] | `time_to_eat`                               | Time to eat with two forks in milliseconds.              |
| [arg4] | `time_to_sleep`                             | Time to sleep in milliseconds.                           |
| [arg5] | `number_of_times_each_philosopher_must_eat` | Number of times each philosopher must eat. (Optional)    |

#### THREADS AND MUTEXES
A **thread** is a unit of execution within a process. Each **process** has at least one **thread**, but additional **threads** can be created. A **thread** consists of unique elements and shared elements with other **threads** of the same process, such as the code section, data section, and operating system resources like open files and signals.

However, if two **threads** of the same process try to access the same shared memory variable simultaneously, it can lead to undefined behaviours, known as **data races**. To prevent this, **mutexes** are used. **Mutexes** block a piece of code, allowing only one **thread** at a time to execute that piece of code, similar to how a toilet key is used.

In the context of the given example:
* Each fork has its own **mutex**, which can be locked when a philosopher takes it.
* There is also a **mutex** shared by all the philosophers, ensuring that text is printed without mixing.

#### STRATEGY
>To prevent conflicts and ensure proper execution, the following strategies are employed:

Make even or odd philosophers start with a delay.** If all philosophers start at the same time and take their right fork, none of them will be able to eat.

```c
if (pointer->no % 2 == 0)
		ft_usleep(10);
```
 
Each philosopher has their fork on the left (`l_fork`) and borrows the fork from their right neighbour using a pointer (`*r_fork`) that points to the left fork of the neighbour on the right.
 
```c
while (i < p->arg.nb_phils)
	{
		p->ph[i].no = i + 1;
		p->ph[i].last_meal = get_time() - p->arg.t_start;
		p->ph[i].r_fork = NULL;
		p->ph[i].arg = &p->arg;
		pthread_mutex_init(&p->ph[i].l_fork, NULL);
		if (p->arg.nb_phils == 1)
			break ;
		if (i + 1 == p->arg.nb_phils)
			p->ph[i].r_fork = &p->ph[0].l_fork;
		else
			p->ph[i].r_fork = &p->ph[i + 1].l_fork;
		i++;
	}
```
 
Death checking is performed in a separate **thread** to ensure timely detection. If the main **thread** continuously checks for death, it can significantly impact performance. So, when a philosopher performs their activities, a separate **thread** is launched to check if any philosopher has died. This **thread** sleeps for the duration specified by `time_to_die` and then checks if the philosopher is still alive.
 
```c
void	*check_death(void *data)
{
	...
	ft_usleep(dp->arg.t_until_death);
	while (i < dp->arg.nb_phils)
	{
		pthread_mutex_lock(&dp->arg.last_mutex);
		if ((get_time() - dp->ph[i].last_meal)
			>= (long int)dp->arg.t_until_death)
		{
			pthread_mutex_unlock(&dp->arg.last_mutex);
			printmsg(DEADMSG, &dp->ph[i]);
			pthread_mutex_lock(&dp->arg.end_mutex);
			dp->arg.is_dead = 1;
			pthread_mutex_unlock(&dp->arg.end_mutex);
			return (NULL);
		}
    ...
}
```
 
#### TIME MANAGEMENT
> Time can be managed using the following conversions:

| Second | Millisecond | Microsecond |
| :-- | :-- | :-- |
| 1     | 1000 | 1e+6 |
| 0.001 | 1    | 1000 |
 
The `gettimeofday` function is used to get the current time, which is stored in a timeval structure. The following example demonstrates how `gettimeofday` works:
```c
struct timeval current_time;
gettimeofday(&current_time, NULL);
printf("seconds : %ld\nmicro seconds : %d", current_time.tv_sec, current_time.tv_usec);
```
 
To get the current time in milliseconds using `gettimeofday`, the following function can be used:
```c
long int	get_time(void)
{
	struct timeval	ftime;
	long int		time;

	time = 0;
	if (gettimeofday(&ftime, NULL))
		return (-1);
	time = (ftime.tv_sec * 1000) + (ftime.tv_usec / 1000);
	return (time);
}
```
 
A custom `ft_usleep` function is created to provide more precise control over the sleep time compared to the actual `usleep` function, which waits at least the specified time. The custom function repeatedly checks the time difference until the desired time has passed.
```c
void	ft_usleep(long int miliseconds)
{
	long int	start;

	start = 0;
	start = get_time();
	while (get_time() - start < miliseconds)
		usleep(miliseconds / 10);
}
````
 
#### DATA RACES
A **data race** occurs when two or more **threads** within a single process concurrently access the same memory location, with at least one of the accesses being a write operation, and no exclusive locks are used to control the accesses. **Data races** can lead to a non-deterministic order of accesses and produce different results from run to run. While some **data races** may be harmless, many are bugs in the program.

To fix **data races**, the option `-g fsanitize=thread` can be used.

The tools `valgrind --tool=helgrind` or `valgrind --tool=drd` can be utilized to detect any missing or misused **mutexes**. Warnings or errors from these tools indicate potential issues that should be manually checked. Such issues are often signs of a problematic project, even if it appears to be working.

- `detached` refers to a **thread** that cleans its memory as soon as it finishes. It is essential to ensure that the main **thread** does not terminate before the detached **thread** completes its execution.
- `reachable` refers to a **thread** that does not destroy its memory when it finishes. The `pthread_join` function can be used to block the execution until the **thread** finishes.
 
## EXAMPLES
> The performance will change if you use `-fsanitize` and `valgrind` or both together.
 
| Example | Expected Result |
| :-- | :-- |
| `./philo 1 200 200 200`           | Philosopher 1 takes a fork and dies after 200 ms.              |
| `./philo 2 800 200 200`           | No philosopher dies.                                           |
| `./philo 5 800 200 200`           | No philosopher dies.                                           |
| `./philo 5 800 200 200 7`         | The program stops when each philosopher has eaten 7 times.     |
| `./philo 4 410 200 200`           | No philosopher dies.                                           |
| `./philo 4 310 200 200`           | A philosopher dies.                                            |
| `./philo 4 500 200 1.2`           | Invalid argument.                                              |
| `./philo 4 0 200 200`             | Invalid argument.                                              |
| `./philo 4 -500 200 200`          | Invalid argument.                                              |
| `./philo 4 500 200 2147483647`    | A philosopher dies after 500 ms                                |
| `./philo 4 2147483647 200 200`    | No philosopher dies.                                           |
| `./philo 4 214748364732 200 200`  | Invalid argument.                                              |
| `./philo 4 200 210 200`           | A philosopher dies, it should display the death before 210 ms. |
| `./philo 5 800 200 150`           | No philosopher dies.                                           |
| `./philo 3 610 200 80`            | No philosopher dies.                                           |
 

* [42 Norms](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf) - Information about 42 code norms. `PDF`
* [Norminette](https://github.com/42School/norminette) - Tool to respect the code norm, made by 42. `GitHub`
* [42 Header](https://github.com/42Paris/42header) - 42 header for Vim. `GitHub`

