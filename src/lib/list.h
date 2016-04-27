
#ifndef LIB_LIST_H_
#define LIB_LIST_H_

template<typename T>
struct List {
	T *data;
	List<T> *next;
};

template<typename T>
void addList(List<T> *list, T *data) {
	if (list->data == 0x0) {
		list->data = data;
		return;
	}

	List<T> *i = list;
	while (i->next != 0x0) {
		i = i->next;
	}

	List<T> *l = new List<T>;
	l->data = data;

	i->next = l;
}

template<class T>
T *getList(List<T> *list, int index) {
	List<T> *l = list;
	for (int i = 0; i < index; i++) {
		l = l->next;
	}

	return l->data;
}

#endif /* LIB_LIST_H_ */
