#ifndef _PR_QUEUE_H
#define _PR_QUEUE_H

/*
 * Some headers that may be useful.
 * The utility header is included for the
 * std::pair<X,Y> class, used below.
 */
#include <vector>
#include <list>
#include <utility>
#include <iostream>
using namespace std;
/*
 * This class implements a priority queue ADT
 * with priorities specified in ints.
 * Lower priority values precede higher values in
 * the ordering.
 * The template type E is the element type.
 * See the tests for examples.
 */
template <typename E>



class PriorityQueue {

private:

	std::vector <std::pair<int, E> > pq;
	

	int priority;



	/*
	 * You will probably want to add some data
	 * members here.
	 */

public:

	/*
	 * A constructor, if you need it.
	 */
	PriorityQueue() {}

	/*
	 * This function adds a new element "element" to the queue
	 * with priorioty "priority".
	 */

	void swap(int array[], int i, int j)
	{
		int tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}


	int sort(std::vector <std::pair<int, E> > pq)
	{

		std::vector <std::pair<int, E> > temp = pq;//Copy the value to temp

		int min_num = 0, max_num = 0; //get the index of min and max
		for (int i = 0; i < temp.size(); i++)
		{

			if (temp[i].first > temp[max_num].first) //get max index
				max_num = i;
			else if (temp[i].first < temp[min_num].first) //get min index
				min_num = i;
		}
		return min_num;
	}


	void insert(int priority, E element) {

		if (priority >=0) {
			pq.push_back(std::make_pair<int, E >(priority, element));
		}
	}

	/*
	 * Similar to insert, but takes a whole vector of new things to
	 * add.
	 */
	void insert_all(std::vector<std::pair<int, E> > new_elements) {


		for (int i = 0; i < new_elements.size(); i++)
		{

			pq.push_back(new_elements[i]);

		}



	}

	/*
	 * Takes the lowest priority value element off the queue,
	 * and returns it.
	 */
	E remove_front() {

		

		if(!pq.empty())
		{	
			E temp = pq[0].second;
			pq.erase(pq.begin());
			return temp;
		}
		
		return E();

	}

	/*
	 * Returns the lowest priority value element in the queue, but leaves
	 * it in the queue.
	 */
	E peek() {

		int i = sort(pq);

		return pq[i].second;
	}

	/*
	 * Returns a vector containing all the elements in the queue.
	 */
	std::vector<E> get_all_elements() {
		std::vector<E> v;

		for (int i = 0; i < pq.size(); i++)
		{
			v.push_back(pq[i].second);

		}

		return v;

	}

	/*
	 * Returns true if the queue contains element "element", false
	 * otherwise.
	 */
	bool contains(E element) {

		//string x = element;


		for (int i = 0; i < pq.size(); i++)
		{
			if (pq[i].second == element)
				return true;

		}

		return false;

	}

	/*
	 * Returns the priority of the element that matches
	 * "element". If there is more than one, return it returns
	 * the lowest priority value.
	 * If no element matches, return -1.
	 */
	int get_priority(E element) {

		//priority = 0;
		E e = element;

		for (int i = 0; i < pq.size(); i++)
		{
			if (pq[i].second == e)
				return pq[i].first;
		}


		return -1;

	}

	/*
	 * Returns a vector containing all the priorities.
	 * The ordering of the vector should match that of the
	 * return from get_all_elements().
	 * That is, the priority of the element
	 * get_all_elements()[i] should be get_all_prriorities()[i].
	 */
	std::vector<int> get_all_priorities() {

		std::vector<int> v;
		
		for (int i = 0; i < pq.size(); i++)
		{

			v.push_back(pq[i].first);

		}



		return v;

	}

	/*
	 * Finds the first (in priority order) element that matches
	 * "element", and changes its priority to "new_priority".
	 */
	void change_priority(E element, int new_priority) {

		
		for (int i = 0; i < pq.size(); i++)
		{

			if (pq[i].second == element)
				pq[i].first = new_priority;

		}

	}

	/*
	 * Returns the number of elements in the queue.
	 */

	int size() {


		return pq.size();

	}

	/*
	 * Returns true if the queue has no elements, false otherwise.
	 */
	bool empty() {

		if (pq.size() == 0)
		{
			return true;
		}
		return false;

	}
};

#endif
