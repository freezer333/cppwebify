# Automating a C++ program from a Node.js Web app
Intro to the series (post link back)

Explain again which circumstance this is best for

# Primesieve C/C++ implementation
As described in the [opening post -LINK](here), I'm building all my examples for this series around a C implementation of the [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) Prime number calculation strategy.  It's a good example problem, because speed matters big time for prime numbers - and the C code that I'm using is not exactly the type of thing you'd be eager to rewrite!  The example I'm using  - [found here](http://wwwhomes.uni-bielefeld.de/achim/prime_sieve.html) - is actually pretty simple, compared to more complex techniques that leverage CPU caching, among other things.  Head over to [primesieve.org](http://primesieve.org/) to get an idea.

To follow along, please take a look at primesieve.c now - although don't get too caught up in the details, we won't need to mess with much (that's the whole point!).

<iframe src="http://wwwhomes.uni-bielefeld.de/achim/prime_sieve.c" width="100%" height="200px"/>

## Modifications to primesieve.c
When faced with integrating an legacy program, you might not have the luxury of accessing the code.  For the purposes of this article, I'm going to simulate a few common integration scenarios - and I'll edit some bits of the original primesieve.c in order to allow for this.

First, we'll want to be able to pass a file descriptor into the main routine, so the program doesn't *always* print to the console.  Let's rename `main` to `generate_args` and add a third parameter for the file descriptor.  We'll make specific use of this in Example 3 below.

I'll write the entry point in a different file (`main.cpp`), so I'm also adding the declaration of `generate` to a header file called `prime_sieve.c`.

I'm also creating a second function - `generate`, also available through the header, that provides a simplified interfaced - it just accepts the "under" parameter instead of command line arguments.  The definition is at the bottom of prime_sieve.c, and just transforms the parameter into character arguments and calls `generate_args`.  This is just so I don't edit the original code much, and to make Example 2 below a little cleaner.  Obviously, the creative reader can figure out better ways of doing all this :)

So, we're left with the following prime_sieve.h header - appropriately using `extern C` to make sure our C functions can be integrated correctly with the C++ main files I'll use in the examples.

```c
extern "C" {
    // the old main, renamed - with a third parameter
    // to direct output to a file as needed
    int generate_args(int argc, char *argv[], FILE * out);

    // an adapter function when the caller hasn't
    // received under through command line arguments
    int generate(int under, FILE *out);
}
```

# The Node.js Child Process API
Do a detailed overview of the different options.
Why the sync options aren't good for the web

# Example 1:  C++ Program that gets input command-line arguments
The simplest type of program to automate is a program that will accept all of it's input as command line arguments and dump it's output to stdout - so we'll start with this scenario.

So - let's "imagine" primeieve works like this (actually, it basically already does!).  To use the application, we might type:

```
> primesieve 10
2
3
5
7
# {1 <= primes <= 10} = 4
0.000000000000  -3.464368964356
```
And we'd get all prime numbers under 10 print out to the screen (one on each line) - plus some extra info printed by the program that we don't need.  

*I'll keep the output easy to parse in all my example - obviously if your program spits out data in a tough-to-parse way, you'll have a bit more work to do.*

## Using node-gyp to compile
## Automating from Node.js

# Example 2:  C++ Program that gets input from user (stdin)

## Modifications to primesieve.c


# Example 3:  C++ Program that gets output from input file

## Modifications to primesieve.code


## Dealing with File-based program on the web
You have multiple simultaneous requests - need to protect input/output File-based

# Conclusion, up next
