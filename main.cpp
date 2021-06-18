//
// Created by Daniil Kolesnik on 18/05/2021.
//all rights and lefts reserved

#include <iostream>
#include "my_vector.h"
#include<string>
#include <algorithm>


//1) at +
//2) [] +
//3) front +
//4) back +
//5) data +
//6) begin //implemented in insert and erase
//7) end //implemented in insert
//8) empty +
//9) size +
//10) reserve //implemented in insert
//11) capacity +
//12) clear +
//13) insert (вставка элемента) +
//14) erase (удаление по итератору , удаление
//диапазона по итераторам) ++
//15) push_back +
//16) pop_back +
//17) resize +
//18)swap +


int main() {


    my_vector<std::string> test = my_vector<std::string>(10, "string");
    for (auto &i : test) {
        i = "value";
    }


    for (int i = 0; i < test.size(); ++i) { //[]
        std::cout << i << "th element is " << test[i] << std::endl;
    }

//    std::cout << "enter position" << std::endl; //at
//    int pos = 0;
//    std::cin >> pos;
//    std::cout << "element at " << pos << "th position is " << test.at(pos);


//    std::cout << "the front element is " << test.front() << std::endl; // front
//    std::cout << "the back element is " << test.back() << std::endl; // back
//
//    std::cout << test.data(); // data
//
//    std::cout << test.empty() << " returned '0' bc container is not empty" << std::endl; // empty
//    my_vector<int> empty_container;
//    std::cout << empty_container.empty() << " returned '1' bc container is empty" << std::endl;
//
//    std::cout << "size of container is " << test.size() << std::endl; //size
//
//    std::cout << "capacity of container is " << test.capacity() << std::endl; //capacity
//
//    test.clear(); //clear
//    std::cout << "current size is " << test.size() << std::endl;
//
//    for (int i = 0; i < test.size(); ++i) {
//        test[i] = i;
//    }
//
//    std::cout << "Enter position to insert" << std::endl; //insert
//    int position = 0;
//    std::cin >> position;
//    std::cout << "Enter value to insert" << std::endl;
//    std::string temp = "test";
//    std::cin >> temp;
//    test.insert(my_iterator(&test[position]), temp);
//    std::cout << test[position] << std::endl;
//
//    for (int l = 0; l < test.size() - 1; ++l) { //[]
//        std::cout << l << " th element is " << test[l] << std::endl;
//    }
//
//
//    std::cout << "Enter position to delete" << std::endl; //delete pos
//    int position_1 = 0;
//    std::cin >> position_1;
//    test.erase(my_iterator(&test[position_1]));
//    std::cout << test[position_1] << std::endl;
//
//    for (int i = 0; i < test.size(); ++i) {
//        std::cout << i << "th element is" << test[i] << std::endl;
//    }
//
//    std::cout << "Enter gap to delete" << std::endl; // delete gap
//    int left_edge = 0;
//    int right_edge = 0;
//    std::cin >> left_edge;
//    std::cin >> right_edge;
//    test.erase(my_iterator(&test[left_edge]), my_iterator(&test[right_edge]));
//
//    for (int i = 0; i < test.size(); ++i) {
//        std::cout << i << "th element is" << test[i] << std::endl;
//    }
//
   // std::cout << "enter value to pushback" << std::endl; //pushback
//    std::string pushback = "PLUG";
//    test.push_back(pushback);
//    for (int i = 0; i < test.size(); ++i) {
//        std::cout << i << "th element is" << test[i] << std::endl;
//    }
//
//    test.pop_back(); //popback
//    std::cout << std::endl;
//    for (int i = 0; i < test.size(); ++i) {
//        std::cout << i << "th element is" << test[i] << std::endl;
//    }
//
//    std::cout << "enter new size " << std::endl; //resize
//    int new_size = 0;
//    std::cin >> new_size;
//    test.resize_(new_size, "u");
//
//
//
//    for (int i = 0; i < test.size(); ++i) {
//        std::cout << i << "th element is" << test[i] << std::endl;
//    }
//
//    my_vector<std::string> to_swap = my_vector<std::string>(5, "o"); //swap ЭТО НЕ РАЬОТАЕТ БЯЛТЬБ КОНСТУРКТОР ЕРРОР
//    test.swap(to_swap);
//    std::cout << "test : " << std::endl;
//    for (int i = 0; i < test.size(); ++i) {
//        std::cout << i << "th element is" << test[i] << std::endl;
//    }
//    std::cout << "-------------" << std::endl;
//    std::cout << "to_swap : " << std::endl;
//    for (int i = 0; i < to_swap.size(); ++i) {
//        std::cout << i << "th element is" << to_swap[i] << std::endl;
//    }
//
//    test.clear(); //clear
//    std::cout << "current size is " << test.size() << std::endl;
//
//    for (int i = 0; i < test.size(); ++i) {
//        test[i] = i;
//    }
    return 0;
}