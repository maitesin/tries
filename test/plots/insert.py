#!/usr/bin/env python2.7

from numpy import *
from pylab import *
from matplotlib import rc, rcParams

rc('font',**{'family':'serif','serif':['Computer Modern']})

trie = genfromtxt('../data/trie_insert.output')
tst = genfromtxt('../data/tst_insert.output')
radix = genfromtxt('../data/radix_insert.output')
_map = genfromtxt('../data/map_insert.output')
umap  = genfromtxt('../data/umap_insert.output')

######## TIME ########
plot(trie[:,0], trie[:,1], '-o', label='Trie')
hold(True)
plot(tst[:,0], tst[:,1], '-o', label='Ternary Search Tree')
plot(radix[:,0], radix[:,1], '-o', label='Radix Tree')
plot(_map[:,0], _map[:,1], '-o', label='STL ordered Map')
plot(umap[:,0], umap[:,1], '-o', label='STL unordered Map')

xlabel('Max length of the string')
ylabel('Time(ms)')
title('Insert test')
legend(loc='best')
grid(True)
savefig('../images/insert/random/insert_time_ALL.eps')

hold(False)
plot(tst[:,0], tst[:,1], '-o', label='Ternary Search Tree')
hold(True)
plot(radix[:,0], radix[:,1], '-o', label='Radix Tree')
plot(_map[:,0], _map[:,1], '-o', label='STL ordered Map')
plot(umap[:,0], umap[:,1], '-o', label='STL unordered Map')

xlabel('Max length of the string')
ylabel('Time(ms)')
title('Insert test')
legend(loc='best')
grid(True)
savefig('../images/insert/random/insert_time_TRMU.eps')

hold(False)
plot(radix[:,0], radix[:,1], '-o', label='Radix Tree')
hold(True)
plot(_map[:,0], _map[:,1], '-o', label='STL ordered Map')
plot(umap[:,0], umap[:,1], '-o', label='STL unordered Map')

xlabel('Max length of the string')
ylabel('Time(ms)')
title('Insert test')
legend(loc='best')
grid(True)
savefig('../images/insert/random/insert_time_RMU.eps')

hold(False)
plot(trie[:,0], trie[:,1], '-o', label='Trie')
hold(True)
plot(tst[:,0], tst[:,1], '-o', label='Ternary Search Tree')
plot(radix[:,0], radix[:,1], '-o', label='Radix Tree')

xlabel('Max length of the string')
ylabel('Time(ms)')
title('Insert test')
legend(loc='best')
grid(True)
savefig('../images/insert/random/insert_time_TTR.eps')

###### MEMORY ######
hold(False)
plot(trie[:,0], trie[:,2], '-o', label='Trie')
hold(True)
plot(tst[:,0], tst[:,2], '-o', label='Ternary Search Tree')
plot(radix[:,0], radix[:,2], '-o', label='Radix Tree')
plot(_map[:,0], _map[:,2], '-o', label='STL ordered Map')
plot(umap[:,0], umap[:,2], '-o', label='STL unordered Map')

xlabel('Max length of the string')
ylabel('Size in memory(Kb)')
title('Memory test')
legend(loc='best')
grid(True)
savefig('../images/insert/random/memory.eps')

