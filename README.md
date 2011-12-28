Command Line Analysis (CLA)
===========================

An extendable tool suite for data analysis from the command line.

This suite of tools enables exploratory data analysis from the command
line.  The `cla` executable accepts data through `STDIN`, feeds that
data to an easily extendable set of analytic modules (just shell
scripts), and outputs their results to `STDOUT`.  The goal of the
`cla` system is to provide *no configuration required* data analysis
ranging from simple means and correlations to more sophisticated
machine learning.

### Usage

To use cla first add both the `bin` and `modules` sub-directories of
this directory to your path.  For example by placing the following in
your `~/.bashrc`, `~/.zshrc` or `~/.profile`.

    export PATH="$PATH:/path/to/this/dir/bin:/path/to/this/dir/modules"

Use the `-h` option to see the available command line flags.

    $ cla -h
    Reads data from STDIN and writes analysis to STDOUT.

    The following options may be specified.
            -h      print usage information
            -i      toggle incremental results
            -t TDIR specify TDIR as the cla tmp directory
            -m MODS specify a comma seperated list of modules to use

Then pipe data (for example from `bin/sine`) into `cla`.

    $ alias sine="for x in \`seq 400\`;do echo \"s(\$x/100)\"|bc -l; done"
    $ sine|cla -m min,max,mean,stdev
    sum     164.985
    stdev   0.518419
    min     -.75680249530792825137
    mean    0.412461
    max     .99999968293183462021

### License

Licensed under the GPLV3, see the COPYING file in this directory for
more information.
