//
// Created by Daniil Kolesnik on 18/05/2021.
//all rights and lefts reserved

#ifndef INC_5THLABONLY_MY_VECTOR_H
#define INC_5THLABONLY_MY_VECTOR_H

/*ЗДЕСТ ДОЛЖНЫ БЫТЬ
 * !!!!
1) at
2) []
3) front
4) back
5) data
6) begin
7) end
8) empty
9) size
10) reserve
11) capacity
12) clear
13) insert (вставка элемента)
14) erase (удаление по итератору, удаление
диапазона по итераторам)
15) push_back
16) pop_back
17) resize
18)swap ----- !!!!!!!

 ПЛЮС

 1) == +
2) != +
3) -> +
4) * +
5) ++ (правосторонний) +
6) ++ (левосторонний) +
7) -- (правосторонний) + 8) -- (левосторонний) +
9) [] +
10) + (сдвиг + итератор)  +
11) + (итератор + сдвиг)
12) - (итератор – сдвиг) +
13) - (итератор – итератор) +
14) += +
15) -= +
16) > +
17) < +
18) >= +
19) <= +
 */


template<typename T>
class my_iterator {

public:
    using pointer = T*;
    using reference = T&;
    using value_type = T;
    using difference_type = int;
    using iterator_category = std::random_access_iterator_tag;

    pointer pos = nullptr;

    explicit my_iterator(pointer ptr) : pos(ptr) {}; // теперь итератор смотрит на ptr.  explicit in order to prevent implicit cast from pointer to my_iterator

    bool operator==(const my_iterator &other) const  { //PASS
        return pos == other.pos; // if slots are equal return 1
    }

    bool operator!=(const my_iterator &other) const  { //PASS
        return pos != other.pos; // if slots are equal return 0
    }

    pointer operator->()  { //PASS
        return pos; // get address of a pointer
    }

    reference operator*() const  { //PASS
        return *pos; //return int position
    }

    my_iterator operator+(const difference_type &diff) const  { //diff + iterator /10 //PASS
        return my_iterator(pos + diff); // return iterator with position pos + diff
    }

    friend inline my_iterator operator+(difference_type const& diff,my_iterator const& it){

    } // 11 //iterator + diff

    my_iterator operator-(const difference_type &diff) const  { //iterator - diff /12 //PASS
        return my_iterator(pos - diff); // return iterator with position pos - diff
    }

    difference_type operator-(const my_iterator &other) const { // iterator - iterator 13 //PASS
        return std::distance(other.pos, pos);
    } //--------

    bool operator>(const my_iterator &other) const  {  //PASS
        return pos > other.pos; // look at the furthest from the origin and return 1 if the furthest 0 if other is the furthest
    }

    bool operator<(const my_iterator &other) const  { //PASS
        return pos < other.pos; // look at the furthest from the origin and return 0 if the furthest 1 if other is the furthest
    }
//-----------
    bool operator>=(const my_iterator &other) const  { //PASS
        return pos >= other.pos; // look at the furthest from the origin and return 1 if the furthest 0 if other is the furthest
    } //also returns 1 if both point at the same element

    bool operator<=(const my_iterator &other) const  { //PASS
        return pos <= other.pos; // look at the furthest from the origin and return 0 if the furthest 1 if the other is the furthest
    }// also returns 1 if both point at the same element

    reference operator[](u_int index) const  { //PASS
        return pos[index]; // returns a reference to an element pointed by index . is pos an array? yes
    }



    my_iterator &operator++()  { //right side //PASS
        ++pos;
        return *this;
    }

    my_iterator operator++(int)  { //left side //PASS
        my_iterator tmp = *this;
        ++pos;
        return *this;
    }

    my_iterator &operator--()  {//right side //PASS
        --pos;
        return *this;
    }

    my_iterator operator--(int) noexcept  { //left side //PASS
        my_iterator tmp = *this;
        --pos;
        return tmp;
    }


    my_iterator &operator+=(const difference_type &diff)  { // modify pos (+=) //PASS
        pos += diff;
        return *this;
    }

    my_iterator &operator-=(const difference_type &diff)  { // modify pos (-=) //PASS
        pos -= diff;
        return *this;
    }


};

template<typename T>
class my_vector {
public:


    my_vector():capacity_(0),number_of_elements(0),data_(nullptr)  { //def constructor via  initialization list instead of direct

    }

    explicit my_vector(u_int n, const T &value )  { //prevent implicit cast // constructor with args
        capacity_ = n + 1;
        number_of_elements = n;
        data_ = new T[capacity_];
        for (u_int i = 0; i < number_of_elements; ++i) {
            data_[i] = value;
        }
    }

    my_vector(const my_vector &other)  { // copy constructor CHECK IF WORKS

        delete[] data_;
        capacity_ = other.capacity_;
        number_of_elements = other.number_of_elements;
        T *tmp = new T[capacity_];
        for (u_int i = 0; i < number_of_elements; ++i) {
            tmp[i] = other.data_[i];
        }
        data_ = tmp;
    }

    my_vector &operator=(const my_vector &other)  {  // overloading "equalize" operation for 2 vectors
        if (this == &other) std::cout << "youre trying to equalize same objects" << std::endl;
        if (this != &other){ // self initialization check

            delete[] data_;
            capacity_ = other.capacity_;
            number_of_elements = other.number_of_elements;
            T *tmp = new T[capacity_];
            for (u_int i = 0; i < number_of_elements; ++i) {
                tmp[i] = other.data_[i];
            }
            data_ = tmp;

        }

        return *this;
    }

