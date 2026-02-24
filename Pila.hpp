/** \file Pila.hpp
 *
 * \author Isaac Espinoza Hern&aacute;ndez,
 * David Armando Angulo Gil
 *
 * \date 23/02/2026
 * \code {.cpp}
 * int main()
{
    // Aqui probamos la Pila pero con ENTEROS
    cout << "Pila de enteros: " << endl;
    try {
        Pila<int> p;
        for(int i = 0; i < 15; ++i){
            p.Agregar(i);
        }
        p.Imprimir();
        cout << p.ObtenerCapacidad() << endl;
        p.Agregar(67);
        cout << p.ObtenerCapacidad() << endl;
        for(int i = 0; i < 15; ++i){
            p.Agregar(i);
        }
        cout << p.ObtenerCapacidad();

        return 0;




    } catch (const char *error) { // Este cacha el p.agregar().
        cerr << "Error: " << error << endl;
    } catch (Pila<int>::PilaVacia &error) { // Este cacha la clase PilaVacia
        cerr << "Error: " << error.what() << endl;
    } catch (...) {
        cerr << "Ocurri\242 un error inesperado" << endl;
    }
    cout << endl;

    return 0;
 *  }
 * \endcode
 */
#ifndef PILA_HPP
#define PILA_HPP

#include <exception>
#include <iostream> // Para sobrecargar el <<

enum { SIN_ELEMENTOS = -1 };


/** \brief Clase de pila
 *
 * \tparam T Tipo de los elementos de la pila
 *
 */
template<typename T = int>
class Pila
{
    template<typename TT>
    /** \brief
     *
     * \tparam TT Tipo de los elementos de la pila
     * \param par&aacute;metro ostream salida para la impresi&oacute;n
     * \param Pila a imprimir
     * \return Impresi&oacute;n de la Pila
     *
     */
    friend std::ostream &operator<<(std::ostream &salida, const Pila<TT> &pila);
public:

    /** \brief Constructor de la clase
     * \return Nada
     *
     * \warning Advertencias que puede lanzar: Bad Alloc
     * \throw Bad Alloc: Advertencia lanzada por falta de memoria disponible para la creaci&oacute;n de una pila
     */
    Pila(); // Constructor
    /** \brief Destructor de la clase
     * \return Nada
     *
     */
     ~Pila(); // Destructor
    /** \brief Constructor de Copias
     *
     * \param Pila a copiar
     *
     * \return Nada
     */
    Pila(const Pila<T> &pila); // Constructor de Copias
    /** \brief Operador igual para las pilas
     *
     * \tparam T Tipo de los elementos de la pila
     * \param Pila para copiar con el operador igual
     * \return Pila copiada
     *
     */
    Pila<T> &operator=(const Pila<T> &pila);

    /** \brief Funci&oacute;n para agregarle alg &uacute;n elemento en el tope de la pila
     *
     * \tparam T Tipo de los elementos de la pila
     * \param Valor a agregar a la pila
     * \return Nada
     *
     */
    void Agregar(T valor);

    /** \brief Funci&oacute;n para eliminar el elemento del tope de la pila
     *
     * \return Nada
     *
     */
    void Eliminar();

    /** \brief Funci&oacute;n que le dice al usuario el elemento en el tope de la pila
     *
     * \tparam T Tipo de los elementos de la pila
     * \return Valor encontrado en el tope
     *
     * \warning Advertencias que puede lanzar: Pila Vac&iacute;a
     * \throw Pila Vac&iacute;a: Advertencia lanzada al querer interactuar con los elementos de una pila vac&iacute;a
     */
    T ObtenerTope() const;

    /** \brief Funci&oacute;n para conocer si la pila se encuentra vac&iacute;a
     *
     * \return Si la pila se encuentra vac&iacute;a o no
     *
     * \warning Advertencias que puede lanzar: Pila Vac&iacute;a
     * \throw Pila Vac&iacute;a: Advertencia lanzada al querer interactuar con los elementos de una pila vac&iacute;a
     */
    bool EstaVacia() const;

    /** \brief Funci&oacute;n que le permite al usuario vac&iacute;ar la pila
     *
     * \return Nada
     *
     */
    void Vaciar();

    /** \brief Funci&oacute;n que devuelve el tama&ntilde;o de la pila hasta el tope
     *
     * \return Elemento en el que se encuentra el tope de la pila
     *
     */
    int ObtenerTam() const;

    /** \brief Funci&oacute;n que permite imprimir la Pila
     *
     * \return Nada
     *
     */
    void Imprimir() const;

    /** \brief Funci&oacute;n que devuelve el tama&ntilde;o entero de la pila
     *
     * \return N &uacute;mero de elementos en la pila
     *
     */
    int ObtenerCapacidad() const;

    // Una clase para CADA excepcion
    class PilaVacia : public std::exception
    {
        public:
            /** \brief Constructor de la subclase pila vac&iacute;a
             *
             * \return Nada
             *
             */
            PilaVacia() noexcept; // as&iacute; le digo que PilaVacia() NO lanza excepciones

            /** \brief Funci&oacute;n para lanzar una excepci&oacute;n para cuando la pila este vac&iacute;a
             *
             * \return Excepci&oacute;n lanzada
             *
             */
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
