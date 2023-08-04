"""
==============================================================================
Exeriment Set
------------------------------------------------------------------------------


Analyse runtime characterists : CPP vs Python. 


: 03 August 2023
: Zach Wolpe
: zach.wolpe@medibio.com.au
==============================================================================
"""

from DSA.DataStructures.DoublyLinkedLists.DoublyLinkedList import *
from DSA.DataStructures.StacksQueues.StacksAndQueues import *
from DSA.DataStructures.LinkedLists.LinkedList import *
from DSA.DataStructures.BinarySearchTree.bst import *
from DSA.DataStructures.HashTable.HashTable import *
from DSA.DataStructures.Graphs.graphs import *

from DSA.Algorithms.python.selection_sort import *
from DSA.Algorithms.python.insertion_sort import *
from DSA.Algorithms.python.tree_traverse import *
from DSA.Algorithms.python.bubble_sort import *
from DSA.Algorithms.python.merge_sort import *
from DSA.Algorithms.python.quick_sort import *


from Profiler.pyModules.profiler        import CPUProfiler, MemoryProfiler
from Profiler.pyModules.dependencies    import *

from helpers import *
import pandas as pd
import numpy as np
import random
import psutil
import time
import sys
import os


def sorting_algorithms(array, *args, **kwargs):

    # standard sorting algorithms
    selection_sort(array)
    insertion_sort(array)
    bubble_sort(array)
    merge_sort(array)
    # quickSort.quick_sort(array)

    # build tree
    tree = TreeTraversal()
    [tree.insert(i) for i in array]

    # # tree traverse
    tree.BFS()
    tree.DFS('preorder')
    tree.DFS('inorder')
    tree.DFS('postorder')
    return True


def datastructures(array, *args, **kwargs):
    
    # # graphs
    my_graph = Graph()
    print('_dir_: ', dir(my_graph))
    for _ in range(len(array)):
        my_graph.addVertex('A')
        my_graph.addEdge('A','B')
        my_graph.removeVertex('A')

    # Binary Search Tree
    my_tree = BinarySearchTree()
    [my_tree.insert(a) for a in array]

    # Hash Table
    my_hash = HashTable()
    [my_hash.set_item(str(a), a) for a in array]

    # Queue
    my_queue = Queue(33)
    [my_queue.enqueue(a) for a in array]
    
    return True


@CPUProfiler.profile 
@MemoryProfiler.profile
def core_algorithms(array, *args, **kwargs):
    # core algorithms
    datastructures(array)
    sorting_algorithms(array)
    return True


from datetime import datetime, timedelta


class basic_timer:
    def __init__(self, *args, **kwargs) -> None:
        self.start_time = time.time()
        self.end_time   = None

    def __enter__(self, *args, **kwargs):
        return self

    def __exit__(self, *args, **kwargs):
        self.end_time = time.time()
        # convert to seconds
        self.time_delta = self.end_time - self.start_time
        self.delta      = timedelta(seconds=self.time_delta)

        print('time taken: ', self.delta)
        return self
    
    

def write_to_file(_dict, path):
    with open(f'{path}/basetimes.pkl', 'wb') as f:
        pickle.dump(_dict, f)




if __name__ == '__main__':
    clear_directory()

    # Run experiments
    store_loc  = 'results'
    base_times = {}

    for _, size in enumerate([10, 100, 1000, 10000, 100000]):
        bt = basic_timer()
        with bt:
            print('launching size=', size)
            array = np.random.sample(size)*100 // 1
            result, mem_profile = core_algorithms(array, sav_loc=f'{store_loc}/n_combinations-{size}')
            print('\nresult:    ', result)
            print('mem_profile: ', mem_profile)
            print(array)
        base_times[size] = bt.delta

    print('base_times: ', base_times)
    write_to_file(base_times,store_loc)
        

