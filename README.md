# (ll/g)db cheatsheet and tricks

## Debugging forked child process with lldb:
   Run the $program with lldb
   
   ` $ lldb "program" `
   
   ` $ b @function_where_fork `
   
   Open another lldb instance and `$ (lldb) process attach -n "program" -w`
   
   "Continue" in the parrent's instance (not next)
      
      NOTE: a sleep() may be needed in the child process in order to it gets attached properly.

# operation

1. compile the code
```gcc example.c -g3 -o program```

2. instance or window 1
 * lldb  programm
 * b main
 * r
 * (press n to the fork instruction)

3. instance or window 2
 * lldb
 * process attach -n program -w

4. instance or window 1
 * press c

5. instance or window 2
 * press c

6. instance or window 1
 * enter a number
