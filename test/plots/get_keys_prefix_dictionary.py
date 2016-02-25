#!/usr/bin/env python2.7

import sys
from numpy import *
from pylab import *
from matplotlib import rc, rcParams


dict=sys.argv[1].split("/")[2]

trie = genfromtxt('../data/trie_get_keys_prefix_' + dict  + '.output')
tst = genfromtxt('../data/tst_get_keys_prefix_' + dict  + '.output')
radix = genfromtxt('../data/radix_get_keys_prefix_' + dict  + '.output')
_map = genfromtxt('../data/map_get_keys_prefix_' + dict  + '.output')
umap  = genfromtxt('../data/umap_get_keys_prefix_' + dict  + '.output')

data = [trie, tst, radix, _map, umap]
fig, ax = subplots()
index = arange(5)
width = 0.5

ax.bar(index,data, width, align='center')

xlabel('Data structures')
ylabel('Time(ms)')
title('Get keys prefix dictionary(' + dict + ')')
xticks(index, ('Trie', 'TST', 'Radix', 'Map', 'Umap'))
legend(loc='best')
grid(True)

savefig('../images/get_keys_prefix/dict/get_keys_prefix_' + dict  + '_time_ALL.eps')


data = [trie, tst, radix]
fig, ax = subplots()
index = arange(3)
width = 0.5

ax.bar(index,data, width, align='center')

xlabel('Data structures')
ylabel('Time(ms)')
title('Get keys prefix dictionary(' + dict + ')')
xticks(index, ('Trie', 'TST', 'Radix'))
legend(loc='best')
grid(True)

savefig('../images/get_keys_prefix/dict/get_keys_prefix_' + dict  + '_time_TTR.eps')
