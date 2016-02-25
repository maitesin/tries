#!/usr/bin/env python2.7

from numpy import *
from pylab import *
from matplotlib import rc, rcParams

rc('font',**{'family':'serif','serif':['Computer Modern']})

trie = genfromtxt('../data/trie_get_keys_prefix.output')
tst = genfromtxt('../data/tst_get_keys_prefix.output')
radix = genfromtxt('../data/radix_get_keys_prefix.output')
_map = genfromtxt('../data/map_get_keys_prefix.output')
umap  = genfromtxt('../data/umap_get_keys_prefix.output')

######## TIME ########
plot(trie[:,0], trie[:,1], '-o', label='Trie')
hold(True)
plot(tst[:,0], tst[:,1], '-o', label='Ternary Search Tree')
plot(radix[:,0], radix[:,1], '-o', label='Radix Tree')
plot(_map[:,0], _map[:,1], '-o', label='STL ordered Map')
plot(umap[:,0], umap[:,1], '-o', label='STL unordered Map')

xlabel('Max length of the string')
ylabel('Time(ms)')
title('Get keys prefix')
legend(loc='best')
grid(True)
savefig('../images/get_keys_prefix/random/get_keys_prefix_time_ALL.eps')

hold(False)
plot(tst[:,0], tst[:,1], '-o', label='Ternary Search Tree')
hold(True)
plot(radix[:,0], radix[:,1], '-o', label='Radix Tree')
plot(_map[:,0], _map[:,1], '-o', label='STL ordered Map')
plot(umap[:,0], umap[:,1], '-o', label='STL unordered Map')

xlabel('Max length of the string')
ylabel('Time(ms)')
title('Get keys prefix')
legend(loc='best')
grid(True)
savefig('../images/get_keys_prefix/random/get_keys_prefix_time_TRMU.eps')

hold(False)
plot(radix[:,0], radix[:,1], '-o', label='Radix Tree')
hold(True)
plot(_map[:,0], _map[:,1], '-o', label='STL ordered Map')
plot(umap[:,0], umap[:,1], '-o', label='STL unordered Map')

xlabel('Max length of the string')
ylabel('Time(ms)')
title('Get keys prefix')
legend(loc='best')
grid(True)
savefig('../images/get_keys_prefix/random/get_keys_prefix_time_RMU.eps')


hold(False)
plot(trie[:,0], trie[:,1], '-o', label='Trie')
hold(True)
plot(tst[:,0], tst[:,1], '-o', label='Ternary Search Tree')
plot(radix[:,0], radix[:,1], '-o', label='Radix Tree')

xlabel('Max length of the string')
ylabel('Time(ms)')
title('Get keys prefix')
legend(loc='best')
grid(True)
savefig('../images/get_keys_prefix/random/get_keys_prefix_time_TTR.eps')
