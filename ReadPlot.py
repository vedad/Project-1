#!/usr/bin/env python
"""
Created on Fri 30 Aug 2013

Script for reading and plotting the data produced by the ThomasAlgorithm.

author: Kristoffer Braekken
"""
from matplotlib import pyplot as plt
import sys
import numpy as np

try:
    global _infile
    global _infile2
    _infile = sys.argv[1]
    _infile2 = sys.argv[2]
except IndexError:
    print 'Please specify datafile to read.'
    print 'Usage: python %s datafile.dat' % sys.argv[0]
    sys.exit(1)

def read():
    '''
    Reads the data from given datafile.
    '''
    infile = open(_infile,'r')

    global _x; _x = []
    global _y; _y = []

    for line in infile:
        columns = line.split()
        _x.append(float(columns[0]))
        _y.append(float(columns[1]))


    infile.close()

def read2():
    infile2 = open(_infile2,'r')

    global _z; _z = []

    for line in infile2:
        columns = line.split()
        _z.append(float(columns[1]))

    infile2.close()


def plot():
    '''
    Plots data.
    '''
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.plot(_x,_y, label='Numerical')
    plt.hold('on')
    ax.plot(_x,_z, label='Analytical')
    ax.legend()

if __name__ == '__main__':
    print 'Sucessfully started.'
    read()
    read2()
    print 'Files read.'
    plot()

    plt.show()
