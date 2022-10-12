#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()) : comp(c), heapsize(m){

	}
  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() {

	}

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

	void print() const; //personal print function for test case purposes

	// template <typename T> struct greater {
	// 	bool operator() (const T& x, const T& y) const {return x>y;}
	// };
	// template <typename T> struct less {
	// 	bool operator() (const T& x, const T& y) const {return x>y;}
	// };

private:
  /// Add whatever helper functions and data members you need below
	std::vector<T> data;
	PComparator comp;
	int heapsize;

};

// Add implementation of member functions here
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
	return this->data.size();//simply returning the size of our vector member
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
	if ( this->data.size() == 0 ) { //checking our data member size
		return true; //return true if empty
	}
	else {
		return false; //false if not empty
	}
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
		throw std::underflow_error("Empty!");
  }
	else {
		return this->data[0]; //return the first element of our data member if not empty
	}
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator> 
void Heap<T,PComparator>::pop() //replace bottom with top element
{
	//find smallest child index first, then compare current index in vector with smallest child
  if(empty()){
    throw std::underflow_error("Empty!");
  }
	else {
		// std::cout <<"Size: " << data.size() << std::endl;
		// std::cout <<"Before Swap" << std::endl << "-----------" <<std::endl;
		// std::cout << this->data[0] << std::endl<< this->data[this->data.size() - 1] << std::endl;
		// std::cout <<"End Before Swap" << std::endl << "-----------" <<std::endl;
		std::swap(this->data[0], this->data[data.size()-1]);
		// std::cout <<"Swap" << std::endl << "-----------" <<std::endl;
		// std::cout << this->data[0] << std::endl<< this->data[this->data.size() - 1] << std::endl;
		// std::cout <<"End Swap" << std::endl << "-----------" <<std::endl;
		this->data.pop_back();
		// std::cout <<"Size after pop: " << data.size() << std::endl;
		// std::cout << "First Index after pop: " << this->data[0] <<std::endl;
		if ( this->data.size() != 1 ) {
			unsigned int i = 0;
			while ( i < this->data.size()) { //look for smallest child, check if current index is greater, if not swap, if yes, leave at location
				//std::cout << "Entered in while loop" << std::endl;
				unsigned int gindex = 0; //saves which is greatest index
				int childamt = 0;
				if ( this->data.size() < (i *heapsize + 2)) { //if the size is less than, no children
					break;
				}
				if (data.size() > ((i + 1 ) * heapsize)) { //checking if current parent has all children
					childamt = heapsize;
				}
				else { //if not, find how many children
					int lastchild = data.size(); //find the last chuld of the current parent
					int leftchild = (i * heapsize) + 1; //find the veryt first child of the current parent
					childamt = lastchild - leftchild; //difference is amount of childredn with current parent
				}
				for ( int c = 1 ;  c < childamt + 1 ; ++c) {
					//std::cout << "Entered in for loop" << std::endl;
					if ( c == 1) {
						gindex = (i * heapsize) + c; 
						continue;
					}
					else {
						if ( comp(this->data[gindex], this->data[(i*heapsize)+ c]) == true ) { //first element is greater
							continue;
						}
						else { //set new greater element index 
							gindex = (i*heapsize) + c;
						}
					}
				}
				if ( comp(this->data[gindex] , this->data[i]) == true) { //checking if the greatest value in the children, is greater than current index
					// std::cout <<"-----------"  << std::endl << "Before Swap 2"<<std::endl;
					// std::cout << this->data[0] << std::endl<< this->data[this->data.size() - 1] << std::endl;
					// std::cout <<"End Before Swap 2" << std::endl << "-----------" <<std::endl;
					// std::cout << "I: " << i << std::endl;
					// std::cout << "Gindex: " << gindex << std::endl;
					std::swap(this->data[i] , this->data[gindex]);
					// std::cout <<"-----------" << std::endl <<"Swap 2" <<std::endl;
					// std::cout << this->data[0] << std::endl<< this->data[this->data.size() - 1] << std::endl;
					// std::cout <<"End Swap 2" << std::endl << "-----------" <<std::endl;
					// std::cout <<"Swap 2" << std::endl << "-----------" <<std::endl;
					// std::cout << this->data[i] << std::endl<< this->data[gindex] << std::endl;
					// std::cout <<"End Swap 2" << std::endl << "-----------" <<std::endl;
					i = gindex;
				}
				else { //if current index is not greater than child
					break;
				}
			}
		}
	}
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
	this->data.push_back(item);
	unsigned int i = this->data.size() - 1;
	while (i > 0 ) { //to find parent (i-1)/heapsize
		int ploc = (i -1)/heapsize;
		//std::cout << "Parent: " << ploc << std::endl;
		if ( comp(this->data[i], this->data[ploc]) == true) { //if comp is true, data[i] should go up
			std::swap(this->data[i], this->data[ploc]); 
			i = ploc;
		}
		else {
			break;
		}
	}
	

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::print() const {
	std::cout << "----------" << std::endl;
	for (unsigned int i = 0 ;  i < this->data.size() ; ++i ) {
		std::cout << this->data[i] << std::endl;
	}
}

#endif

