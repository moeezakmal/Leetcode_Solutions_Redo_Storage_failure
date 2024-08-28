/*
 *	struct Iterator {
 *		// Returns true if the iteration has more elements.
 *		bool (*hasNext)();
 *
 * 		// Returns the next element in the iteration.
 *		int (*next)();
 *	};
 */


// Time: O(1) -> for all operations
// Space: O(1) -> for all operations

struct PeekingIterator {
    struct Iterator* iterator;
    bool hasPeeked;
    int peekedNum;
};

struct PeekingIterator* Constructor(struct Iterator* iter) {
    struct PeekingIterator* piter = malloc(sizeof(struct PeekingIterator));
    piter->iterator = iter;
    piter->hasPeeked = false;
    return piter;
}

int peek(struct PeekingIterator* obj) {
    
    if(obj->hasPeeked)
        return obj->peekedNum;

    obj->peekedNum = next(obj);
    obj->hasPeeked = true;
    return obj->peekedNum;
}

int next(struct PeekingIterator* obj) {
    
    if(obj->hasPeeked) {
        obj->hasPeeked = false;
        return obj->peekedNum;
    }
    return obj->iterator->next();
}

bool hasNext(struct PeekingIterator* obj) {
    
    if(obj->hasPeeked)
        return true;
    else
        return obj->iterator->hasNext();
}