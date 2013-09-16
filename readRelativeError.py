import matplotlib.pyplot as plt
import numpy as np


def read():
    '''
    Reads the data from given datafile.
    '''
    infile = open("../build-Project-1-Desktop_Qt_5_1_0_clang_64bit-Debug/errorData.txt",'r')

    global _x; _x = []
    global _y; _y = []
#    global _z; _z = []

    for line in infile:
        columns = line.split()
        _x.append(float(columns[0]))
        _y.append(float(columns[1]))
#        _z.append(float(columns[2]))

    infile.close()


def plot():
    '''
    Plots data.
    '''
    fig = plt.figure()
    ax = fig.add_subplot(111)
    fig.suptitle('The max relative error as function of $N$')
    ax.set_xlabel('$log_{10}(N)$', fontsize='16')
    ax.set_ylabel('Max relative error, $\epsilon_{max}$')
    plt.grid('on')
    ax.plot(_x,_y)

    plt.show()

read()
plot()
