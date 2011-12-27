Command Line Analysis (CLA)
===========================

An extendable tool suite for data analysis from the command line.

This suite of tools enables exploratory data analysis from the command
line.  The `cla` executable accepts data through `STDIN`, feeds that
data to an easily extendable set of analytic modules, and outputs
their results to `STDOUT`.  The goal of the `cla` system is to provide
*no configuration required* data analysis ranging from simple means
and correlations to more sophisticated machine learning on the command
line for exploratory data analysis.

### Usage

To use cla first define the `CLA_MODULE_DIR` environment variable to
point to `modules/` in this directory.

    export CLA_MODULE_DIR=/home/user/src/cla/modules

Add the `cla` executable in the `bin/` sub-directory of this
repository to your path.  Use the `-h` option to see the available
command line flags.

    $ cla -h
    Reads data from STDIN and writes analysis to STDOUT.

    The following options may be specified.
            -i      turn on incremental results
            -m DIR  specify DIR as the cla module directory
            -t DIR  specify DIR as the cla tmp directory

Then pipe data (for example from `bin/sine`) into `cla`.

    $ ./bin/sine|cla 
    sum     164.985
    stdev   0.518419
    min     -.75680249530792825137
    mean    0.412461
    max     .99999968293183462021
