/***************************************************************************
JSPICE3 adaptation of Spice3e2 - Copyright (c) Stephen R. Whiteley 1992
Copyright 1990 Regents of the University of California.  All rights reserved.
Authors: 1985 Wayne A. Christopher
         1992 Stephen R. Whiteley
****************************************************************************/

/*
 * General front end stuff.
 */

#ifndef FTEdefs_h
#define FTEdefs_h

#define DEF_WIDTH   80  /* Line printer width. */
#define DEF_HEIGHT  60  /* Line printer height. */
#define IPOINTMIN   20  /* When we start plotting incremental plots. */

#include "ifsim.h"
#include "cpdefs.h"
#include "fteparse.h"

/* The curcuits that are currently available to the user. */

struct circ {
    char *ci_name;            /* What the circuit can be called. */
    char *ci_ckt;             /* The CKTcircuit structure. */
    char *ci_symtab;          /* The INP symbol table. */
    char *ci_contblk;         /* Name of control block for range analysis */
    struct line *ci_deck;     /* The input deck. */
    struct line *ci_origdeck; /* The input deck, before subckt expansion. */
    struct line *ci_options;  /* The .option cards from the deck... */
    struct variable *ci_vars; /* ... and the parsed versions. */
    bool ci_inprogress;       /* We are in a break now. */
    bool ci_runonce;          /* So com_run can to a reset if necessary... */
    wordlist *ci_commands;    /* Things to do when this circuit is done. */
    struct circ *ci_next;     /* The next in the list. */
    char *ci_nodes;           /* ccom structs for the nodes... */
    char *ci_devices;         /* and devices in the circuit. */
    char *ci_filename;        /* Where this circuit came from. */
    char *ci_defTask;         /* the default task for this circuit */
    char *ci_specTask;        /* the special task for command line jobs */
    char *ci_curTask;         /* the most recent task for this circuit */
    char *ci_defOpt;          /* the default options anal. for this circuit */
    char *ci_specOpt;   /* the special options anal. for command line jobs */
    char *ci_curOpt;    /* the most recent options anal. for the circuit */
} ;

struct subcirc {
    char *sc_name;  /* Whatever... */
} ;

#define mylog10(xx) (((xx) > 0.0) ? log10(xx) : (- log10(HUGE)))

#define DCOPY(s,d,n) {int i = (n); \
    double *ps = (double*)(s); double *pd = (double*)(d); \
    while (i--) *pd++ = *ps++; }

#define CCOPY(s,d,n) {int i = (n); \
    complex *ps = (complex*)(s); complex *pd = (complex*)(d); \
    while (i--) *pd++ = *ps++; }

#include "fteext.h"

#endif /* FTEdefs_h */