    ~my_vector()  { // according to RAII if weve taken memory we have to give it back;
        delete[] data_;
    }


    T &at(u_int pos) { // returns data by index //PASS
        return data_[pos];
    }

    void clear(){ //PASS //clears entire array and invalidates pointers
        delete [] this->data_;
        capacity_ = 0;
        number_of_elements = 0;
        data_ = nullptr;
    };

    T &operator[](u_int pos)   {// return element by index and reference //PASS
        return data_[pos];
    }



    T &front()  { //PASS
        return data_[0]; // returns the first element
    }

    const T &front() const  { //PASS
        return data_[0]; // returns the first element in a constant way
    }

    T &back() noexcept { //PASS
        return data_[number_of_elements - 1]; // returns the last element
    }

    const T &back() const  { //PASS
        return data_[number_of_elements - 1]; // returns the last element in a constant way
    }

    [[nodiscard]] u_int size() const  { // return number of elements //PASS
        return number_of_elements;
    }

    [[nodiscard]] u_int capacity() const  { // return capacity //PASS
        return capacity_;
    }

    T *data()  { // return data //PASS
        return data_;
    }

    const T *data() const  { //return data in a constant way //PASS
        return data_;
    }

    my_iterator<T> begin()  { // returns iterator pointed at the first element //PASS
        return my_iterator(&data_[0]);
    }

    my_iterator<T> begin() const  { // returns iterator pointed at the first element in a constant way //PASS
        return my_iterator(&data_[0]);
    }

    my_iterator<T> end()  { //PASS
        return my_iterator(&data_[number_of_elements]); // returns iterator pointed at the first element
    }

    my_iterator<T> end() const { //PASS
        return my_iterator(&data_[number_of_elements]); // returns iterator pointed at the first element in a constant way
    }

    [[nodiscard]] bool empty() const  { // if the container is empty returns 1 //PASS
        return number_of_elements == 0;
    }

    void swap(my_vector &other)  { // swapping two vectors with each other //It throws an error if the vector is not of the same type.

        auto tmp = std::move(*this); // why type auto
        *this = std::move(other);
        other = std::move(tmp);

    }

    void pop_back() { //PASS
        if (number_of_elements == 1) {
            delete[] data_;
            capacity_ = 1;
            number_of_elements = 0;
            data_ = new T[1];
        } else {
            --number_of_elements;
        }
    }

    void push_back(const T &value) { //PASS
        if (number_of_elements + 1 == capacity_) reserve(capacity_ * factor);
        data_[number_of_elements] = value;
        ++number_of_elements;
    }

    void reserve(u_int new_cap) { //PASS
        if (capacity_ >= new_cap) return void();
        capacity_ = new_cap;

        T *tmp = new T[capacity_];
        for (u_int i = 0; i < number_of_elements; ++i) {
            tmp[i] = data_[i];
        }

        delete[] data_;
        data_ = tmp;
    }


    void resize_(u_int count, const T &value ) { //PASS
        u_int max_right = 0;
        u_int threshold_l = 0; //minleft
        if (count == number_of_elements) return void();
        if (number_of_elements > count){
            number_of_elements = count;
            capacity_ = count + 1;
            for (u_int i = 0; i < count; ++i){
                data_[i] = value;
            }
            return void();
        }

        if (number_of_elements < count){
            u_int old_size = this->number_of_elements;
            T *tmp = new T[count + 1];
            u_int new_size = count;
            number_of_elements = count;
            capacity_ = count + 1;
            threshold_l = count;

            for (u_int i = 0; i < old_size; ++i){
                tmp[i] = data_[i];
            }
            for (u_int i = old_size; i < count; ++i) {
                tmp[i] = "NULL";
            }
            delete[] data_;
            data_ = tmp;
            capacity_ = new_size + 1;
            number_of_elements = new_size;
            return void();
        }

    }





    my_iterator<T> insert(const my_iterator<T> pos, T value) { //PASS
        u_int n = number_of_elements + 1;
        T *tmp = new T[n];
        u_int i = 0;
        auto it = begin();
        /*
         * The auto keyword is a simple way to declare a variable that has a complicated type.
         */
        while (it != pos) tmp[i++] = *(it++);
        auto ret = it;
        tmp[i++] = std::move(value);
        while (it != end()) tmp[i++] = *(it++);

        if (n >= capacity_) reserve(n * factor);
        std::copy(tmp, tmp + n, begin());
        number_of_elements = n;

        return ret;
    }

    my_iterator<T> erase(const my_iterator<T> pos) { //PASS
        u_int n = number_of_elements - 1;
        T* tmp = new T[n];

        u_int i = 0;
        auto it = begin();
        while (it != pos) tmp[i++] = *(it++);
        auto ret = it++;
        while (it != end()) tmp[i++] = *(it++);

        std::copy(tmp, tmp + n, begin());
        number_of_elements = n;

        return ret;
    }


    my_iterator<T> erase(const my_iterator<T> first, const my_iterator<T> last) { //PASS
        u_int d = distance(first, last);
        u_int n = number_of_elements - d;
        T *tmp = new T[n];

        u_int i = 0;
        auto it = begin();
        while (it != first) tmp[i++] = *(it++);
        auto ret = it;

        it += d;
        while (it != end()) tmp[i++] = *(it++);

        std::copy(tmp, tmp + n, begin());
        number_of_elements = n;

        return ret;
    }

private:



    u_int capacity_ = 0;
    u_int number_of_elements = 0;
    T *data_ = nullptr;

    u_int factor = 2;
};


#endif //INC_5THLABONLY_MY_VECTOR_H
