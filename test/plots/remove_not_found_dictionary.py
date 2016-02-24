#!/usr/bin/env python2.7

import sys
from numpy import *
from pylab import *
from matplotlib import rc, rcParams

rc('font',**{'family':'serif','serif':['Computer Modern']})

dict=sys.argv[1].split("/")[2]

trie = genfromtxt('../data/trie_remove_not_found_' + dict  + '.output')
tst = genfromtxt('../data/tst_remove_not_found_' + dict  + '.output')
radix = genfromtxt('../data/radix_remove_not_found_' + dict  + '.output')
_map = genfromtxt('../data/map_remove_not_found_' + dict  + '.output')
umap  = genfromtxt('../data/umap_remove_not_found_' + dict  + '.output')

######## TIME ########
plot(trie[:,0], trie[:,1], '-o', label='Trie')
hold(True)
plot(tst[:,0], tst[:,1], '-o', label='Ternary Search Tree')
plot(radix[:,0], radix[:,1], '-o', label='Radix Tree')
plot(_map[:,0], _map[:,1], '-o', label='STL ordered Map')
plot(umap[:,0], umap[:,1], '-o', label='STL unordered Map')

xlabel('Max length of the string')
ylabel('Time(ms)')
title('Remove test (not found)')
legend(loc='best')
grid(True)
savefig('remove_not_found_' + dict  + '_time_ALL.eps')

hold(False)
plot(tst[:,0], tst[:,1], '-o', label='Ternary Search Tree')
hold(True)
plot(radix[:,0], radix[:,1], '-o', label='Radix Tree')
plot(_map[:,0], _map[:,1], '-o', label='STL ordered Map')
plot(umap[:,0], umap[:,1], '-o', label='STL unordered Map')

xlabel('Max length of the string')
ylabel('Time(ms)')
title('Remove test (not found)')
legend(loc='best')
grid(True)
savefig('remove_not_found_' + dict  + '_time_TRMU.eps')

hold(False)
plot(radix[:,0], radix[:,1], '-o', label='Radix Tree')
hold(True)
plot(_map[:,0], _map[:,1], '-o', label='STL ordered Map')
plot(umap[:,0], umap[:,1], '-o', label='STL unordered Map')

xlabel('Max length of the string')
ylabel('Time(ms)')
title('Remove test (not found)')
legend(loc='best')
grid(True)
savefig('remove_not_found_' + dict  + '_time_RMU.eps')
