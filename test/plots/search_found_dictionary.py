#!/usr/bin/env python2.7

import sys
from numpy import *
from pylab import *
from matplotlib import rc, rcParams


dict=sys.argv[1].split("/")[2]

trie = genfromtxt('../data/trie_search_found_' + dict  + '.output')
tst = genfromtxt('../data/tst_search_found_' + dict  + '.output')
radix = genfromtxt('../data/radix_search_found_' + dict  + '.output')
_map = genfromtxt('../data/map_search_found_' + dict  + '.output')
umap  = genfromtxt('../data/umap_search_found_' + dict  + '.output')

data = [trie, tst, radix, _map, umap]
fig, ax = subplots()
index = arange(5)
width = 0.5

ax.bar(index,data, width, align='center')

xlabel('Data structures')
ylabel('Time(ms)')
title('Search found dictionary(' + dict + ')')
xticks(index, ('Trie', 'TST', 'Radix', 'Map', 'Umap'))
legend(loc='best')
grid(True)

savefig('../images/search_found/dict/search_found_' + dict  + '_time_ALL.eps')

data = [trie, tst, radix]
fig, ax = subplots()
index = arange(3)
width = 0.5

ax.bar(index,data, width, align='center')

xlabel('Data structures')
ylabel('Time(ms)')
title('Search found dictionary(' + dict + ')')
xticks(index, ('Trie', 'TST', 'Radix'))
legend(loc='best')
grid(True)

savefig('../images/search_found/dict/search_found_' + dict  + '_time_TTR.eps')
