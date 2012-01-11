Command Line Analysis (CLA)
===========================
An extendable tool suite for data analysis from the command line.

This suite of tools enables exploratory data analysis from the command
line.  The `cla` executable accepts data through `STDIN`, feeds that
data to an easily extendable set of analytic modules (just shell
scripts), and outputs the modules results to `STDOUT`.  The goal of
the `cla` system is to provide *no configuration required* data
analysis ranging from simple means and correlations to more
sophisticated machine learning.

### Usage

##### Instillation
First build the two small C helper functions by running `make` in this
directory.  Then add both the `bin` and `modules` sub-directories to
your path.  For example by placing the following in your `~/.bashrc`,
`~/.zshrc` or `~/.profile` as appropriate.

    export PATH="$PATH:/path/to/cla/bin:/path/to/cla/modules"

##### Command line usage
Use the `-h` option to see the usage information.

    $ cla -h
    Usage: cla [OPTION]... [MODULES]...
    Process data from STDIN with multiple modules.
            -h      display this help
            -i      print incremental results
            -t TDIR specify TDIR as the cla tmp directory

Data piped to `cla` will be passed through to any modules specified
after `cla` on the command line.  The `-i` option will enable the
display of incremental results during processing.  See below for
example usage.

##### Check
To check that everything is working properly pipe data (for example
from the `./test/sine` script in this directory) into `cla`.

    $ ./test/sine|cla min max mean stdev
    min     .00999983333416666468
    max     .84147098480789650665
    mean    0.463901
    stdev   0.247021

### A word on Modules
"Modules" are simply commands which accept data on `STDIN` and print
results to `STDOUT`.  A module may print any number of lines of output
over the course of an execution, each line will be considered to be an
updated result and will replace all previous lines.

It is possible to pass command-line arguments to modules through
`cla`, for example the following uses the excellent
[feedgnuplot](https://github.com/dkogan/feedgnuplot) package to graph
data as it is being processed.

    $ ./test/sine 4000|cla mean 'feedgnuplot --stream' stdev

The pipe-based module design is intended to make the process of adding
new modules as simple and language-agnostic as possible.  The real
value of this tool suite and repository will be as a place in which to
accumulate no-configuration analytic tools usable from the command
line.  The value of cla will be directly proportional to the number
and quality of included modules, so please contribute!

### License
Licensed under the GPLV3, see the COPYING file in this directory for
more information.
