#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

/*struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif*/

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void) {

    LinkedList* this = NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList)); // creo el espacio de memoria de la linked list
    if(this != NULL) { // si no es null
    	this->pFirstNode = NULL; // asigno el primer nodo de la linked a null
    	this->size = 0; // con un tamaño de 0 porque no tiene ningun nodo
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this) {

    int returnAux = -1;
    if(this != NULL) { //verifico que sea distinto de null para devolver -1 en caso que lo sea
    	returnAux = this->size; // devuelvo el size de la linked list
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex) {

	Node* pNode = NULL;
	int len;
	len = ll_len(this); // guardo el len en una variable

	if(this != NULL && nodeIndex >= 0 && nodeIndex < len) { // para entrar me fijo que la LL no sea null que el index sea >= 0 bla bla

			pNode = this->pFirstNode;

			if(pNode != NULL) {

				for(int i = 0; i < nodeIndex; i++) {

				pNode = pNode->pNextNode;

				}
			}
	}

	return pNode;

}
/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement) {

	int returnAux = -1;
	Node* pNode = NULL;
	Node* aux_pNode = NULL;
	int len;
	len = ll_len(this); // guardo el len en una variable

	if(this != NULL && nodeIndex >= 0 && nodeIndex <= len) {// para entrar me fijo que la LL no sea null que el index sea >= 0 bla bla

		pNode = (Node*)malloc(sizeof(Node));

		if(pNode != NULL) {

			pNode->pElement = pElement; // asigno el elemento al nodo
			pNode->pNextNode = NULL;// apunto es

			if(nodeIndex == 0) {

				pNode->pNextNode = this->pFirstNode ;
				this->pFirstNode = pNode;

			} else { // indice distinto de 0

				aux_pNode = getNode(this, nodeIndex - 1);
				pNode->pNextNode = aux_pNode->pNextNode;
				aux_pNode->pNextNode = pNode;

			}

			this->size = this->size + 1;
			returnAux = 0;

		}

	}
	return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement) {

    int returnAux = -1;
    int len;
    len = ll_len(this);

    if(this != NULL && addNode(this, len, pElement) == 0)  {
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */

void* ll_get(LinkedList* this, int index) {

	void* returnAux = NULL;
	Node* pNode = NULL;

	if(this!= NULL) {
		pNode = getNode(this, index);

		if(pNode != NULL) {

			returnAux = pNode->pElement;
		}
	}

	return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement) {

    int returnAux = -1;
    int len;
    len = ll_len(this);
    Node* pNode = NULL;

    if(this != NULL && index >= 0 && index <= len) {

    	pNode = getNode(this, index);
    	if(pNode != NULL) {

    		pNode->pElement = pElement;
    		returnAux = 0;
    	}

    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index) {

    int returnAux = -1;
    int len;
    len = ll_len(this);
    Node* pNode = NULL; // nodo que voy a borrar
    Node* pNodeAux = NULL; // nodo que tengo que enlazar nuevamente


    	if(this != NULL && index >= 0 && index <= len) {

    		pNode = getNode(this, index); //busco el nodo que quiero borrar

    		if(index == 0 && pNode != NULL) {

    			this->pFirstNode = pNode->pNextNode;  // si el indice es 0, tengo que enlazar la ll con el siguiente dato
    			free(pNode);// libero el espacio que ocupa pNode
    			pNode = NULL;//lo apunto a null
    			this->size--;// importantisimo, la lista tiene un numero menos asi que la decremento
    			returnAux = 0;
    		} else {

    			pNodeAux = getNode(this, (index - 1));//busco el nodo anterior para luego enlazarlo
				if(pNode != NULL && pNodeAux != NULL) {

					pNodeAux->pNextNode = pNode->pNextNode;
					free(pNode);// libero el espacio que ocupa pNode
					pNode = NULL;//lo apunto a null
					this->size--;// importantisimo, la lista tiene un numero menos asi que la decremento
					returnAux = 0;// creo un enlace entre el nodo anterior al que quiero borrar y el proximo
				}

    		}

    	}

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this) {

    int returnAux = -1;
    int len;
    Node* pNode = NULL;
    len = ll_len(this);
    if(this != NULL) {
    	for(int i = 0; i<len; i++) {
    		pNode = getNode(this, i);
    		if(pNode != NULL) {
    			free(pNode);
    			pNode = NULL;
    			this->size--;
    			returnAux = 0;
    		}
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this) {
	int returnAux = -1;

    if(this != NULL) {
    	ll_clear(this);
    	free(this);
    	this = NULL;
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement) {

    int returnAux = -1;
    Node* pNode = NULL;
    int len;
    len = ll_len(this);

    if(this != NULL) {
    	for(int i = 0; i<len ; i++) {
    		pNode = getNode(this, i);
    		if(pNode != NULL) {
    			if(pNode->pElement == pElement) {
    				returnAux = i;
    				break;
    			}
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this) {

    int returnAux = -1;
    if(this != NULL) {
    	if(this->size == 0) {
    		returnAux = 1;

    	}else {
    			if(this->size > 0) {
    				returnAux = 0;
    			}
    		}
    	}

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement) {

    int returnAux = -1;
    int len;
    //Node* pNode = NULL;
    len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len) {
    	if(addNode(this, index, pElement) == 0) {
    		returnAux = 0;
    	}

    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index) {

    void* returnAux = NULL;
    Node* pNode = NULL;
    Node* NodoPop = NULL;
    int len;
    len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len) {

    	pNode = getNode(this, index);
    	NodoPop = getNode(this, index);

    	if(pNode != NULL) {
    		returnAux = NodoPop->pElement;
    		ll_remove(this, index);
    	}

    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement) {

    int returnAux = -1;
    int len;
    Node* pNodoAux = NULL;

    len = ll_len(this);

    if(this != NULL) {

    	returnAux = 0;

    	for(int i = 0; i<len; i++) {

    		pNodoAux = getNode(this, i);

    		if(pNodoAux != NULL) {
    			if(pElement == pNodoAux-> pElement) {
    				returnAux = 1;
    				break;
    			}
    		}
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2) {

    int returnAux = -1;
    int len_1;
    int len_2;
    int contador = 0;
    Node* pNode_1 = NULL;
    Node* pNode_2 = NULL;
    len_1 = ll_len(this);
    len_2 = ll_len(this2);
    if(this != NULL && this2 != NULL) {

    	returnAux = 0;

    	for(int i = 0; i<len_2; i++) {
    		pNode_2 = getNode(this2, i);

    		if(pNode_2 != NULL) {

    			for(int j = 0; j<len_1; j++) {

    				pNode_1 = getNode(this, j);
    				if(pNode_1 != NULL ) {
    					if(pNode_2->pElement == pNode_1-> pElement) {

    						contador++;
    					}
    				}
    			}
    		}
    	}

    	 if(contador == len_2) {

       	returnAux = 1;

    	 }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to) {

    LinkedList* cloneArray = NULL;
    void* pElement = NULL;
    int len;
    len = ll_len(this);


    if(this != NULL &&  from >= 0 && from < len && to > from && to <= len) {

    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL) {

    		for(int i = from; i< to; i++) {

    				pElement = ll_get(this, i);

    				ll_add(cloneArray, pElement);

    			}

    		}
    	}

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this) {

    LinkedList* cloneArray = NULL;
    void* pElement = NULL;
    int len;
    len = ll_len(this);

    if(this != NULL) {

    	cloneArray = ll_subList(this, 0, len);
    	 pElement = ll_get(this, len);
    	 ll_add(cloneArray, pElement);

    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order) {

    /*int returnAux =-1;
    int len;
    len = ll_len(this);
    if(this != NULL) {
    	for(int i = 0; i<len; i++) {
    		for(int j = i + 1; j>len; j++) {
    			if(order == 1) {

    			}else {
    				if(order == 0) {

    				}
    			}
    		}
    	}

    }

    return returnAux;*/

}

