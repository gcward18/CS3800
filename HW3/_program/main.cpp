#include <iostream>
#include <queue>
#include "string.h"
#include <utility>
#include <thread>
#include <algorithm>
#include <vector>
#include <chrono>
#include <fstream>
#include <mutex>

std::mutex word_count_lock;
std::mutex file_queue_lock;
bool sum_greater_geq_2 = false;

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
        std::cout << file_name << " was not able to be opened" << std::endl;
    }
    else{
        // iterate through the file to find matching words
        while(inFile>>content)
        {
            // transform(content.begin(), content.end(), content.begin(), ::tolower);
            // found a match increment word count
            if(content == word){

                word_count = word_count + 1;
            }
        }
    }
}

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
    std::cout << file_queue.front() << ": " << sum << std::endl;
    word_count_lock.unlock();
    if(word_count.size() >= 2 ) sum_greater_geq_2 = true;

}

void reduce(std::queue<int>& word_count, int i){

    int first   = 0;
    int second  = 0;
    int result  = 0;

    // Reducer thread first job which is in the critical section.
    // Need to get the values from the word count queue and pop the
    // the values from the queue
    while(sum_greater_geq_2 == false){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    if(word_count.size() < 2)
    {

    }
    else
        while(word_count.size() >= 2){

            // get two elements from the queue
            word_count_lock.lock();
            first = word_count.front();
            word_count.pop();
            second = word_count.front();
            word_count.pop();
            word_count_lock.unlock();

            // add the values together
            result = first + second;

            
            // push the result back on the queue
            word_count_lock.lock();
            word_count.push(result);
            word_count_lock.unlock();
        }
}

int main()
{
    int n = 0;

    std::queue<std::string> file_queue;
    std::queue<int> word_count;
    int size_of_file_queue = 0;
    int num_reducers = 0;
    std::vector<std::thread> mapper_threads;
    std::vector<std::thread> reducer_threads;
    std::string input = "";
    

    int first   = 0;
    int second  = 0;
        std::cout << "Please enter a word that you'd wish to count in our collection of books: ";
        std::cin >> input;

    while(input == ""){
        std::cout << "Invalid input please try another word: ";
        std::cin >> input;
    }

    std::cout << "Please enter the number of reducers you'd like to create: ";
    std::cin >> num_reducers;

    while(num_reducers == 0 || num_reducers > 80){
        std::cout << "Invalid input please try another number: ";
        std::cin >>num_reducers;
    }


    // transform(input.begin(), input.end(), input.begin(), ::tolower);
    // get the files that will be proccessed by the thread
    get_files(file_queue);

    size_of_file_queue = file_queue.size();

    for(unsigned int i = 0; i < size_of_file_queue; i++){
        mapper_threads.push_back(std::thread(map, std::ref(file_queue), std::ref(word_count), input));
    }

    for(unsigned int i = 0; i < num_reducers; i++){
        reducer_threads.push_back(std::thread(reduce, std::ref(word_count), i));
    }

    // Mappers and Reducers are running similatiously until this point. 
    for(auto& map : mapper_threads)
        map.join();

    // Reducers are forced to end their process. 
    for(auto& reduce : reducer_threads)
        reduce.join();
    


    std::cout << "\""<< input << "\" appeared ";
    std::cout << word_count.front();
    std::cout << " times" << std::endl;

    return 0;
}
