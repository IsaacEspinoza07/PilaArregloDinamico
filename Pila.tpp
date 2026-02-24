// Ya se incluyo en el hpp

// A todos los métodos, para hacerlos Plantilla de Funcion

template<typename T /*= int*/>
Pila<T>::Pila(): tope(SIN_ELEMENTOS), capacidad(15)
{
    try{
        elemento = new T[capacidad];
    }catch(std::bad_alloc &){
        throw "Error en la asigaci\162n de memoria";
    }
}
/* ----------------- Destructor ----------------- */
template <typename T>
Pila<T>::~Pila()
{
    delete [] elemento;
}
/* ----------- Constructor de copias ------------ */
template <typename T>
Pila<T>::Pila(const Pila<T> &pila): elemento(nullptr)
{
    // elemento inicializado en nullptr para que cuando el operador = libere
    // a lo que aputaba no haga un cochinero y truene todo.
    capacidad = 0;
    tope = SIN_ELEMENTOS;



    // A lo que apunta this, le asigno la pila que me llego
    *this = pila;
}
/* ---------------------------------- */
template <typename T>
Pila<T> & Pila<T>::operator=(const Pila<T> &pila)
{
    if(this == &pila) return *this; // QUe no se copie a si mismo
    // TODO: Ahora si copiamos las cosas
    delete []elemento;
    capacidad = pila.capacidad;
    tope = pila.tope;

    elemento = new T [capacidad];
    for(int i = 0; i <= tope; ++i){
        elemento[i] = pila.elemento[i];
    }


    return *this;
}



/* ---------------------------------- */
template<typename T>
void Pila<T>::Agregar(T valor)
{
    if (EstaLlena()) Redimensionar();
    elemento[++tope] = valor;
}
/* ---------------------------------- */
template<typename T>
void Pila<T>::Redimensionar()
{
    capacidad = capacidad*2;
    T *nuevo_arreglo = new T [capacidad];

    for(int i = 0; i <= tope; ++i){
        nuevo_arreglo[i] = elemento[i];
    }

    delete []elemento;
    elemento = nuevo_arreglo;
}


/* ---------------------------------- */

template<typename T>
void Pila<T>::Eliminar()
{
    if (EstaVacia())
        throw PilaVacia();
    --tope;
}
/* ---------------------------------- */
template<typename T>
T Pila<T>::ObtenerTope() const
{
    if (EstaVacia())
        throw PilaVacia();
    return elemento[tope];
}
/* ---------------------------------- */
template<typename T>
bool Pila<T>::EstaVacia() const
{
    return tope == SIN_ELEMENTOS;
}

/* ---------------------------------- */
template<typename T>
bool Pila<T>::EstaLlena() const
{
    return tope == capacidad - 1;
}
/* ---------------------------------- */
template<typename T>
void Pila<T>::Vaciar()
{
    tope = SIN_ELEMENTOS;
}
/* ---------------------------------- */
template<typename T>
int Pila<T>::ObtenerTam() const
{
    return tope + 1;
}
/* ---------------------------------- */
template<typename T>
int Pila<T>::ObtenerCapacidad() const
{
    return capacidad;
}

/* ---------------------------------- */

template<typename T>
void Pila<T>::Imprimir() const
{
    std::cout << "Tope -> ";
    if (!EstaVacia()) {
        std::cout << "<";
    }
    for (int i = tope; i >= 0; --i) {
        std::cout << elemento[i] << ", ";
    }
    if (!EstaVacia()) {
        std::cout << "\b\b>\n";
    }
}
/* ---------------------------------- */

/* ------- CLASES PARA LAS EXCEPCIONES -------- */
// === PilaVacia === //
template<typename T>
Pila<T>::PilaVacia::PilaVacia() throw() {}

template<typename T>
const char *Pila<T>::PilaVacia::what() const throw()
{
    return "La pila se encuentra vac\241a\n";
}

// ************* Amiwiris de la clase ************** //
template<typename TT>
std::ostream &operator<<(std::ostream &salida, const Pila<TT> &pila)
{
    if (!pila.EstaVacia()) {
        salida << "<";
    }
    for (int i = pila.tope; i >= 0; --i) {
        salida << pila.elemento[i] << ", ";
    }
    if (!pila.EstaVacia()) {
        salida << "\b\b>";
    }
    return salida;

}

