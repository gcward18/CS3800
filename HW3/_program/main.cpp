#include <iostream>
#include <queue>
#include "string.h"
#include <utility>
#include <thread>
#include <vector>
#include <chrono>
#include <fstream>
#include <mutex>

std::mutex word_count_lock;
std::mutex file_queue_lock;

void get_files(std::queue<std::string>& file_queue)
{
    std::ifstream inFile;
    std::string   word;
    // open file with the name that was passed
    inFile.open("../data/data/files.dat");

    // check to see if the file opened properly
    if(!inFile){
        std::cout << "files.dat was not able to be opened" << std::endl;
        exit(1);
    }
    else{
        while(inFile >> word){
            file_queue.push(word);
        }
    }
    inFile.close();
}

void open_file(const std::string file_name, const std::string word, int& word_count)
{
    std::ifstream inFile;
    std::string   content;

    // open file that needs to have words counted
    inFile.open("../data/data/" + file_name);

    // let user know if file was not able to be opened
    if(!inFile){
        std::cout << word << " was not able to be opened" << std::endl;
    }
    else{
        // iterate through the file to find matching words
        while(inFile>>content)
        {
            // found a match increment word count
            if(content == word){

                word_count = word_count + 1;
            }
        }
    }
}


    /**
     * Structure:
     *
     *  mapper thread -
     *      FIRST
     *          1.  lock file queue
     *          2.  remove top file
     *          3.  unlock file queue
     *      SECOND
     *          1.  Open file
     *          2.  Count number of times word appears in
     *              file
     *          3.  Close file
     *      THIRD
     *          1.  lock count queue
     *          2.  push sum onto the queue
     *          3.  unlock count queue
     *
     *  reducer thread -
     *      FIRST
     *          1.  Lock count queue
     *          2.  Remove top two elements
     *          3.  Unlock the count queue
     *      SECOND
     *          1.  Sum two elements together
     *      THIRD
     *          1.  Lock count queue
     *          2.  Push sum onto the count queue
     *          3.  Unlock count queue
     *
     *  main function -
     *          1.  prompt user for the word they wish to
     *              count
     *          2.  set up queue's
     *          3.  launch mapper threads and wait for them
     *              to finish counting
     *          4.  launch reducer threads and wait for them
     *              to finish their work
     *          5.  print the total count
     */

void map(std::queue<std::string>& file_queue, std::queue<int>& word_count, std::string word){

    int sum = 0;
    std::string top_file;

    file_queue_lock.lock();
    top_file = file_queue.front();
    file_queue.pop();
    file_queue_lock.unlock();

    open_file(top_file, word, sum);

    word_count_lock.lock();
    word_count.push(sum);
    word_count_lock.unlock();

}

void reduce(std::queue<int>& word_count, int i){

    int first   = 0;
    int second  = 0;
    int result  = 0;

    // Reducer thread first job which is in the critical section.
    // Need to get the values from the word count queue and pop the
    // the values from the queue
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    if(word_count.size() >= 0){
        // get two elements from the queue
        word_count_lock.lock();
        first = word_count.front();
        word_count.pop();
        second = word_count.front();
        word_count.pop();
        // word_count_lock.unlock();
        
        // add the values together
        result = first + second;

        
        // if (word_count.size() <= 10 && word_count.size() >= 0 ){
        //     // // push the result back on the queue
        //     word_count_lock.lock();
            word_count.push(result);
            word_count_lock.unlock();
        // }
    }
}

int main()
{
    int n = 0;

    std::queue<std::string> file_queue;
    std::queue<int> word_count;
    int size_of_file_queue = 0;
    std::vector<std::thread> mapper_threads;
    std::vector<std::thread> reducer_threads;

    int first   = 0;
    int second  = 0;

    // get the files that will be proccessed by the thread
    get_files(file_queue);

    size_of_file_queue = file_queue.size();

    for(unsigned int i = 0; i < size_of_file_queue; i++){
        mapper_threads.push_back(std::thread(map, std::ref(file_queue), std::ref(word_count),"the"));
        reducer_threads.push_back(std::thread(reduce, std::ref(word_count), i));
    }

    for(auto& map : mapper_threads)
        map.join();
    
    for(auto& reduce: reducer_threads)
        reduce.join();
    


    std::cout << "\"the\" appeared ";
    std::cout << word_count.front();
    std::cout << " times" << std::endl;

    // for(unsigned int i = 0; i < size_of_file_queue; i++){
    //     std::cout << word_count.front() << ", ";
    //     word_count.pop();    
    // }
    // std::cout << file_queue.front() << ", ";

    // std::cout << std::endl;
    return 0;
}