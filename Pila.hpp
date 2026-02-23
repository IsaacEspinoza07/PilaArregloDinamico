#ifndef PILA_HPP
#define PILA_HPP

#include <exception>
#include <iostream> // Para sobrecargar el <<

enum { SIN_ELEMENTOS = -1 };


/** \brief
 *
 * \tparam T Tipo de los elementos de la pila
 * \param tam tamaño de la pila (capacidad de contenci&oactue;n)
 *
 */

template<typename T = int>
class Pila
{
    template<typename TT>
    friend std::ostream &operator<<(std::ostream &salida, const Pila<TT> &pila);
public:
    Pila(); // Constructor
    ~Pila(); // Destructor
    Pila(const Pila<T> &pila); // Constructor de Copias
    Pila<T> &operator=(const Pila<T> &pila);


    void Agregar(T valor);
    void Eliminar();
    T ObtenerTope() const;
    bool EstaVacia() const;
    void Vaciar();
    int ObtenerTam() const;
    void Imprimir() const;
    int ObtenerCapacidad() const;

    // Una clase para CADA excepcion
    class PilaVacia : public std::exception
    {
        public:
            PilaVacia() noexcept; // así le digo que PilaVacia() NO lanza excepciones
            virtual const char *what() const noexcept;
        private:
            const char *mensaje;
    };

private:
    bool EstaLlena() const;
    void Redimensionar();
    int tope, capacidad;
    T *elemento;
};

#include "Pila.tpp"


#endif // PILA_HPP
