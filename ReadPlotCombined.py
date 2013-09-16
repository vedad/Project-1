import matplotlib.pyplot as plt
import numpy as np


def read():
    '''
    Reads the data from given datafile.
    '''
    infile = open("analyticalDataN1000.txt",'r')

    global _x; _x = []
    global _y; _y = []
#    global _z; _z = []

    for line in infile:
        columns = line.split()
        _x.append(float(columns[0]))
        _y.append(float(columns[1]))
#        _z.append(float(columns[2]))

    infile.close()

def read2():

    infile = open("numericalDataN10.txt",'r')

    global _xN10; _xN10 = []
    global _numN10; _numN10 = []

    for line in infile:
        columns = line.split()
        _xN10.append(float(columns[0]))
        _numN10.append(float(columns[1]))

    infile.close()

def read3():

    infile = open("numericalDataN100.txt",'r')

    global _xN100; _xN100 = []
    global _numN100; _numN100 = []

    for line in infile:
        columns = line.split()
        _xN100.append(float(columns[0]))
        _numN100.append(float(columns[1]))

    infile.close()

def read4():

    infile = open("numericalDataN1000.txt",'r')

    global _numN1000; _numN1000 = []

    for line in infile:
        columns = line.split()
        _numN1000.append(float(columns[1]))

    infile.close()


def plot():
    '''
    Plots data.
    '''
    fig = plt.figure()
    ax = fig.add_subplot(111)
    fig.suptitle('Comparison of $u(x)$ (analytical) and $v(x)$ (numerical)\n for the 1D Poisson equation.')
    ax.set_xlabel('$x$', fontsize='16')
    ax.set_ylabel('$u(x), \ v(x)$', fontsize='16')
    plt.grid('on')
    ax.plot(_x,_y, 'b', label='$u(x), \ N = 1000$')
    plt.hold('on')
    ax.plot(_xN10, _numN10, 'r', linestyle='--', label='$v(x), \ N = 10$')
    ax.plot(_xN100, _numN100, 'c', linestyle='--', label='$v(x), \ N = 100$')
    ax.plot(_x, _numN1000, 'g', linestyle='--', label='$v(x), \ N = 1000$')
    ax.legend(loc='best')

    plt.show()

read()
read2()
read3()
read4()
plot()
