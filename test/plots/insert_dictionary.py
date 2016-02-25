#!/usr/bin/env python2.7

import sys
from numpy import *
from pylab import *
from matplotlib import rc, rcParams

rc('font',**{'family':'serif','serif':['Computer Modern']})

dict=sys.argv[1].split("/")[2]

trie = genfromtxt('../data/trie_insert_' + dict  + '.output')
tst = genfromtxt('../data/tst_insert_' + dict  + '.output')
radix = genfromtxt('../data/radix_insert_' + dict  + '.output')
_map = genfromtxt('../data/map_insert_' + dict  + '.output')
umap  = genfromtxt('../data/umap_insert_' + dict  + '.output')

data = [trie, tst, radix, _map, umap]
fig, ax = subplots()
index = arange(5)
width = 0.5

ax.bar(index,data, width, align='center')

xlabel('Data structures')
ylabel('Time(ms)')
title('Insert dictionary(' + dict + ')')
xticks(index, ('Trie', 'TST', 'Radix', 'Map', 'Umap'))
legend(loc='best')
grid(True)

savefig('../images/insert/dict/insert_' + dict  + '_time_ALL.eps')
