/**
 Author       : Dr. Spiegel
 Date         : April 1, 2019
 File         : SortSearch.h
 Purpose      : SORTS AN ARRAY (ASCENDING ORDER) USING SELECTION SORT ALGORITHM
 */

// A couple of things that are nice to have available

// SORTS AN ARRAY (ASCENDING ORDER) USING SELECTION SORT ALGORITHM
//    USES exchange AND find_index_of_min

   // EXCHANGES TWO INTEGER VALUES
  /**
   Function name: exchange \n
   Description  : EXCHANGES TWO (element type) VALUES  \n
   Parameters   : eltType &x - first value - input \n
                  eltType &y - second value - input \n
   Return value : None \n
   */
   template <class eltType> void exchange(eltType &x,eltType &y)          
   // Arguments:
   // Both: INOUT: 
   {	eltType temp;
		temp=y; y=x; x=temp;
   }

/**
 Function name: selSort \n
 Description  : sort the array (ascending order)  \n
 Parameters   : eltType *list - the array to be sort - input \n
                int items - number of items (elements) in the array - input \n
 Return value : None \n
 */
template <class eltType> void selSort(eltType *list,int items)
// Arguments:
// list: INOUT - array to be sorted; 
// items IN: number of items to be sorted (items >= 0)

// Sorts the data in array items (list[0] through list[items-1]).
// Pre:  list is defined and items <= declared size of actual argument array.
// Post: The values in list[0] through list[items-1] are in increasing order.
{
   // Local data ...
   int idxMax;  // subscript of each smallest item located by find_index_of_min

   for (int spot = items-1; spot > 0; spot--)
   {
      // Invariant: The elements in list[spot+1] through list[items-1] are in their
      //    proper place and spot > 0.

      // Find index of largest unsorted element 
      idxMax = spot;
      for (int idx = 0 ; idx < spot ; idx++)
		if (list[idx] > list[idxMax])
			idxMax = idx;

      // Exchange items at position idxMax and spot if different
      if (spot != idxMax)
		exchange (list[idxMax], list[spot]);
   }  // end for

}  // end sel_sort


// Templated Search function
/**
 Function name: orderedSearch \n
 Description  : search value in the array  \n
 Parameters   : eltType *list - the array being searched into - input \n
                int items - number of items (elements) in the array - input \n
                eltType key - the value being searched - input \n
 Return value : int - return the index if found, otherwise -1 \n
 */
template <class eltType> 
		int orderedSearch(eltType *list,int items,eltType key)
{
 int idx;
 for (int idx = 0;idx < items && list[ idx ] < key; idx++);
 if (idx == items || list[ idx ] > key) return(-1);
 return(idx);
}

