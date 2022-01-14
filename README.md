# (ll/g)db cheatsheet and tricks

## Debugging forked child process with lldb:
    Run the $program with lldb
    * lldb $program *
    `b $function_where_fork`
    Open another lldb instance and `(lldb) process attach -n $program -w`
    Continue in the parrent's instance
      
      NOTE: a sleep() may be needed in the child process in order to
      it gets attached properly.
