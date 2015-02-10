#!/usr/bin/env python2.7

from numpy import *
from pylab import *
from matplotlib import rc, rcParams

rc('font',**{'family':'serif','serif':['Computer Modern']})

trie = genfromtxt('../trie.output')
tst = genfromtxt('../tst.output')
radix = genfromtxt('../radix.output')
_map = genfromtxt('../map.output')
umap  = genfromtxt('../umap.output')

plot(trie[:,0], trie[:,1], '-o', label='Trie')
hold(true)
plot(tst[:,0], tst[:,1], '-o', label='TST')
plot(radix[:,0], radix[:,1], '-o', label='Radix Tree')
plot(_map[:,0], _map[:,1], '-o', label='STL ordered Map')
plot(umap[:,0], umap[:,1], '-o', label='STL unordered Map')

xlabel('Max length of the string')
ylabel('Time(ms)')
title('Insertion test')
legend(log='best')
grid(true)
