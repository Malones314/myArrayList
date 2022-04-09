#include<iostream>
using namespace std;

const int maxSize = 20;
template <class Element> 
class mylist {
public:
	Element data [maxSize];
	int length;
} ;
typedef class mylist<int> myListInt;
typedef myListInt myList;

//初始化
void initList ( myList& L ) {
	L.length = 0;
	for ( auto& i : L.data )
		i = 0;
}

//删除
template< class Element>
bool deleteNumber ( myList& L, Element number ) {
	int indexL = 0;
	for ( indexL = 0; indexL < L.length; indexL++ ) {
		if ( L.data [indexL] == number )
			break;
	}
	if ( indexL == L.length ) {
		return false;
	} else {
		for ( ; indexL < L.length - 1; indexL++ ) {
			L.data [indexL] = L.data [indexL + 1];
		}
		L.length--;
	}
	return true;
}

bool deleteNumber ( myList& L, int deleteIndex ) {
	if ( deleteIndex < 0 || deleteIndex > L.length ) {
		return false;
	} else {
		for ( int i = deleteIndex; i < L.length - 1; i++ ) {
			L.data [i] = L.data [i + 1];
		}
		L.length--;
	}
	return true;
}

//判断List是否为空
bool emptyList ( myList& L ) {
	return L.length == 0;
}

//插入
template< class Element>
bool insertList ( myList& L, Element dataElement, int insertIndex ) {
	if ( insertIndex > L.length || insertIndex < 0 )
		return false;
	else {
		for ( int i = L.length + 1; i > insertIndex; i-- ) {
			L.data [i] = L.data [i - 1];
		}
		L.data [insertIndex] = dataElement;
		L.length++;
	}
	return true;
}

int main ( ) {
	myList listi;
	initList ( listi );
	for ( int i = 0; i < 10; i++ ) {
		cout << insertList ( listi, i, i ) << endl;
	}
	for ( auto i : listi.data )
		cout << i << endl;
	return 0;
}
