/*
==============================================================================
Exeriment Set
------------------------------------------------------------------------------


Analyse runtime characterists : CPP vs Python. 


: 03 August 2023
: Zach Wolpe
: zach.wolpe@medibio.com.au
==============================================================================
*/


#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <array>
#include <fstream>

#include <chrono>
#include <fstream>
#include <map>
#include <cstdlib> / for exit function

#include "DSA/Algorithms/cpp/bubble_sort.cpp"
#include "DSA/Algorithms/cpp/selection_sort.cpp"
#include "DSA/Algorithms/cpp/quick_sort.cpp"
#include "DSA/Algorithms/cpp/merge_sort.cpp"
#include "DSA/Algorithms/cpp/insertion_sort.cpp"
#include "DSA/Algorithms/cpp/tree_traverse.cpp"
#include "Profiler/cppModules/profiler.cpp"



void tree_sorter_inorder(int array[], int size) {
    BinarySearchTree* BST = new BinarySearchTree();
    for (int i=0; i<size; i++) {
        BST->insert(array[i]);
    };
    BST->DFS("inorder");
};

void tree_sorter_postorder(int array[], int size) {
    BinarySearchTree* BST = new BinarySearchTree();
    for (int i=0; i<size; i++) {
        BST->insert(array[i]);
    };
    BST->DFS("postorder");
};

void tree_sorter_preorder(int array[], int size) {
    BinarySearchTree* BST = new BinarySearchTree();
    for (int i=0; i<size; i++) {
        BST->insert(array[i]);
    };
    BST->DFS("preorder");
};

void merge_sorter(int array[], int size) {
    int leftIndex   = 0;
    int rightIndex  = size - 1;
    mergeSort(array, leftIndex, rightIndex);
};

void quick_sorter(int array[], int size) {
    int leftIndex   = 0;
    int rightIndex  = size - 1;
    quickSort(array, leftIndex, rightIndex);
};

void bubbleSort(int array[], int size);
void selectionSort(int array[], int size);
void insertionSort(int array[], int size);


bool sorting_algorithms(int arr_size, void (*algorithm)(int array[], int size)) {
    PROFILE_FUNCTION();
    int myArray[arr_size];
    for(int i=0;i<arr_size;i++)
        myArray[i]=rand()%100;
    int size = sizeof(myArray) / sizeof(myArray[0]);
    algorithm(myArray, size);
    // PROFILE_FUNCTION();
    return true;
    // Instrumentor::Get().EndSession();
    // For adhoc debugging.
    // std::cout << " myArray : " << myArray << ": ";
    // for(int i=0;i<arr_size;i++)
    //     std::cout << myArray[i] << " ";
    // std::cout << std::endl;
};





class basic_timer {
    public:
        std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
        std::chrono::time_point<std::chrono::high_resolution_clock> end_time;
        bool running;

        void start() {
            if (!running) {
                start_time = std::chrono::high_resolution_clock::now();
                end_time   = start_time;
                running    = true;
            }
        };

        void stop() {
            if (running) {
                end_time = std::chrono::high_resolution_clock::now();
                running  = false;
            }
        };

        void restart() {
            start_time = std::chrono::high_resolution_clock::now();
            running = false;
        }

        double elapsed() {
            if (running) {
                return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start_time).count();
            } else {
                return std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
            }
        };
};





class write_to_file {

public:
    std::ofstream outdata;
    void open_file(std::string loc = "runtime-cpp.txt") {
        this->outdata.open(loc);
        if (!this->outdata) {
            std::cerr << "Error: file could not be opened" << std::endl;
            exit(1);
        }
    };
    void close_file() {
        this->outdata.close();
    };
    void write_data(int key, int value) {
        this->outdata << "{" << key << ", " << value << "}, " << std::endl;
    };
};



void runtime() {
    PROFILE_FUNCTION();
// write to file
    write_to_file file;
    file.open_file();
    basic_timer timer;
    // run experiments
    for (int x=10; x<=100000; x*=10) {
        timer.start();
        std::cout << "x : " << x << std::endl;
        sorting_algorithms(x, &bubbleSort);
        sorting_algorithms(x, &selectionSort);
        sorting_algorithms(x, &insertionSort);
        sorting_algorithms(x, &merge_sorter);
        sorting_algorithms(x, &quick_sorter);
        sorting_algorithms(x, &tree_sorter_preorder);
        sorting_algorithms(x, &tree_sorter_inorder);
        sorting_algorithms(x, &tree_sorter_postorder);
        timer.stop();
        std::cout << "x : " << x << std::endl;
        std::cout << "time : " << timer.elapsed() << std::endl;
        file.write_data(x, timer.elapsed());
    }
};


void runtime_profiler() {
    PROFILE_FUNCTION();
    std::cout << ">> Running programWrapper..." << std::endl;
    Instrumentor::Get().LaunchSession("myprofiler", "profiler-v2x.json"); 
    runtime();
    Instrumentor::Get().EndSession();

};


int main() {
    runtime_profiler();
    return 0;
};


